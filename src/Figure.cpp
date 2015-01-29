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
#include "Selection.h"





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

bool Figure::IsInside(Point p1, Point p2)
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

} //----- Fin de IsInside


void Figure::AddSelect(Selection* s){
    cout << "AddSelect dans " << name << " de : " << s->GetName() << endl;
    whoOwnsMe.push_back(s);
}

void Figure::EraseSelect(Selection* s){
    cout << "EraseSelect dans " << name << " de : " << s->GetName() << endl;
    vector<Selection*>::iterator it;
    for(it=whoOwnsMe.begin(); it!=whoOwnsMe.end(); ++it){
        if( (*it)==s){
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
    cout << "Appel au destructeur de <Figure>" << endl;
#ifdef MAP
    cout << "Appel au destructeur de <Figure>" << endl;
#endif
} //----- Fin de ~Figure


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
