/*************************************************************************
                           Selection  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Selection> (fichier Selection.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Selection.h"
#include "toString.h"
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Selection::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Selection::Selection ( const Selection & unSelection )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Selection>" << endl;
#endif
} //----- Fin de Selection (constructeur de copie)


 Selection::Selection (vector <Figure*> newFigureList, Point p1, Point p2, string graphicsName, string graphicsCommandLine)
 // Algorithme :
//
{
   coinGauche=p1;
   coinDroit=p2;
   name=graphicsName;
   commandLine=graphicsCommandLine;

    figureList.swap(newFigureList);

#ifdef MAP
    cout << "Appel au constructeur de <Selection>" << endl;
#endif
} //----- Fin de Selection

Selection::~Selection ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Selection>" << endl;
#endif
} //----- Fin de ~Selection


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

    string Selection::description()
    // type Selection::Méthode ( liste de paramètres )
    // Algorithme :
    {
        return "";
    } //----- Fin de description

    bool Selection::isInside(Point p1, Point p2){
        if( (p1.x <=coinGauche.x) &&
		(p2.x >=coinDroit.x) &&
		(p1.y >=coinGauche.y) &&
		(p2.y <=coinDroit.y) )
	{
		return true;
	}
	else
	{
		return false;
	}
    }

    void Selection::move(long dx, long dy)
    // type Selection::Méthode ( liste de paramètres )
    // Algorithme :
    {
    vector<Figure*>::iterator it;
    for(it=figureList.begin(); it!=figureList.end(); ++it){
        if( (*it)->isInside(coinGauche, coinDroit) ){
            (*it)->move(dx,dy);
        }
    }
    coinGauche.x += dx;
	coinGauche.y += dy;
	coinDroit.x += dx;
	coinDroit.y += dy;
	commandLine="S "+name+" "+toString(coinGauche.x)+" "+toString(coinGauche.y)+" "+toString(coinDroit.x)+" "+toString(coinDroit.y);
    } //----- Fin de move
//------------------------------------------------------- Méthodes privées
