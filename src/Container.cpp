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
#include "Container.h"
#include "Tools.h"
#include "toString.h"

#include "Point.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Line.h"
#include "Polyline.h"
#include "Selection.h"

#include "Command.h"
#include "MoveCommand.h"
#include "CreateElementCommand.h"
#include "DeleteElementCommand.h"
#include "DeleteCommand.h"
#include "LoadCommand.h"
//------------------------------------------------------------- Constantes
const size_t UNDO_REDO_MAX_LEVEL = 20; //Taille maximum de la pile des UNDO définie par le CdC
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
    //La libération de la mémoire est obligée de se faire par un parcourt de nos conteneur car ils contiennent des pointeurs.
    
    //libération des éléments de la MapGraphics
    MapGraphics::iterator it;
    for (it = listeGraphics.begin(); it != listeGraphics.end(); ++it)
    {
        delete it->second;
    }
    listeGraphics.clear();

    //libération des commandes de la pile redo
    list<Command*>::iterator it2;
    for (it2 = redoCommands.begin(); it2 != redoCommands.end(); ++it2)
    {
        delete *it2;
    }
    redoCommands.clear();

    //libération des commandes de la pile undo
    for (it2 = undoCommands.begin(); it2 != undoCommands.end(); ++it2)
    {
        delete *it2;
    }
    undoCommands.clear();
#ifdef MAP
    cout << "Appel au destructeur de <Container>" << endl;
#endif
} //----- Fin de ~Container


void Container::Save(const string nomFichier) const
// Algorithme : Permet de sauvegarder toutes les commandes propres à chaque Graphics dans un fichier
// Le nom du fichier à créer est passé en paramètre
// On parcourt tous les Graphics situés dans le container et pour chacun d'entre eux on stocke leur commande dans le fichier
{
	ofstream fichier;
    fichier.open(nomFichier.c_str(),ios::trunc);
	if(fichier)
    {
		Graphics_const_iterator it;
		for(it=listeGraphics.begin(); it!=listeGraphics.end();++it)
        {
            //les séléctions ont une description vide et ne s'affichent donc pas.
			fichier<<it->second->description(); //On récupère toutes les commandes
		}
		fichier.close();
		cout<<"OK"<<endl;
	}
	else
    {
		cout<<"#Can't create the file "<<nomFichier<<endl;
	}
} //----- Fin de Save

void Container::Clear()
// Algorithme : Vide le container de tous les Graphics qu'il contient
// On parcourt le container, on stocke toutes les commandes dans un DeleteCommand qui contient un vector anticiper un éventiuel UNDO
// Puis on vide la liste de Graphics
{
	if(listeGraphics.size()==0)
    {   //Si c'est deja vide
		cout<<"OK"<<endl;
		cout<<"#The list was already empty"<<endl;
	}
	else
    {  //Si il y a des elements

        vector<Command*> listeCMD;  //liste des commandes de suppressions
        Graphics_iterator it;
        for(it = listeGraphics.begin(); it!=listeGraphics.end(); ++it)
        {
            //  on stocke les commandes de suppressions de chaque elements
            listeCMD.push_back(new DeleteElementCommand(&listeGraphics, &hashedName, it->second));
        }
        //on considère le CLEAR comme un DELETE de tous les elements (même comportement)
        insertCommand(new DeleteCommand(listeCMD));

        //on vide la MapGRaphics
		listeGraphics.clear();
        hashedName.clear();
		cout<<"OK"<<endl;
	}
}

void Container::List() const
// Algorithme : Liste toutes les figures (pas les sélections) situées dans le container
// On parcours la liste de Graphics et on ne récupère que les figures pour ensuite afficher leur commande
{
	Graphics_const_iterator it;
    int compteurFigure=0;   //on compte les elements non-selection (donc figure)
	for(it=listeGraphics.begin(); it!=listeGraphics.end();++it)
    {
        if(dynamic_cast<Figure *>(it->second)!=NULL)
        {//vérification si c'est le Graphics est une Selection
            compteurFigure++;
            //on affihe la description de chaque element
            cout<<it->second->description();
        }
	}
	if(compteurFigure==0)
    {
        cout<<"#The list is empty"<<endl;
	}
}

void Container::moveElement(const string name, const long dX, const long dY)
// Algorithme : Déplace un Graphics dans le container
// On cherche le nom de la figure passée en paramètre dans la liste de Graphics
// Si elle existe on ajoute dX à sa coordonnée x et dY à sa coordonnée en y
{
	MapGraphics::iterator it;
	it=listeGraphics.find(name);   // on cherche notre element
	if(it!=listeGraphics.end())
    {   //si il a été trouvé
		it->second->move(dX, dY);
		Point pt;
		pt.x = dX;
		pt.y = dY;

		//on l'ajoute a la pile des undo
		insertCommand(new MoveCommand(&listeGraphics, &hashedName, it->second , pt));
		cout<<"OK"<<endl;
	}
	else
    {
		cout<<"ERR"<<endl;
		cout<<"#"<<name<<" not found"<<endl;
   }
}

void Container::Load(const string nomFichier)
// Algorithme : Permet de charger un fichier
// On parcourt et on insère chaque ligne du fichier en créant une CreateElementCommand pour chacun d'entre eux.
// Une erreur dans le fichier (de syntaxe, nom deja existant, ...) est detectée et annule tous les ajouts déjà effectués.
{
    string userLine;
    ifstream loadFile (nomFichier.c_str()); //on ouvre le fichier
    if (loadFile.is_open())
    {
        //on créée la liste des Command de type création du LOAD
        vector<Command*> listeCMD;

        bool correctFile = true;
        //définit si le fichier est bien formé.

        list<string> args;  //Contiendra les mots clés d'une ligne
        while ( getline (loadFile,userLine) && correctFile)
        {
            args.clear();
            Tools::Split(userLine, args);// on sépare les mots clés

            if(args.size()!=0)
            {
                string commandType = args.front();
                args.pop_front();

                if (commandType=="C")
                {

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
                        
                        // vérification dans la table de hash l'existence du nom
                        if(hashedName.find(name)!=hashedName.end())
                        {   
                            correctFile = false;
                            cout<<"ERR"<<endl;
                            cout<<"#name already taken"<<endl;
                        }
                        else if(radiusl < 0)
                        {
                            correctFile = false;
                            cout<<"ERR"<<endl;
                            cout<<"#radius must be a postive interger"<<endl;
                        }
                        else
                        {
                            //Création du cercle
                            Circle *c=new Circle(radiusl, center, name, userLine);
                            //ajout a la map de Graphics
                            listeGraphics.insert(make_pair(name, c));
                            //ajout du nom dans la table de hash
                            hashedName.insert(name);
                            //ajout de la commande de Création de cet element
                            listeCMD.push_back(new CreateElementCommand(&listeGraphics, &hashedName, c));

                            //Fin du code pour ajouter un cercle
                        }
                    }
                    else
                    {
                        correctFile = false;
                        cout<<"ERR"<<endl;
                        cout<<"#invalid parameters : 4 parameters expected"<<endl;
                    }

                }

                else if (commandType=="R")
                {

                    if(args.size()==5)
                    {

                        string name;
                        name = args.front();
                        args.pop_front();

                        if(hashedName.find(name)!=hashedName.end())//vérification de l'existence du nom dans la table de hash
                        {
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

                        Rectangle *r=new Rectangle(extremity, origin, name, userLine);
                        //ajout du Rectangle dans la map de Graphics
                        listeGraphics.insert(make_pair(name, r));
                        //Ajout du nom dans la table de hash
                        hashedName.insert(name);
                        //ajout de la commande de création de cet element à la liste
                        listeCMD.push_back(new CreateElementCommand(&listeGraphics, &hashedName, r));

                    }
                    else
                    {
                        correctFile = false;
                        cout<<"ERR"<<endl;
                        cout<<"#invalid parameters"<<endl;
                    }
                }

                else if (commandType=="PL")
                {

                    if( args.size()%2==1 && args.size()>=3) //Un nombre pair de coordonnées + le nom => nombre impair obligatoire
                    {
                        //Code pour ajouter une polyligne
                        int nbPoints=(args.size()-1)/2;
                        string name;
                        name=args.front();
                        args.pop_front();

                        if(hashedName.find(name)!=hashedName.end()) // vérification de l'existence du nom dans la table de hash
                        {
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
                        for(int i=2; i<=nbPoints; i++)
                        {
                            Point p;
                            p.x=atol(args.front().c_str());
                            args.pop_front();
                            p.y=atol(args.front().c_str());
                            args.pop_front();
                            newPointList.push_back(p);
                        }


                        Polyline *pl =new Polyline (newPointList, origin, name, userLine);
                        //  ajout de la Polyligne a la MapGraphics
                        listeGraphics.insert(make_pair(name, pl));
                        //  ajout du nom dans la hashmap
                        hashedName.insert(name);
                        //ajout de la commande de création de cet element à la liste
                        listeCMD.push_back(new CreateElementCommand(&listeGraphics, &hashedName, pl));

                    }
                    else
                    {
                        correctFile = false;
                        cout<<"ERR"<<endl;
                        cout<<"#invalid parameters"<<endl;
                    }
                }

                else if (commandType=="L")
                {

                     if(args.size()==5)
                     {
                        string name;

                        name=args.front();
                        args.pop_front();

                        if(hashedName.find(name)!=hashedName.end())
                        {
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

                        Line *l=new Line(extremity, origin, name, userLine);

                        // Ajout de la Ligne dans la MapGraphics
                        listeGraphics.insert(make_pair(name, l));
                        // Ajout du nomd dans la table de hash
                        hashedName.insert(name);
                        //ajout de la commande de création de cet element à la liste
                        listeCMD.push_back(new CreateElementCommand(&listeGraphics, &hashedName, l));

                    }
                    else
                    {
                        correctFile = false;
                        cout<<"ERR"<<endl;
                        cout<<"#invalid parameters"<<endl;
                    }
                }

                else if (commandType[0]!='#')   //Si ça n'est pas non plus un commentaire
                {
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
// On parcours la liste de Graphics et si tous les paramètres sont valides, on supprime les Graphics qui portent ces noms
{
    // on vérifie l'existence de tous les noms demandés
	for(unsigned int i=0; i<listeNoms.size(); ++i)
	{
		if(hashedName.find(listeNoms[i])==hashedName.end())
		{
            //si un nom n'existe pas dans la MapGraphics
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
	    
        //On vérifie que l'élément est bien présent et n'a pas été supprimé par un delete précédent de cette même commande
        // Ex : DELETE nameSelection nameObjetOfSelection
        if(it!=listeGraphics.end()) 
        {
            Figure *toDelete=NULL;
            toDelete=dynamic_cast<Figure *>(it->second);    //on tente de cast notre Graphics en Figure

            if(toDelete!=NULL)  //Si c'est une figure
            { 
                // ajout de la commande de suppression de cet element à la liste
                listeCMD.push_back(new DeleteElementCommand(&listeGraphics, &hashedName, it->second));
                //on change l'etat de notre Element pour indiquer qu'il n'est plus actif
                toDelete->SetInDraw(GRAPHICS_STATE_NOT_IN_DRAW);
                //on l'enleve de la MapGraphics
                listeGraphics.erase(it);
                //on enleve son nom de la table de hash
                hashedName.erase( toDelete->GetName() );
            }
            else    //Si c'est une sélection alors on supprime les elements de cette selection
            { 
                vector<Command*> listeCMDSelection; // commandes de suppression des elements de la selection
                vector<Figure*> figureToDelete; 

                //on sait que c'est une selection et que le cast se passera correctement
                figureToDelete = (dynamic_cast<Selection *>(it->second))->GetInDrawElements(); // on récupère les elements contenus dans la selection  
                vector<Figure*>::iterator it2;
                for(it2=figureToDelete.begin(); it2!=figureToDelete.end(); ++it2)
                {   
                    // on effectue les même operations que pour la suppression d'une figure simple
                    listeCMDSelection.push_back(new DeleteElementCommand(&listeGraphics, &hashedName, *it2));
                    (*it2)->SetInDraw(GRAPHICS_STATE_NOT_IN_DRAW);
                    listeGraphics.erase((*it2)->GetName());
                    hashedName.erase( (*it2)->GetName() );
                }

                listeGraphics.erase(it); //Erase de la selection
                hashedName.erase( it->first );  //suppression du nom de la selection dans la hash
                it->second->SetInDraw(GRAPHICS_STATE_NOT_IN_DRAW);
                //On libère directement l'objet de la memoire contrairement aux figures. Car on ne peut recreer les selections.
                delete it->second;
                //on ajoute toutes les commandes de suppression relative a la selection dans la liste de commande du DELETE
                listeCMD.push_back(new DeleteCommand(listeCMDSelection));
            }
        }
	}
	insertCommand(new DeleteCommand(listeCMD));
	cout<<"OK"<<endl;
}

void Container::AddCircle(const string name, const long radius, const long centerX, const long centerY, const string commande)
// Algorithme : Création d'un objet cercle (de type Figure) à partir des valeurs passées en paramètres
// On vérifie que le nom n'est pas déjà pris par une autre figure ou sélection
// On peut ensuite créer l'objet en ayant pris soin de vérifier que le rayon ne soit pas négatif
{
	if(hashedName.find(name)!=hashedName.end())//verification de la disponibilite du nom
    {
		cout<<"ERR"<<endl;
		cout<<"#name already taken"<<endl;
		return;
	}
	if(radius<0)
    {
		cout<<"ERR"<<endl;
		cout<<"#radius must be a postive interger"<<endl;
	}
	else
    {
		Point center;
		center.x=centerX;
		center.y=centerY;

		//Création du cercle
        Circle* c=new Circle(radius, center, name, commande);
        //ajout a la map de Graphics
        listeGraphics.insert(make_pair(name, c));
        //ajout du nom dans la table de hash
        hashedName.insert(name);
        //ajout de la commande de Création de cet element
		insertCommand(new CreateElementCommand(&listeGraphics, &hashedName, c ));

		cout<<"OK"<<endl;
		cout<<"#New object :"<<name<<endl;
	}
}

void Container::AddRectangle(const string name, const long coin1X, const long coin1Y, const long coin2X, const long coin2Y, const string commande)
// Algorithme : Création d'un objet rectangle (de type Figure) à partir des valeurs passées en paramètres
// On vérifie que le nom n'est pas déjà pris par une autre figure ou sélection
{

    if(hashedName.find(name)!=hashedName.end())//verification de la disponibilite du nom
    {
		cout<<"ERR"<<endl;
		cout<<"#name already taken"<<endl;
		return;
	}
	Point origin;
	Point extremity;
    origin.x=coin1X;
    extremity.x=coin2X;
    origin.y=coin1Y;
    extremity.y=coin2Y;

    //Création du Rectangle
    Rectangle *r=new Rectangle(extremity, origin, name, commande);
    //ajout a la map de Graphics
    listeGraphics.insert(make_pair(name, r));
    //ajout du nom dans la table de hash
    hashedName.insert(name);
    //ajout de la commande de Création de cet element
	insertCommand(new CreateElementCommand(&listeGraphics, &hashedName, r ));

	cout<<"OK"<<endl;
	cout<<"#New object :"<<name<<endl;
}

void Container::AddLine(const string name, const long coin1X, const long coin1Y, const long coin2X, const long coin2Y, const string commande)
// Algorithme : Création d'un objet line (de type Figure) à partir des valeurs passées en paramètres
// On vérifie que le nom n'est pas déjà pris par une autre figure ou sélection
{
    if(hashedName.find(name)!=hashedName.end())//verification de la disponibilite du nom
    {
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

    //Création de la Ligne
    Line *l=new Line(extremity, origin, name, commande);
    //ajout a la map de Graphics
    listeGraphics.insert(make_pair(name, l));
    //ajout du nom dans la table de hash
    hashedName.insert(name);
    //ajout de la commande de Création de cet element
    insertCommand(new CreateElementCommand(&listeGraphics, &hashedName, l ));

	cout<<"OK"<<endl;
	cout<<"#New object : "<<name<<endl;
}

void Container::AddPolyline(const string name, const vector<Point> newPointList, const Point origin, const string commande)
// Algorithme : Création d'un objet polyline (de type Figure) à partir des valeurs passées en paramètres
// On vérifie que le nom n'est pas déjà pris par une autre figure ou sélection
{
    if(hashedName.find(name)!=hashedName.end()) //verification de la disponibilite du nom
    {
		cout<<"ERR"<<endl;
		cout<<"#name already taken"<<endl;
		return;
	}

    //Création de la Polyligne
	Polyline *pl =new Polyline (newPointList, origin, name, commande);
    //ajout a la map de Graphics
    listeGraphics.insert(make_pair(name, pl));
    //ajout du nom dans la table de hash
    hashedName.insert(name);
    //ajout de la commande de Création de cet element
    insertCommand(new CreateElementCommand(&listeGraphics, &hashedName, pl ));

	cout<<"OK"<<endl;
	cout<<"#New object : "<<name<<endl;
}

void Container::AddSelection(const string name, const long coin1X, const long coin1Y, const long coin2X, const long coin2Y, const string commande)
// Algorithme : Création d'un objet selection (de type Selection) à partir des valeurs passées en paramètres
// On vérifie que le nom n'est pas déjà pris par une autre figure ou sélection
// On calcule les coordonnées du coin supérieur gauche et du coin inférieur droit du rectangle définissant la sélection
// On ajoute chaque figure se trouvant dans la sélection à la liste de figures que possède la sélection (permet de savoir quelles figures elle contient)
{
    if(hashedName.find(name)!=hashedName.end()) //Verification de la disponibilite du nom
    {
		cout<<"ERR"<<endl;
		cout<<"#name already taken"<<endl;
		return;
	}
	Point origin;
	Point extremity;
	//origin doit prendre le x minimum et y maximum (situé en haut à gauche)
	//extremity doir prendre le y minimum et x maximum (situé en bas à droite)
    origin.x=(coin1X<coin2X)?coin1X:coin2X;
	origin.y=(coin1Y<coin2Y)?coin2Y:coin1Y;
	extremity.x=(coin1X<coin2X)?coin2X:coin1X;
	extremity.y=(coin1Y<coin2Y)?coin1Y:coin2Y;

    vector<Figure*> figuresInside;  //continedra les figures situées dans la selection
    Graphics_iterator it;
    Figure *temp=NULL;

    for(it=listeGraphics.begin(); it!=listeGraphics.end(); ++it)
    {
        temp=dynamic_cast<Figure *>(it->second);// on teste pour chaque element de la map si c'est une figure (et donc pas une selection)
        if(temp!=NULL)  //Si c'est effectivement une figure on la considère
        { 
            if( temp->IsInside(origin, extremity) )// on teste son appartenance à la selection
            {
                figuresInside.push_back(temp);
            }
        }
    }

    //Création de la Selection a partir des figures qu'elle contient
    Selection *s =new Selection (figuresInside, origin, extremity, name, commande);
    //ajout a la map de Graphics
	listeGraphics.insert(make_pair(name, s));
    //ajout du nom dans la table de hash
	hashedName.insert(name);

    // NB : On ne crée pas de Command pour cette action, la création de selection n'etant pas UNDO-ABLE

	cout<<"OK"<<endl;
	cout<<"#New object : "<<name<<endl;
}

void Container::Undo()
// Algorithme : Permet d'annuler la dernière opération
// Il suffit de récupérer la dernière commande que l'on a ajouté à la pile des UNDO et de l'annuler et de la placer dans la pile des REDO
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
        cout<<"OK"<<endl;
        cout << "#nothing to undo !" << endl;

    }
}

void Container::Redo()
// Algorithme : Permet de réexécuter une action que l'on vient d'annuler (contraire du UNDO)
// Il suffit de récupérer la derniere commande que l'on a ajouté à la pile des REDO et de l'exécuter et de la placer dasn la pile des REDO
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
        cout<<"OK"<<endl;
        cout << "#nothing to redo !" << endl;

    }
}

//------------------------------------------------------------------ PRIVE

void Container::insertCommand(Command* const cmd)
// Algorithme : Insère une nouvelle commande dans la pile des UNDO et vide la pile des REDO
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
