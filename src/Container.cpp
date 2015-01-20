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
//------------------------------------------------------ Include personnel
#include "Container.h"
#include "Point.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Line.h"
#include "Polyline.h"
#include "Selection.h"
#include "toString.h"
//------------------------------------------------------------- Constantes

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
	if(it==listeGraphics.end()){
		it->second->move(dX, dY);
		cout<<"OK"<<endl;
	}
	else{
		cout<<"ERR"<<endl;
		cout<<"#"<<name<<" not found"<<endl;
   }
}

void Container::Load(string nomFichier){

}

void Container::Delete(vector<string> listeNoms)
{
	for(unsigned int i=0; i<listeNoms.size(); ++i)
	{
		if(!NomLibre( listeNoms[i] ) )
		{
			cout<<"ERR"<<endl;
			cout<<"# can't find "+listeNoms[i]+ ". None of the elements have been removed"<<endl;
			return;
		}
	}
	for(unsigned int i=0; i<listeNoms.size(); ++i)
	{
		delete listeGraphics[listeNoms[i]];
	}
	// Penser au cas de la selection suivie des ses éléments (contrat ?)
	cout<<"OK"<<endl;
}

void Container::AddCircle(string name, long radius, long centerX, long centerY, string commande)
{
	if(!NomLibre(name)){
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
		//Fin du code pour ajouter un cerlce
		cout<<"OK"<<endl;
		cout<<"#New object :"<<name<<endl;
	}
}

void Container::AddRectangle(string name, long coin1X, long coin1Y, long coin2X, long coin2Y, string commande)
{
	Point origin;
	Point extremity;
	//origin doit prendre le x minimum et y maximum
	//extremity doir prendre le y minimum et x maximum
	if(!NomLibre(name)){
		cout<<"ERR"<<endl;
		cout<<"#name already taken"<<endl;
		return;
	}
	
	if(coin1X>coin2X)
	{
		origin.x=coin2X;
		extremity.x=coin1X;
		cout<<"#Reverse corner's X coordonates"<<endl;
	}
	else
	{
		origin.x=coin1X;
		extremity.x=coin2X;
	}
	if(coin1Y<coin2Y)
	{
		origin.y=coin2Y;
		extremity.y=coin1Y;	
		cout<<"#Reverse corner's Y coordonates"<<endl;				
	}
	else
	{
		origin.y=coin1Y;
		extremity.y=coin2Y;	
	}
	string cmd="R "+name+" "+toString(origin.x)+" "+toString(origin.y)+" "+toString(extremity.x)+" "+toString(extremity.y);
	Rectangle *r=new Rectangle(extremity, origin, name, cmd);
	listeGraphics.insert(make_pair(name, r));
	cout<<"OK"<<endl;
	cout<<"#New object :"<<name<<endl;
}

void Container::AddLine(string name, long coin1X, long coin1Y, long coin2X, long coin2Y, string commande)
{
	Point origin;
	Point extremity;

	origin.x=coin1X;
	origin.y=coin1Y;
	extremity.x=coin2X;
	extremity.y=coin2Y;
	
	string cmd="L "+name+" "+toString(origin.x)+" "+toString(origin.y)+" "+toString(extremity.x)+" "+toString(extremity.y);
	Line *l=new Line(extremity, origin, name, cmd);
	listeGraphics.insert(make_pair(name, l));
	cout<<"OK"<<endl;
	cout<<"#New object :"<<name<<endl;
}

void Container::AddPolyline(string name, vector<Point> newPointList, Point origin, string commande)
{
	string cmd="PL "+name;
	vector<Point>::iterator it;
	for(it=newPointList.begin(); it!=newPointList.end(); ++it){
		cmd += " "+toString(it->x)+" "+toString(it->y);
	}
	Polyline *pl =new Polyline (newPointList, origin, name, cmd);
	listeGraphics.insert(make_pair(name, pl));
	cout<<"OK"<<endl;
	cout<<"#New object :"<<name<<endl;
}

void Container::AddSelection()
{
	
}

//------------------------------------------------------------------ PRIVE
bool Container::NomLibre(string name)
{
	Graphics_iterator it;
	it=listeGraphics.find(name);
	if(it==listeGraphics.end()){
		return true;
	}
	return false;
}
//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
