/*************************************************************************
                           SimpleCommand  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
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
// type SimpleCommand::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


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


SimpleCommand::SimpleCommand ( MapGraphics* mapToLink, Graphics* elt, Point newOrigin )
    :linkedMap(mapToLink), element(elt), origin(newOrigin)
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
