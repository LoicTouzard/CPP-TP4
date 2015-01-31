/*************************************************************************
                           CreateElementCommand  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par Touzard Loïc et GOUZI Gaëtan
*************************************************************************/

//---------- Réalisation de la classe <CreateElementCommand> (fichier CreateElementCommand.cpp}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CreateElementCommand.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void CreateElementCommand::Execute()
// Algorithme :
//
{
    //on insère directement l'élément pas de vérification à faire car le nom est forcément libre
    //de plus l'objet est déjà bien construit
    linkedMap->insert(make_pair(element->GetName(), element));
    whichList=IN_UNDO;
}

void CreateElementCommand::UnExecute()
// Algorithme :
//
{
    //l'element est gardé en mémoire pour un futur Execute plus rapide (pas de réallocation)
    linkedMap->erase(element->GetName());
    whichList=IN_REDO;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
CreateElementCommand::CreateElementCommand ( const CreateElementCommand & unCreateElementCommand ):SimpleCommand(unCreateElementCommand)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CreateElementCommand>" << endl;
#endif
} //----- Fin de CreateElementCommand (constructeur de copie)


CreateElementCommand::CreateElementCommand ( MapGraphics* mapToLink, Graphics* elt)
    :SimpleCommand(mapToLink, elt)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CreateElementCommand>" << endl;
#endif
} //----- Fin de CreateElementCommand


CreateElementCommand::~CreateElementCommand ( )
// Algorithme :
//
{
    if(whichList==IN_REDO){
        delete element;
    }
#ifdef MAP
    cout << "Appel au destructeur de <CreateElementCommand>" << endl;
#endif
} //----- Fin de ~CreateElementCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
