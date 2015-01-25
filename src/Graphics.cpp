/*************************************************************************
                           Graphics  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
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


/*Graphics::Graphics (string graphicsName, string graphicsCommandLine )
// Algorithme :
//
{
name=graphicsName;
commandLine=graphicsCommandLine;
#ifdef MAP
    cout << "Appel au constructeur de <Graphics>" << endl;
#endif
} //----- Fin de Graphics*/


Graphics::Graphics (  ){}

Graphics::~Graphics ( )
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
