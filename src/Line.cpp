/*************************************************************************
                           Line  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Line> (fichier Line.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Line.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs
Line & Line::operator = ( const Line & unLine )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Line::Line ( const Line & unLine )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Line>" << endl;
#endif
} //----- Fin de Line (constructeur de copie)


Line::Line (Point recExtremity, Point figureOrigin, string graphicsName, string graphicsCommandLine)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Line>" << endl;
#endif
} //----- Fin de Line


Line::~Line ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Line>" << endl;
#endif
} //----- Fin de ~Line


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
Line::virtual bool isInside(Point p1, Point p2)
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

Line::virtual string description()
// Algorithme :
//
{
	return commandLine;
	
} //----- Fin de description

Line::virtual void move(long dx, long dy)
// Algorithme :
//
{
	origin.x += dx;
	origin.y += dy;
	extremity.x += dx;
	extremity.y += dy;
	
	commandLine="L "+name+" "+Long_to_string(origin.x)+" "+Long_to_string(origin.y)+" "+Long_to_string(extremity.x)+" "+Long_to_string(extremity.y);
	
} //----- Fin de move


//------------------------------------------------------- Méthodes privées
