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
Selection::Selection ( const Selection & unSelection ):Graphics(unSelection)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Selection>" << endl;
#endif
} //----- Fin de Selection (constructeur de copie)


 Selection::Selection (vector<Figure*> newFigureList, Point p1, Point p2, string graphicsName, string graphicsCommandLine)
  :Graphics(graphicsName, graphicsCommandLine), origin(p1), extremity(p2), figureList(newFigureList)
 // Algorithme :
//
{
    vector<Figure*>::iterator it;
    for(it=figureList.begin(); it!=figureList.end(); ++it){
        (*it)->AddSelect(this);
    }
#ifdef MAP
    cout << "Appel au constructeur de <Selection>" << endl;
#endif
} //----- Fin de Selection

Selection::~Selection ( )
// Algorithme :
//
{
    cout << "Appel au destructeur de <Selection>" << endl;vector<Figure*>::iterator it;
    for(it=figureList.begin(); it!=figureList.end(); ++it){
        (*it)->EraseSelect(this);
    }
#ifdef MAP
    cout << "Appel au destructeur de <Selection>" << endl;
#endif
} //----- Fin de ~Selection


void Selection::EraseFigure(Figure* f){
    cout << "EraseFigure dans " << name << " de : " << f->GetName() << endl;
    vector<Figure*>::iterator it;
    for(it=figureList.begin(); it!=figureList.end(); ++it){
        if( (*it)==f){
            figureList.erase(it);
            it--;
        }
    }
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

    string Selection::description()
    // type Selection::Méthode ( liste de paramètres )
    // Algorithme :
    {
        return "";
    } //----- Fin de description


    void Selection::move(long dx, long dy)
    // type Selection::Méthode ( liste de paramètres )
    // Algorithme :
    {
    vector<Figure*>::iterator it;
    for(it=figureList.begin(); it!=figureList.end(); ++it){
        (*it)->move(dx,dy);
    }
    origin.x += dx;
	origin.y += dy;
	extremity.x += dx;
	extremity.y += dy;
    } //----- Fin de move
//------------------------------------------------------- Méthodes privées
