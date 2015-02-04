/*************************************************************************
                           Figure  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par TOUZARD Loïc, GOUZI Gaëtan et GONZALEZ TOLEDO Gabriela
*************************************************************************/

//---------- Réalisation de la classe <Figure> (fichier Figure.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Figure.h"
#include "Selection.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies


//----------------------------------------------------- Méthodes publiques

bool Figure::IsInside(Point p1, Point p2) const
// Algorithme : Renvoie true si la figure est contenue dans le rctangle formé par les deux points passés en paramètres
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

} //----- Fin de IsInside


void Figure::AddSelect(Selection* const s)
// Algorithme : Ajoute une selection au vector whoOwnsMe qui contient toutes les sélections dans lesquelles fait partie la figure
//
{
    whoOwnsMe.push_back(s);
}

void Figure::EraseSelect(Selection* const s)
// Algorithme : Supprime une selection du vector whoOwnsMe qui contient toutes les sélections dans lesquelles fait partie la figure
//
{
    vector<Selection*>::iterator it;
    for(it=whoOwnsMe.begin(); it!=whoOwnsMe.end(); ++it)
    {
        if( (*it)==s)
        {
            whoOwnsMe.erase(it);
            it--;
        }
    }
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

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
