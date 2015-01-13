/*************************************************************************
                           Container  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Container> (fichier Container.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Container.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Container::Container ( const Container & unContainer )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Container>" << endl;
#endif
} //----- Fin de Container (constructeur de copie)


Container::Container ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Container>" << endl;
#endif
} //----- Fin de Container


Container::~Container ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Container>" << endl;
#endif
} //----- Fin de ~Container


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
