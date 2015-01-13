/*************************************************************************
                           Circle  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Circle> (fichier Circle.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Circle.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs
Circle & Circle::operator = ( const Circle & unCircle )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Circle::Circle ( const Circle & unCircle )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Circle>" << endl;
#endif
} //----- Fin de Circle (constructeur de copie)


Circle::Circle (long newRadius, Point figureOrigin, string graphicsName, string graphicsCommandLine)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Circle>" << endl;
#endif
} //----- Fin de Circle


Circle::~Circle ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Circle>" << endl;
#endif
} //----- Fin de ~Circle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
Circle::bool isInside(Point p1, Point p2)
// Algorithme :
//
{

	if( (p1.x <=origin.x-radius) &&
		(p2.x >=origin.x+radius) &&
		(p1.y >=origin.y+radius) &&
		(p2.y <=origin.y-radius) )
	{
		return true;
	}
	else
	{
		return false;
	}

} //----- Fin de isInside

Circle::virtual string description()
// Algorithme :
//
{
	return commandLine;

} //----- Fin de description

Circle::virtual void move(long dx, long dy)
// Algorithme :
//
{
	origin.x += dx;
	origin.y += dy;

	commandLine="C "+name+" "+Long_to_string(origin.x)+" "+Long_to_string(origin.y)+" "+Long_to_string(radius);

} //----- Fin de move
//------------------------------------------------------- Méthodes privées
