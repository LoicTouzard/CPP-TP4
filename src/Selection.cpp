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


 /*Selection::Selection (vector <Figure*> newFigureList, Point p1, Point p2, string graphicsName, string graphicsCommandLine)
 // Algorithme :
//
{
   coinGauche=p1;
   coinDroit=p2;
   name=graphicsName;
   commandLine=graphicsCommandLine;
   figureList=new vector<Figure>;


#ifdef MAP
    cout << "Appel au constructeur de <Selection>" << endl;
#endif
} //----- Fin de Selection*/


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

    } //----- Fin de description

    void Selection::move(long dx, long dy)
    // type Selection::Méthode ( liste de paramètres )
    // Algorithme :
    {

    } //----- Fin de move
//------------------------------------------------------- Méthodes privées
