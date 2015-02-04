/*************************************************************************
                           LoadCommand  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par TOUZARD Loïc, GOUZI Gaëtan et GONZALEZ TOLEDO Gabriela
*************************************************************************/

//---------- Réalisation de la classe <LoadCommand> (fichier LoadCommand.h) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <vector>

//------------------------------------------------------ Include personnel
#include "LoadCommand.h"
#include "Command.h"


//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void LoadCommand::Execute()
// Mode d'emploi :
//  Execute tout les elements que contient la commande
// Contrat :
//
{
    vector<Command*>::iterator it;
    for(it=listCommands.begin(); it!=listCommands.end(); ++it)
    {
        (*it)->Execute();
    }
    whichList=IN_UNDO;

}

void LoadCommand::UnExecute()
// Mode d'emploi :
//  UnExecute tout les elements que contient la commande
// Contrat :
//
{
    vector<Command*>::iterator it;
    for(it=listCommands.begin(); it!=listCommands.end(); ++it)
    {
        (*it)->UnExecute();
    }
    whichList=IN_REDO;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
LoadCommand::LoadCommand ( const LoadCommand & unLoadCommand )
    :ComposedCommand(unLoadCommand)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <LoadCommand>" << endl;
#endif
} //----- Fin de LoadCommand (constructeur de copie)


LoadCommand::LoadCommand ( std::vector<Command*> listC )
    :ComposedCommand(listC)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <LoadCommand>" << endl;
#endif
} //----- Fin de LoadCommand


LoadCommand::~LoadCommand ( )
// Algorithme : Detruit la Command et libère potentiellement l'element graphique associé
//
{
    vector<Command*>::iterator it;
    for (it = listCommands.begin(); it != listCommands.end(); ++it)
    {
        delete *it;
    }
    listCommands.clear();
#ifdef MAP
    cout << "Appel au destructeur de <LoadCommand>" << endl;
#endif
} //----- Fin de ~LoadCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
