/*************************************************************************
                           CreateCircleCommand  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <CreateCircleCommand> (fichier CreateCircleCommand.cpp}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CreateCircleCommand.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type CreateCircleCommand::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

    void CreateCircleCommand::execute()
    // Mode d'emploi :
    //
    // Contrat :
    //
    {
        //on insère directement l'élément pas de vérification à faire car le nom est forcément libre
        //de plus l'objet est déjà bien construit
        cout << "#il y a " << linkedMap->size() << "elements" << endl;
        cout << "#tentative d'ajout de " << element->GetName() << endl;
        linkedMap->insert(make_pair(element->GetName(), element));
        cout << "#il y a " << linkedMap->size() << "elements" << endl;
    }

    void CreateCircleCommand::unexecute()
    // Mode d'emploi :
    //
    // Contrat :
    //
    {
        cout << "#tentative de suppression de " << element->GetName() << endl;
        cout << "#il y a " << linkedMap->size() << "elements" << endl;
        //l'element est gardé en mémoire pour un futur execute plus rapide (pas de réallocation)
        linkedMap->erase(element->GetName());
        cout << "#il y a " << linkedMap->size() << "elements" << endl;
    }

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
CreateCircleCommand::CreateCircleCommand ( const CreateCircleCommand & unCreateCircleCommand ):SimpleCommand(unCreateCircleCommand)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CreateCircleCommand>" << endl;
#endif
} //----- Fin de CreateCircleCommand (constructeur de copie)


CreateCircleCommand::CreateCircleCommand ( MapGraphics* mapToLink, Graphics* elt, Point newOrigin )
    :SimpleCommand(mapToLink, elt, newOrigin)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CreateCircleCommand>" << endl;
#endif
} //----- Fin de CreateCircleCommand


CreateCircleCommand::~CreateCircleCommand ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CreateCircleCommand>" << endl;
#endif
} //----- Fin de ~CreateCircleCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
