/*************************************************************************
                           SimpleCommand  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par TOUZARD Loïc, GOUZI Gaëtan et GONZALEZ TOLEDO Gabriela
*************************************************************************/

//---------- Réalisation de la classe <SimpleCommand> (fichier SimpleCommand.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "SimpleCommand.h"
#include "Container.h"
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
SimpleCommand::SimpleCommand ( const SimpleCommand & SimpleCommand )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <SimpleCommand>" << endl;
#endif
} //----- Fin de SimpleCommand (constructeur de copie)


SimpleCommand::SimpleCommand ( MapGraphics* mapToLink,  unordered_set<string>* hashToLink, Graphics* elt)
    :linkedMap(mapToLink), linkedHash(hashToLink), element(elt)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <SimpleCommand>" << endl;
#endif
} //----- Fin de SimpleCommand


SimpleCommand::~SimpleCommand ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <SimpleCommand>" << endl;
#endif
} //----- Fin de ~SimpleCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
