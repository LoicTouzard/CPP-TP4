/*************************************************************************
                           DeleteElementCommand
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par TOUZARD Loïc, GOUZI Gaëtan et GONZALEZ TOLEDO Gabriela
*************************************************************************/

//---------- Réalisation de la classe <DeleteElementCommand> (fichier DeleteElementCommand.cpp}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "DeleteElementCommand.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques



void DeleteElementCommand::Execute()
// Mode d'emploi : Enleve l'element de la MapGraphics et de la HashTable
//
// Contrat :
//
{
 
    //l'element est gardé en mémoire pour un futur Execute plus rapide (pas de réallocation)
    linkedMap->erase(element->GetName());
    linkedHash->erase(element->GetName());

    //on désactive l'element
    element->SetInDraw(GRAPHICS_STATE_NOT_IN_DRAW);
    whichList=IN_UNDO;

}

void DeleteElementCommand::UnExecute()
// Mode d'emploi : Insere l'element dans la MapGraphics et dans la HashTable
//
// Contrat :
//
{
    //on insère directement l'élément pas de vérification à faire car le nom est forcément libre
    //de plus l'objet est déjà bien construit
    linkedMap->insert(make_pair(element->GetName(), element));
    linkedHash->insert( element->GetName() );

    //on réactive l'element
    element->SetInDraw(GRAPHICS_STATE_IN_DRAW);
    whichList=IN_REDO;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
DeleteElementCommand::DeleteElementCommand ( const DeleteElementCommand & unDeleteElementCommand )
    :SimpleCommand(unDeleteElementCommand)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <DeleteElementCommand>" << endl;
#endif
} //----- Fin de DeleteElementCommand (constructeur de copie)


DeleteElementCommand::DeleteElementCommand ( MapGraphics* mapToLink, unordered_set<string>* hashToLink, Graphics* elt)
    :SimpleCommand(mapToLink, hashToLink, elt)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <DeleteElementCommand>" << endl;
#endif
} //----- Fin de DeleteElementCommand


DeleteElementCommand::~DeleteElementCommand ( )
// Algorithme : Detruit la Command et libère potentiellement l'element graphique associé
//
{
    if(whichList==IN_UNDO){
        delete element;
    }
#ifdef MAP
    cout << "Appel au destructeur de <DeleteElementCommand>" << endl;
#endif
} //----- Fin de ~DeleteElementCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
