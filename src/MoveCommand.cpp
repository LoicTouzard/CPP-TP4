/*************************************************************************
                           MoveCommand  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par TOUZARD Loïc, GOUZI Gaëtan et GONZALEZ TOLEDO Gabriela
*************************************************************************/

//---------- Réalisation de la classe <MoveCommand> (fichier MoveCommand.cpp}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "MoveCommand.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void MoveCommand::Execute()
 // Algorithme : Déplace de origin.x et origin.y le Graphics associé
//
{
    element->move(origin.x, origin.y);
    whichList=IN_UNDO;
}

void MoveCommand::UnExecute()
 // Algorithme : Déplace de -origin.x et -origin.y le Graphics associé
//
{
    element->move(-(origin.x), -(origin.y));
    whichList=IN_REDO;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
MoveCommand::MoveCommand ( const MoveCommand & unMoveCommand ):SimpleCommand(unMoveCommand)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <MoveCommand>" << endl;
#endif
} //----- Fin de MoveCommand (constructeur de copie)


MoveCommand::MoveCommand ( MapGraphics* mapToLink, unordered_set<string>* hashToLink, Graphics* elt, Point newOrigin )
    :SimpleCommand(mapToLink, hashToLink, elt), origin(newOrigin)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <MoveCommand>" << endl;
#endif
} //----- Fin de MoveCommand


MoveCommand::~MoveCommand ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <MoveCommand>" << endl;
#endif
} //----- Fin de ~MoveCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
