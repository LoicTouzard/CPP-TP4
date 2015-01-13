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


//------------------------------------------------- Surcharge d'opérateurs
Figure & Figure::operator = ( const Figure & unFigure )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Figure::Figure ( const Figure & unFigure )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Figure>" << endl;
#endif
} //----- Fin de Figure (constructeur de copie)


Figure::Figure ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Figure>" << endl;
#endif
} //----- Fin de Figure


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
