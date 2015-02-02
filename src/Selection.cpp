/*************************************************************************
                           Selection  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par TOUZARD Loïc, GOUZI Gaëtan et GONZALEZ TOLEDO Gabriela
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
 // Algorithme : Création d'une selection à partir des paramètres
// Pour chaque figure contenue (entièrement) dans cette sélection, on lui ajoute la selection dans son vector whoOwnsMe
// (qui repertorie toutes les sélections dans lesquelles la figure est incluse)
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
// Algorithme : Pour chaque figure contenue dans cette selection on lui retire la selection courante de son vector whoOwnsMe
// (qui repertorie toutes les sélections dans lesquelles la figure est incluse)
{
    vector<Figure*>::iterator it;
    for(it=figureList.begin(); it!=figureList.end(); ++it){
        (*it)->EraseSelect(this);
    }
#ifdef MAP
    cout << "Appel au destructeur de <Selection>" << endl;
#endif
} //----- Fin de ~Selection


void Selection::EraseFigure(Figure* f)
// Algorithme : Permet de retirer une figure contenue dans une selection
// Si une figure est détruite, il faut spécifier aux sélections qui la contenaient qu'elle ne fait plus partie de leur liste de figures
{
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
    // Algorithme : Renvoie une chaine vide : Méthode utile pour les figures mais inutile pour les sélections (obligé de la redéfinir car description() est virtual pure dans Gaphics)
    {
        return "";
    } //----- Fin de description


    void Selection::move(long dx, long dy)
    // Algorithme : Déplace la sélection et les figures qu'elle contient de dX et dY
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
