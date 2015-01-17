/*************************************************************************
                           Rectangle  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Rectangle> (fichier Rectangle.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Rectangle.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Rectangle::Rectangle ( const Rectangle & unRectangle )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle (constructeur de copie)


/*Rectangle::Rectangle (Point recExtremity, Point figureOrigin, string graphicsName, string graphicsCommandLine)
// Algorithme :
//
{
    extremity=recExtremity;
    origin=figureOrigin;
    name=graphicsName;
    commandLine=graphicsCommandLine;
#ifdef MAP
    cout << "Appel au constructeur de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle*/


Rectangle::~Rectangle ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Rectangle>" << endl;
#endif
} //----- Fin de ~Rectangle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
bool Rectangle::isInside(Point p1, Point p2)
// Algorithme :
//
{

	if( (p1.x <=origin.x) &&
		(p2.x >=extremity.x) &&
		(p1.y >=origin.y) &&
		(p2.y <=extremity.y) )
	{
		return true;
	}
	else
	{
		return false;
	}

} //----- Fin de isInside

string Rectangle::description()
// Algorithme :
//
{
	return commandLine;

} //----- Fin de description

void Rectangle::move(long dx, long dy)
// Algorithme :
//
{
	origin.x += dx;
	origin.y += dy;
	extremity.x += dx;
	extremity.y += dy;

	commandLine="R "+name+" "+Long_to_string(origin.x)+" "+Long_to_string(origin.y)+" "+Long_to_string(extremity.x)+" "+Long_to_string(extremity.y);

} //----- Fin de move

//------------------------------------------------------- Méthodes privées
