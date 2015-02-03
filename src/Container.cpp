/*************************************************************************
                           Container  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par TOUZARD Loïc, GOUZI Gaëtan et GONZALEZ TOLEDO Gabriela
*************************************************************************/

//---------- Réalisation de la classe <Container> (fichier Container.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <cstdlib>
//------------------------------------------------------ Include personnel
#include "Tools.h"
#include "Container.h"
#include "Point.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Line.h"
#include "Polyline.h"
#include "Selection.h"
#include "toString.h"
#include "Command.h"
#include "MoveCommand.h"
#include "CreateElementCommand.h"
#include "DeleteElementCommand.h"
#include "DeleteCommand.h"
#include "LoadCommand.h"
//------------------------------------------------------------- Constantes
const size_t UNDO_REDO_MAX_LEVEL = 20; //Taille maxi de la pile des UNDO définie par le CdC
//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Container::Container ( const Container & unContainer )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Container>" << endl;
#endif
} //----- Fin de Container (constructeur de copie)


Container::Container ( )
// Algorithme :
//
{

#ifdef MAP
    cout << "Appel au constructeur de <Container>" << endl;
#endif
} //----- Fin de Container


Container::~Container ( )
// Algorithme :
//
{
    MapGraphics::iterator it;
    for (it = listeGraphics.begin(); it != listeGraphics.end(); ++it){
        delete it->second;
    }
    listeGraphics.clear();

    list<Command*>::iterator it2;
    for (it2 = redoCommands.begin(); it2 != redoCommands.end(); ++it2){
        delete *it2;
    }
    redoCommands.clear();

    for (it2 = undoCommands.begin(); it2 != undoCommands.end(); ++it2){
        delete *it2;
    }
    undoCommands.clear();
#ifdef MAP
    cout << "Appel au destructeur de <Container>" << endl;
#endif
} //----- Fin de ~Container


void Container::Save(const string nomFichier) const
// Algorithme : Permet de sauvegarder toutes les commandes propres à chaque Graphics
// Le nom du fichier à créer est passé en paramètre
// On parcourt tous les Graphics situés dans le container et pour chacun d'entre eux on stocke leur commande dans le fichier
{
	ofstream fichier;
    fichier.open(nomFichier.c_str(),ios::trunc);
	if(fichier){
		Graphics_const_iterator it;
		for(it=listeGraphics.begin(); it!=listeGraphics.end();++it){
			fichier<<it->second->description(); //On récupère toutes les commandes
		}
		fichier.close();
		cout<<"OK"<<endl;
	}
	else{
		cout<<"#Can't create the file "<<nomFichier<<endl;
	}
} //----- Fin de Save

void Container::Clear()
// Algorithme : Vide le container de tous les Graphics qu'il contient
// On parcours le container, on stocke toutes les commandes dans une liste pour anticiper un éventiuel UNDO
// Puis on vide la liste de Graphics
{
	if(listeGraphics.size()==0){
		cout<<"OK"<<endl;
		cout<<"#The list was already empty"<<endl;
	}
	else{

        vector<Command*> listeCMD;
        Graphics_iterator it;
        for(it = listeGraphics.begin(); it!=listeGraphics.end(); ++it)
        {
            listeCMD.push_back(new DeleteElementCommand(&listeGraphics, it->second));
        }
        //on considère le CLEAR comme un DELETE de tous les elements (même comportement)
        insertCommand(new DeleteCommand(listeCMD));

		listeGraphics.clear();
		cout<<"OK"<<endl;
	}
}

void Container::List() const
// Algorithme : Liste toutes les figures (pas les sélections) situées dans le container
// On parcours la liste de Graphics et on ne récupère que les figures pour ensuite afficher leur commande
{
	Graphics_const_iterator it;
	if(listeGraphics.size()!=0){
        int compteurFigure=0;
		for(it=listeGraphics.begin(); it!=listeGraphics.end();++it){
            if(dynamic_cast<Figure *>(it->second)!=NULL){
                compteurFigure++;
                cout<<it->second->description();
            }
		}
		if(compteurFigure==0){
            cout<<"#The list is empty"<<endl;
		}
	}
	else{
		cout<<"#The list is empty"<<endl;
	}
}

void Container::moveElement(const string name, const long dX, const long dY)
// Algorithme : Déplace un Graphics dans le container
// On cherche le nom de la figure passée en param-tre dans la liste de Graphics
// Si elle existe on ajoute dX à sa coordonnée x et dY à sa coordonnée en y
{
	MapGraphics::iterator it;
	it=listeGraphics.find(name);
	if(it!=listeGraphics.end()){
		it->second->move(dX, dY);
		Point pt;
		pt.x = dX;
		pt.y = dY;

		//on l'ajoute a la pile des undo et on clear les redo
		insertCommand(new MoveCommand(&listeGraphics, it->second , pt));
		cout<<"OK"<<endl;
	}
	else{
		cout<<"ERR"<<endl;
		cout<<"#"<<name<<" not found"<<endl;
   }
}

void Container::Load(const string nomFichier)
// Algorithme : Permet de charger un fichier
// On parcours tout le fichier et on récupère toutes les commandes
// On exécute ensuite chaque commande (sans l'affichage)
{
    string entree;
    ifstream loadFile (nomFichier.c_str());
    if (loadFile.is_open())
    {

        MapGraphics tmpMap;
        vector<Command*> listeCMD;

        bool correctFile = true;
        list<string> args;
        while ( getline (loadFile,entree) && correctFile)
        {
            args.clear();
            Tools::Split(entree, args);
            if(args.size()!=0)
            {
                string commandType = args.front();
                args.pop_front();

                if (commandType=="C") {

                    if(args.size()==4)
                    {
                        //Code pour ajouter un cercle
                        string name;
                        name = args.front();
                        args.pop_front();

                        Point center;
                        center.x = atol(args.front().c_str());
                        args.pop_front();
                        center.y = atol(args.front().c_str());
                        args.pop_front();

                        long radiusl = atol(args.front().c_str());

                        if(!NomLibre(name, &listeGraphics)){
                            correctFile = false;
                            cout<<"ERR"<<endl;
                            cout<<"#name already taken"<<endl;
                        }
                        else if(radiusl < 0){
                            correctFile = false;
                            cout<<"ERR"<<endl;
                            cout<<"#radius must be a postive interger"<<endl;
                        }
                        else{

                            Circle *c=new Circle(radiusl, center, name, entree);
                            listeGraphics.insert(make_pair(name, c));
                            listeCMD.push_back(new CreateElementCommand(&listeGraphics, c));

                            //Fin du code pour ajouter un cercle
                        }
                    }
                    else{
                        correctFile = false;
                        cout<<"ERR"<<endl;
                        cout<<"#invalid parameters : 4 parameters expected"<<endl;
                    }

                }

                else if (commandType=="R") {

                    if(args.size()==5){

                        string name;
                        name = args.front();
                        args.pop_front();

                        if(!NomLibre(name, &listeGraphics)){
                            correctFile = false;
                            cout<<"ERR"<<endl;
                            cout<<"#name already taken"<<endl;
                            break;
                        }

                        Point origin;
                        Point extremity;
                        origin.x=atol(args.front().c_str());
                        args.pop_front();
                        origin.y=atol(args.front().c_str());
                        args.pop_front();
                        extremity.x=atol(args.front().c_str());
                        args.pop_front();
                        extremity.y=atol(args.front().c_str());
                        Rectangle *r=new Rectangle(extremity, origin, name, entree);

                        listeGraphics.insert(make_pair(name, r));
                        listeCMD.push_back(new CreateElementCommand(&listeGraphics, r));

                    }
                    else{
                        correctFile = false;
                        cout<<"ERR"<<endl;
                        cout<<"#invalid parameters"<<endl;
                    }
                }

                else if (commandType=="PL") {

                    if( args.size()%2==1 && args.size()>=3){ //Un point minimum
                        //Code pour ajouter un polyligne
                        int nbPoints=(args.size()-1)/2;
                        string name;
                        name=args.front();
                        args.pop_front();

                        if(!NomLibre(name, &listeGraphics)){
                            correctFile = false;
                            cout<<"ERR"<<endl;
                            cout<<"#name already taken"<<endl;
                            break;
                        }

                        Point origin;
                        origin.x=atol(args.front().c_str());
                        args.pop_front();
                        origin.y=atol(args.front().c_str());
                        args.pop_front();

                        vector<Point> newPointList;
                        for(int i=2; i<=nbPoints; i++){
                            Point p;
                            p.x=atol(args.front().c_str());
                            args.pop_front();
                            p.y=atol(args.front().c_str());
                            args.pop_front();
                            newPointList.push_back(p);
                        }


                        Polyline *pl =new Polyline (newPointList, origin, name, entree);

                        listeGraphics.insert(make_pair(name, pl));
                        listeCMD.push_back(new CreateElementCommand(&listeGraphics, pl));

                    }
                    else{
                        correctFile = false;
                        cout<<"ERR"<<endl;
                        cout<<"#invalid parameters"<<endl;
                    }
                }

                else if (commandType=="L") {

                     if(args.size()==5){
                        string name;

                        name=args.front();
                        args.pop_front();

                        if(!NomLibre(name, &listeGraphics)){
                            correctFile = false;
                            cout<<"ERR"<<endl;
                            cout<<"#name already taken"<<endl;
                            break;
                        }

                        Point origin;
                        Point extremity;
                        origin.x=atol(args.front().c_str());
                        args.pop_front();
                        origin.y=atol(args.front().c_str());
                        args.pop_front();
                        extremity.x=atol(args.front().c_str());
                        args.pop_front();
                        extremity.y=atol(args.front().c_str());

                        Line *l=new Line(extremity, origin, name, entree);

                        listeGraphics.insert(make_pair(name, l));
                        listeCMD.push_back(new CreateElementCommand(&listeGraphics, l));

                    }
                    else{
                        correctFile = false;
                        cout<<"ERR"<<endl;
                        cout<<"#invalid parameters"<<endl;
                    }
                }
                
                else if (commandType[0]!='#') {
                    correctFile = false;
                    cout<<"ERR"<<endl;
                    cout<<"#Unknown command"<<endl;
                }
            }
            else
            {
                correctFile = false;
                cout<<"ERR"<<endl;
                cout<<"#Empty line"<<endl;
            }
        }

        loadFile.close();

        if(correctFile)
        {
            //la création est confirmée car tous les éléments sont corrects
            insertCommand(new LoadCommand (listeCMD));
            cout << "#" << listeCMD.size() << "elements have been loaded successfully." << endl;
            cout << "OK" << endl;
        }
        else
        {
            //il y a eu une erreur dans le fichier on libère ce qui a été créé
            cout<<"#Error line : " << listeCMD.size()+1 << endl;
            cout<<"#The load file couldn't be loaded. None of the elements have been created."<<endl;

            vector<Command*>::iterator it2;
            for (it2 = listeCMD.begin(); it2 != listeCMD.end(); ++it2){
                (*it2)->UnExecute();//suppression des elements de la map
                delete *it2;//suppression de la commande et de la forme de la mémoire.
            }
            listeCMD.clear();
        }
    }
    else
    {
        cout << "ERR" << endl;
        cout << "#Unable to open file";
    }
}

void Container::Delete(const vector<string> listeNoms)
// Algorithme : Permet de supprimer un ou plusieurs Graphics
// On parcours la liste de Graphics et si tous les paramètres sont valides, on supprime les Graphics qui portent ce nom
// On stocke auparavant les commandes pour anticiper un éventuel UNDO
{
	for(unsigned int i=0; i<listeNoms.size(); ++i)
	{
		if(NomLibre( listeNoms[i] , &listeGraphics) )
		{
			cout<<"ERR"<<endl;
			cout<<"# can't find "+listeNoms[i]+ ". None of the elements have been removed"<<endl;
			return;
		}
	}
	vector<Command*> listeCMD;
	Graphics_iterator it;
	for(unsigned int i=0; i<listeNoms.size(); ++i)
	{
        it=listeGraphics.find(listeNoms[i]); //On met en place l'iterateur sur l'élément pour ne parcourir la map qu'une seule fois
	    if(it!=listeGraphics.end()) //On vérifie que l'élément est bien présent
	    //et n'a pas été supprimé par un delete précédent de cette même commande
	    // Ex : DELETE nameSelection nameObjetOfSelection
        {
            Figure *toDelete=NULL;
            toDelete=dynamic_cast<Figure *>(it->second);

            if(toDelete!=NULL){ //Si c'est une figure
                listeCMD.push_back(new DeleteElementCommand(&listeGraphics, it->second));
                toDelete->SetInDraw(GRAPHICS_STATE_NOT_IN_DRAW);
                listeGraphics.erase(it);
            }
            else{ //Si c'est une sélection
                vector<Command*> listeCMDSelection;
                vector<Figure*> figureToDelete;
                figureToDelete = (dynamic_cast<Selection *>(it->second))->GetInDrawElements();
                vector<Figure*>::iterator it2;
                for(it2=figureToDelete.begin(); it2!=figureToDelete.end(); ++it2){
                    listeCMDSelection.push_back(new DeleteElementCommand(&listeGraphics, *it2));
                    (*it2)->SetInDraw(GRAPHICS_STATE_NOT_IN_DRAW);
                    listeGraphics.erase((*it2)->GetName());
                }
                listeGraphics.erase(it); //Erase de la selection
                it->second->SetInDraw(GRAPHICS_STATE_NOT_IN_DRAW);
                delete it->second;
                listeCMD.push_back(new DeleteCommand(listeCMDSelection));
            }
        }
	}
	insertCommand(new DeleteCommand(listeCMD));
	// Penser au cas de la selection suivie des ses éléments (contrat ?)
	cout<<"OK"<<endl;
}

void Container::AddCircle(const string name, const long radius, const long centerX, const long centerY, const string commande)
// Algorithme : Création d'un objet cercle (de type Figure) à partir des valeurs passées en paramètres
// On vérifie que le nom n'est pas déjà pris par une autre figure ou sélection
// On peut ensuite créer l'objet en ayant pris soin de vérifier que le rayon ne soit pas négatif
{
	if(!NomLibre(name, &listeGraphics)){
		cout<<"ERR"<<endl;
		cout<<"#name already taken"<<endl;
		return;
	}
	if(radius<0){
		cout<<"ERR"<<endl;
		cout<<"#radius must be a postive interger"<<endl;
	}
	else{
		//Code pour ajouter un cercle
		Point center;
		center.x=centerX;
		center.y=centerY;
		Circle* c=new Circle(radius, center, name, commande);
		listeGraphics.insert(make_pair(name, c));
		insertCommand(new CreateElementCommand(&listeGraphics, c ));
		//Fin du code pour ajouter un cerlce
		cout<<"OK"<<endl;
		cout<<"#New object :"<<name<<endl;
	}
}

void Container::AddRectangle(const string name, const long coin1X, const long coin1Y, const long coin2X, const long coin2Y, const string commande)
// Algorithme : Création d'un objet rectangle (de type Figure) à partir des valeurs passées en paramètres
// On vérifie que le nom n'est pas déjà pris par une autre figure ou sélection
// On peut ensuite créer l'objet en ayant calculé les coordonnées du coin supérieur gauche et du coin inférieur droit  du rectangle
{

    if(!NomLibre(name, &listeGraphics)){
		cout<<"ERR"<<endl;
		cout<<"#name already taken"<<endl;
		return;
	}
	Point origin;
	Point extremity;
	//origin doit prendre le x minimum et y maximum
	//extremity doir prendre le y minimum et x maximum
    origin.x=coin1X;
    extremity.x=coin2X;
    origin.y=coin1Y;
    extremity.y=coin2Y;

	Rectangle *r=new Rectangle(extremity, origin, name, commande);
	listeGraphics.insert(make_pair(name, r));
	insertCommand(new CreateElementCommand(&listeGraphics, r ));
	cout<<"OK"<<endl;
	cout<<"#New object :"<<name<<endl;
}

void Container::AddLine(const string name, const long coin1X, const long coin1Y, const long coin2X, const long coin2Y, const string commande)
// Algorithme : Création d'un objet line (de type Figure) à partir des valeurs passées en paramètres
// On vérifie que le nom n'est pas déjà pris par une autre figure ou sélection
// On peut ensuite créer l'objet en ayant calculé les coordonnées du coin supérieur gauche et du coin inférieur droit  du rectangle dans lequel est contenu cette ligne
{
    if(!NomLibre(name, &listeGraphics)){
		cout<<"ERR"<<endl;
		cout<<"#name already taken"<<endl;
		return;
	}

	Point origin;
	Point extremity;

	origin.x=coin1X;
	origin.y=coin1Y;
	extremity.x=coin2X;
	extremity.y=coin2Y;

	Line *l=new Line(extremity, origin, name, commande);
	listeGraphics.insert(make_pair(name, l));
    insertCommand(new CreateElementCommand(&listeGraphics, l ));
	cout<<"OK"<<endl;
	cout<<"#New object : "<<name<<endl;
}

void Container::AddPolyline(const string name, const vector<Point> newPointList, const Point origin, const string commande)
// Algorithme : Création d'un objet polyline (de type Figure) à partir des valeurs passées en paramètres
// On vérifie que le nom n'est pas déjà pris par une autre figure ou sélection
// On peut ensuite créer l'objet en ayant calculé les coordonnées du coin supérieur gauche et du coin inférieur droit  du rectangle dans lequel sont contenus
// l'ensemble des points de l'objet polyline
{
    if(!NomLibre(name, &listeGraphics)){
		cout<<"ERR"<<endl;
		cout<<"#name already taken"<<endl;
		return;
	}
	/*string cmd="PL "+name+" "+toString(origin.x)+" "+toString(origin.y);
	vector<Point>::iterator it;
	for(it=newPointList.begin(); it!=newPointList.end(); ++it){
		cmd += " "+toString(it->x)+" "+toString(it->y);
	}*/
	Polyline *pl =new Polyline (newPointList, origin, name, commande);
	listeGraphics.insert(make_pair(name, pl));
    insertCommand(new CreateElementCommand(&listeGraphics, pl ));
	cout<<"OK"<<endl;
	cout<<"#New object : "<<name<<endl;
}

void Container::AddSelection(const string name, const long coin1X, const long coin1Y, const long coin2X, const long coin2Y, const string commande)
// Algorithme : Création d'un objet selection (de type Selection) à partir des valeurs passées en paramètres
// On vérifie que le nom n'est pas déjà pris par une autre figure ou sélection
// On calcule les coordonnées du coin supérieur gauche et du coin inférieur droit  du rectangle définissant la sélection
// On ajoute chaque figure se trouvant dans la sélection à la liste de figures que possède la sélection (permet de savoir quelles figures elle contient)

{
    if(!NomLibre(name, &listeGraphics)){
		cout<<"ERR"<<endl;
		cout<<"#name already taken"<<endl;
		return;
	}
	Point origin;
	Point extremity;
	//origin doit prendre le x minimum et y maximum
	//extremity doir prendre le y minimum et x maximum
    origin.x=(coin1X<coin2X)?coin1X:coin2X;
	origin.y=(coin1Y<coin2Y)?coin2Y:coin1Y;

	extremity.x=(coin1X<coin2X)?coin2X:coin1X;
	extremity.y=(coin1Y<coin2Y)?coin1Y:coin2Y;

    vector<Figure*> figuresInside;
    Graphics_iterator it;
    Figure *temp=NULL;
    for(it=listeGraphics.begin(); it!=listeGraphics.end(); ++it){
        temp=dynamic_cast<Figure *>(it->second);
        if(temp!=NULL){ //Si c'est bien une figure
            if( temp->IsInside(origin, extremity) ){
                //temp->whoOwnsMe.push_back();
                figuresInside.push_back(temp);
                //Dynamic_cast permet de ne récupérer que la partie Figure de it (qui est un iterator de Graphics)
            }
        }
    }
    Selection *s =new Selection (figuresInside, origin, extremity, name, commande);
	listeGraphics.insert(make_pair(name, s));
	cout<<"OK"<<endl;
	cout<<"#New object : "<<name<<endl;
}

void Container::Undo()
// Algorithme : Permet d'annuler la dernière opération
// Il suffit de récupérer la dernière commande que l'on a ajouté à la pile des UNDO et de l'annuler
{
    if(!undoCommands.empty())
    {
        Command* tmpCommand = undoCommands.front(); //on prend la commande du haut de la pile
        undoCommands.pop_front();
        tmpCommand->UnExecute();
        redoCommands.push_front(tmpCommand);//on met la command au sommet de la pile de undo
        cout<<"OK"<<endl;
    }
    else
    {
        cout << "#nothing to undo !" << endl;
    }
}

void Container::Redo()
// Algorithme : Permet de réexécuter une action que l'on vient d'annuler (contraire du UNDO)
// Il suffit de récupérer la derniere commande que l'on a ajouté à la pile des REDO et de l'exécuter
{
    if(!redoCommands.empty())
    {
        Command* tmpCommand = redoCommands.front(); //on prend la commande du haut de la pile
        redoCommands.pop_front();
        tmpCommand->Execute();
        undoCommands.push_front(tmpCommand);//on met la command au sommet de la pile de undo
        cout<<"OK"<<endl;
    }
    else
    {
        cout << "#nothing to redo !" << endl;
    }
}

//------------------------------------------------------------------ PRIVE
bool Container::NomLibre(const string name, const MapGraphics* const mapToAnalyse) const
// Algorithme : Renvoie true si le nom est disponible (aucun Graphics dans le container ne le possède)
{
	Graphics_const_iterator it;
	it=mapToAnalyse->find(name);
	if(it==mapToAnalyse->end()){
		return true;
	}
	return false;
}

void Container::insertCommand(Command* const cmd)
// Algorithme : Insère une commande dans la pile des UNDO et vide la pile des REDO
{
    if(undoCommands.size() >= UNDO_REDO_MAX_LEVEL)
    //s'il y a deja x evenement dans la liste
    // on doit supprimer le dernier pour en inserer un nouveau
    {
        Command* tmpCmd = undoCommands.back();
        undoCommands.pop_back();
        delete tmpCmd;
    }
    undoCommands.push_front(cmd);
    //On clean la pile des REDO car on ne peut pas faire un REDO après l'exécution d'une commande à la main (pas par un UNDO)
    list<Command*>::iterator it;
    for (it = redoCommands.begin(); it != redoCommands.end(); ++it){
        delete *it;
    }
    redoCommands.clear();
}
//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
