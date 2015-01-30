/*************************************************************************
                           Rectangle  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par Touzard Loïc et GOUZI Gaëtan
*************************************************************************/

//---------- Réalisation de la classe <Rectangle> (fichier Rectangle.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Rectangle.h"
#include "toString.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Rectangle::Rectangle ( const Rectangle & unRectangle ):Figure(unRectangle)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle (constructeur de copie)


Rectangle::Rectangle (Point recExtremity, Point figureOrigin, string graphicsName, string graphicsCommandLine)
    :Figure(figureOrigin, graphicsName, graphicsCommandLine), extremity(recExtremity)
// Algorithme :
//
{
    leftUpCorner.x=(origin.x<extremity.x)?origin.x:extremity.x;
	leftUpCorner.y=(origin.y<extremity.y)?extremity.y:origin.y;

	downRightCorner.x=(origin.x<extremity.x)?extremity.x:origin.x;
	downRightCorner.y=(origin.y<extremity.y)?origin.y:extremity.y;
#ifdef MAP
    cout << "Appel au constructeur de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle*/


Rectangle::~Rectangle ( )
// Algorithme :
//
{
    vector<Selection*>::iterator it;
    for(it=whoOwnsMe.begin(); it!=whoOwnsMe.end(); ++it){
        (*it)->EraseFigure(this);
    }
#ifdef MAP
    cout << "Appel au destructeur de <Rectangle>" << endl;
#endif
} //----- Fin de ~Rectangle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


string Rectangle::description()
// Algorithme :
//
{
	return commandLine+"\r\n";

} //----- Fin de description

void Rectangle::move(long dx, long dy)
// Algorithme :
//
{
	origin.x += dx;
	origin.y += dy;
	extremity.x += dx;
	extremity.y += dy;

    leftUpCorner.x+=dx;
    leftUpCorner.y+=dy;
    downRightCorner.x+=dx;
    downRightCorner.y+=dy;

	commandLine="R "+name+" "+toString(origin.x)+" "+toString(origin.y)+" "+toString(extremity.x)+" "+toString(extremity.y);

} //----- Fin de move

//------------------------------------------------------- Méthodes privées
