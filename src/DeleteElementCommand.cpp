/*************************************************************************
                           DeleteElementCommand  -  description
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
// type DeleteElementCommand::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


void DeleteElementCommand::Execute()
// Mode d'emploi :
//
// Contrat :
//
{
    //cout << "#tentative de suppression de " << element->GetName() << endl;
    //cout << "#il y a " << linkedMap->size() << "elements" << endl;
    //l'element est gardé en mémoire pour un futur Execute plus rapide (pas de réallocation)
    linkedMap->erase(element->GetName());
    //cout << "#il y a " << linkedMap->size() << "elements" << endl;
    whichList=IN_UNDO;

}

void DeleteElementCommand::UnExecute()
// Mode d'emploi :
//
// Contrat :
//
{
    //on insère directement l'élément pas de vérification à faire car le nom est forcément libre
    //de plus l'objet est déjà bien construit
    //cout << "#il y a " << linkedMap->size() << "elements" << endl;
    //cout << "#tentative d'ajout de " << element->GetName() << endl;
    linkedMap->insert(make_pair(element->GetName(), element));
    //cout << "#il y a " << linkedMap->size() << "elements" << endl;
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


DeleteElementCommand::DeleteElementCommand ( MapGraphics* mapToLink, Graphics* elt)
    :SimpleCommand(mapToLink, elt)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <DeleteElementCommand>" << endl;
#endif
} //----- Fin de DeleteElementCommand


DeleteElementCommand::~DeleteElementCommand ( )
// Algorithme :
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
