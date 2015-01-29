/*************************************************************************
                           Container  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
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
//#include "LoadCommand.h"
//------------------------------------------------------------- Constantes
const size_t UNDO_REDO_MAX_LEVEL = 20;
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
#ifdef MAP
    cout << "Appel au destructeur de <Container>" << endl;
#endif
} //----- Fin de ~Container


void Container::Save(string nomFichier)
// Algorithme :
//
{
	ofstream fichier;
    fichier.open(nomFichier.c_str(),ios::trunc);
	if(fichier){
		Graphics_iterator it;
		for(it=listeGraphics.begin(); it!=listeGraphics.end();++it){
			fichier<<it->second->description();
		}
		fichier.close();
		cout<<"OK"<<endl;
	}
	else{
		cout<<"#Can't create the file "<<nomFichier<<endl;
	}
}

void Container::Clear()
// Algorithme :
//
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

void Container::List()
// Algorithme :
//
{
	Graphics_iterator it;
	if(listeGraphics.size()==0){
		cout<<"#The list is empty"<<endl;
	}
	else{
		for(it=listeGraphics.begin(); it!=listeGraphics.end();++it){
			cout<<it->second->description();
		}
	}
}

void Container::moveElement(string name, long dX, long dY){
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

void Container::Load(string nomFichier)
{
    /*// COPIE COLLE DU CODE MAIN ( A FACTORISER ? )
    string entree;
    ifstream loadFile (nomFichier);
    if (loadFile.is_open())
    {

        MapGraphics tmpMap;
        vector<Command*> listeCMD;

        bool correctFile = true;
        while ( getline (loadFile,entree) && correctFile)
        {
            if (entree.substr(0,1)=="C") {
                string name;
                string radius, centerX, centerY;
                name=Tools::Decoupage(entree,1);
                centerX=Tools::Decoupage(entree,2);
                centerY=Tools::Decoupage(entree,3);
                radius=Tools::Decoupage(entree,4);

                if(Tools::NombreEspaces(entree)==4)
                {
                    long centerlX=atol(centerX.c_str());
                    long centerlY=atol(centerY.c_str());
                    long radiusl=atol(radius.c_str());

                    if(!NomLibre(name, &listeGraphics) || !NomLibre(name, &tmpMap)){
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
                        //Code pour ajouter un cercle
                        Point center;
                        center.x=centerlX;
                        center.y=centerlY;
                        Circle *c=new Circle(radiusl, center, name, entree);

                        tmpMap.insert(make_pair(name, c));
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

            else if (entree.substr(0,1)=="R") {

                string name;
                string corner1X, corner1Y, corner2X, corner2Y;
                long coin1X, coin1Y, coin2X, coin2Y;
                name=Tools::Decoupage(entree,1);
                corner1X=Tools::Decoupage(entree,2);
                corner1Y=Tools::Decoupage(entree,3);
                corner2X=Tools::Decoupage(entree,4);
                corner2Y=Tools::Decoupage(entree,5);

                coin1X=atol(corner1X.c_str());
                coin1Y=atol(corner1Y.c_str());
                coin2X=atol(corner2X.c_str());
                coin2Y=atol(corner2Y.c_str());

                if(Tools::NombreEspaces(entree)==5){


                    if(!NomLibre(name, &listeGraphics) || !NomLibre(name, &tmpMap)){
                        correctFile = false;
                        cout<<"ERR"<<endl;
                        cout<<"#name already taken"<<endl;
                        break;
                    }
                    Point origin;
                    Point extremity;
                    origin.x=coin1X;
                    extremity.x=coin2X;
                    origin.y=coin1Y;
                    extremity.y=coin2Y;
                    Rectangle *r=new Rectangle(extremity, origin, name, entree);

                    tmpMap.insert(make_pair(name, r));
                    listeCMD.push_back(new CreateElementCommand(&listeGraphics, r));

                }
                else{
                    correctFile = false;
                    cout<<"ERR"<<endl;
                    cout<<"#invalid parameters"<<endl;
                }
            }

            else if (entree.substr(0,2)=="PL") {
                string name;
                string cornerX, cornerY;
                long coinX, coinY;
                name=Tools::Decoupage(entree,1);

                if( Tools::NombreEspaces(entree)%2==1 && Tools::NombreEspaces(entree)>=3){ //Un point minimum
                    //Code pour ajouter un polyligne
                    int nbPoints=(Tools::NombreEspaces(entree)-1)/2;
                    Point origin;
                    vector<Point> newPointList;
                    cornerX=Tools::Decoupage(entree,2);
                    cornerY=Tools::Decoupage(entree,3);
                    coinX=atol(cornerX.c_str());
                    coinY=atol(cornerY.c_str());
                    origin.x=coinX;
                    origin.y=coinY;
                    for(int i=2; i<=nbPoints; i++){
                        //Améliorer performances de découpage
                        cornerX=Tools::Decoupage(entree,i*2);
                        cornerY=Tools::Decoupage(entree,i*2+1);
                        coinX=atol(cornerX.c_str());
                        coinY=atol(cornerY.c_str());
                        Point p;
                        p.x=coinX;
                        p.y=coinY;
                        newPointList.push_back(p);
                    }

                    if(!NomLibre(name, &listeGraphics) || !NomLibre(name, &tmpMap)){
                        correctFile = false;
                        cout<<"ERR"<<endl;
                        cout<<"#name already taken"<<endl;
                        break;
                    }

                    Polyline *pl =new Polyline (newPointList, origin, name, entree);

                    tmpMap.insert(make_pair(name, pl));
                    listeCMD.push_back(new CreateElementCommand(&listeGraphics, pl));

                }
                else{
                    correctFile = false;
                    cout<<"ERR"<<endl;
                    cout<<"#invalid parameters"<<endl;
                }
            }

            else if (entree.substr(0,1)=="L") {
                string name;
                string corner1X, corner1Y, corner2X, corner2Y;
                long coin1X, coin1Y, coin2X, coin2Y;
                name=Tools::Decoupage(entree,1);
                corner1X=Tools::Decoupage(entree,2);
                corner1Y=Tools::Decoupage(entree,3);
                corner2X=Tools::Decoupage(entree,4);
                corner2Y=Tools::Decoupage(entree,5);

                coin1X=atol(corner1X.c_str());
                coin1Y=atol(corner1Y.c_str());
                coin2X=atol(corner2X.c_str());
                coin2Y=atol(corner2Y.c_str());

                 if(Tools::NombreEspaces(entree)==5){

                        if(!NomLibre(name, &listeGraphics) || !NomLibre(name, &tmpMap)){
                            correctFile = false;
                            cout<<"ERR"<<endl;
                            cout<<"#name already taken"<<endl;
                            break;
                        }

                        Point origin;
                        Point extremity;

                        origin.x=coin1X;
                        origin.y=coin1Y;
                        extremity.x=coin2X;
                        extremity.y=coin2Y;

                        Line *l=new Line(extremity, origin, name, entree);

                        tmpMap.insert(make_pair(name, l));
                        listeCMD.push_back(new CreateElementCommand(&listeGraphics, l));

                }
                else{
                    correctFile = false;
                    cout<<"ERR"<<endl;
                    cout<<"#invalid parameters"<<endl;
                }
            }
            else
            {
                correctFile = false;
                cout<<"ERR"<<endl;
                cout<<"#Unknown command"<<endl;
            }

        }
        loadFile.close();
        if(correctFile)
        {
            //la création est confirmée car tous les éléments sont corrects
            listeGraphics.insert(tmpMap.begin(), tmpMap.end()); //merge
            insertCommand(new LoadCommand(listeCMD));
            cout << "#" << tmpMap.size() << "elements have been loaded successfully." << endl;
            cout << "OK" << endl;
        }
        else
        {
            //il y a eu une erreur dans le fichier on libère ce qui a été créé
            cout<<"#Error line : " << tmpMap.size()+1 << endl;
            cout<<"#The load file couldn't be loaded. None of the elements have been created."<<endl;

            MapGraphics::iterator it;
            for (it = tmpMap.begin(); it != tmpMap.end(); ++it){
                delete it->second;
            }
            tmpMap.clear();
            listeCMD.clear();
        }
    }
    else
    {
        cout << "ERR" << endl;
        cout << "#Unable to open file";
    }*/
}

void Container::Delete(vector<string> listeNoms)
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
            listeCMD.push_back(new DeleteElementCommand(&listeGraphics, it->second));
            listeGraphics.erase(it);
        }
	}
	insertCommand(new DeleteCommand(listeCMD));
	// Penser au cas de la selection suivie des ses éléments (contrat ?)
	cout<<"OK"<<endl;
}

void Container::AddCircle(string name, long radius, long centerX, long centerY, string commande)
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
		Circle *c=new Circle(radius, center, name, commande);
		listeGraphics.insert(make_pair(name, c));
		insertCommand(new CreateElementCommand(&listeGraphics, c ));
		//Fin du code pour ajouter un cerlce
		cout<<"OK"<<endl;
		cout<<"#New object :"<<name<<endl;
	}
}

void Container::AddRectangle(string name, long coin1X, long coin1Y, long coin2X, long coin2Y, string commande)
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

void Container::AddLine(string name, long coin1X, long coin1Y, long coin2X, long coin2Y, string commande)
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
	cout<<"#New object :"<<name<<endl;
}

void Container::AddPolyline(string name, vector<Point> newPointList, Point origin, string commande)
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
	cout<<"#New object :"<<name<<endl;
}

void Container::AddSelection(string name, long coin1X, long coin1Y, long coin2X, long coin2Y, string commande)
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

    vector<Figure*> figuresInside;
    Graphics_iterator it;
    for(it=listeGraphics.begin(); it!=listeGraphics.end(); ++it){
        if( it->second->isInside(origin, extremity) ){
            figuresInside.push_back(dynamic_cast<Figure *>(it->second));
            //Dynamic_cast permet de ne récupérer que la partie Figure de it (qui est un iterator de Graphics)
            //Pb : Si une selection est déjà présente dans le container : on ne peut pas la cast en Figure
            // -> Pas d'exception et tout se passe bien je sais pas pourquoi (peut etre que le exception sont dans cette méthode dynamic_cast ?
        }
    }
    Selection *s =new Selection (figuresInside, origin, extremity, name, commande);
	listeGraphics.insert(make_pair(name, s));
    insertCommand(new CreateElementCommand(&listeGraphics, s ));
	cout<<"OK"<<endl;
	cout<<"#New object :"<<name<<endl;
}

void Container::Undo()
{
    if(!undoCommands.empty())
    {
        Command* tmpCommand = undoCommands.front(); //on prend la commande du haut de la pile
        undoCommands.pop_front();
        tmpCommand->unexecute();
        redoCommands.push_front(tmpCommand);//on met la command au sommet de la pile de undo
        cout<<"OK"<<endl;
    }
    else
    {
        cout << "#nothing to undo !" << endl;
    }
}

void Container::Redo()
{
    if(!redoCommands.empty())
    {
        Command* tmpCommand = redoCommands.front(); //on prend la commande du haut de la pile
        redoCommands.pop_front();
        tmpCommand->execute();
        undoCommands.push_front(tmpCommand);//on met la command au sommet de la pile de undo
        cout<<"OK"<<endl;
    }
    else
    {
        cout << "#nothing to redo !" << endl;
    }
}

//------------------------------------------------------------------ PRIVE
bool Container::NomLibre(string name, MapGraphics* mapToAnalyse)
//Renvoie true si le nom n'est pa dans la map
//Renvoie false si le nom est dans la map
{
	Graphics_iterator it;
	it=mapToAnalyse->find(name);
	if(it==mapToAnalyse->end()){
		return true;
	}
	return false;
}

void Container::insertCommand(Command* cmd)
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
    list<Command*>::iterator it;
    for (it = redoCommands.begin(); it != redoCommands.end(); ++it){
        delete *it;
    }
    redoCommands.clear();
}
//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
