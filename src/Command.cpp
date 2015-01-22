/*************************************************************************
                           Command  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Command> (fichier Command.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Command.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Command::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Command::Command ( const Command & unCommand )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Command>" << endl;
#endif
} //----- Fin de Command (constructeur de copie)


Command::Command ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Command>" << endl;
#endif
} //----- Fin de Command


Command::~Command ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Command>" << endl;
#endif
} //----- Fin de ~Command


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
