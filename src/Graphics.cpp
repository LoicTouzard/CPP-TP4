/*************************************************************************
                           Graphics  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par Touzard Loïc et GOUZI Gaëtan
*************************************************************************/

//---------- Réalisation de la classe <Graphics> (fichier Graphics.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Graphics.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Graphics::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Graphics::Graphics ( const Graphics & unGraphics )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Graphics>" << endl;
#endif
} //----- Fin de Graphics (constructeur de copie)


Graphics::~Graphics()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Graphics>" << endl;
#endif
} //----- Fin de ~Graphics


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
