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
#include "toString.h"
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
Circle::Circle ( const Circle & unCircle ):Figure(unCircle)
// Algorithme :
//
{
    	leftUpCorner.x=origin.x-radius;
        leftUpCorner.y=origin.y+radius;
        downRightCorner.x=origin.x+radius;
        downRightCorner.y=origin.y-radius;
#ifdef MAP
    cout << "Appel au constructeur de copie de <Circle>" << endl;
#endif
} //----- Fin de Circle (constructeur de copie)


Circle::Circle (long circleRadius, Point figureOrigin, string graphicsName, string graphicsCommandLine)
		:Figure(figureOrigin, graphicsName, graphicsCommandLine), radius(circleRadius)
{

        leftUpCorner.x=origin.x-radius;
        leftUpCorner.y=origin.y+radius;
        downRightCorner.x=origin.x+radius;
        downRightCorner.y=origin.y-radius;
#ifdef MAP
    cout << "Appel au constructeur de <Circle>" << endl;
#endif
} //----- Fin de Circle*/


Circle::~Circle ( )
// Algorithme :
//
{
    cout << "Appel au destructeur de <Circle>" << endl;
    vector<Selection*>::iterator it;
    for(it=whoOwnsMe.begin(); it!=whoOwnsMe.end(); ++it){
        (*it)->EraseFigure(this);
    }
#ifdef MAP
    cout << "Appel au destructeur de <Circle>" << endl;
#endif
} //----- Fin de ~Circle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


string Circle::description()
// Algorithme :
//
{
	return commandLine+"\r\n";

} //----- Fin de description

void Circle::move(long dx, long dy)
// Algorithme :
//
{
	origin.x += dx;
	origin.y += dy;

    leftUpCorner.x+=dx;
    leftUpCorner.y+=dy;
    downRightCorner.x+=dx;
    downRightCorner.y+=dy;

	commandLine="C "+name+" "+toString(origin.x)+" "+toString(origin.y)+" "+toString(radius);

} //----- Fin de move
//------------------------------------------------------- Méthodes privées
