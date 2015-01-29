/*************************************************************************
                           Figure  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Figure> (fichier Figure.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Figure.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Figure::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool Figure::isInside(Point p1, Point p2)
// Algorithme :
//
{

	if( (p1.x <=leftUpCorner.x) &&
		(p2.x >=downRightCorner.x) &&
		(p1.y >=leftUpCorner.y) &&
		(p2.y <=downRightCorner.y) )
	{
		return true;
	}
	else
	{
		return false;
	}

} //----- Fin de isInside

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Figure::Figure ( const Figure & unFigure )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Figure>" << endl;
#endif
} //----- Fin de Figure (constructeur de copie)


/*Figure::Figure ( Point figureOrigin, string graphicsName2, string graphicsCommandLine2)
    :Graphics(graphicsName2, graphicsCommandLine2), origin(figureOrigin)
// Algorithme :
//
{
name=graphicsName2;
commandLine=graphicsCommandLine2;
origin=figureOrigin;
#ifdef MAP
    cout << "Appel au constructeur de <Figure>" << endl;
#endif
} //----- Fin de Figure*/


Figure::Figure ( ){

}

Figure::~Figure ( )
// Algorithme :
//
{

#ifdef MAP
    cout << "Appel au destructeur de <Figure>" << endl;
#endif
} //----- Fin de ~Figure


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
