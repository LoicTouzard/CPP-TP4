/*************************************************************************
                           LoadCommand  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par Touzard Loïc et GOUZI Gaëtan
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
// type LoadCommand::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void LoadCommand::Execute()
// Mode d'emploi :
//
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
//
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
// Algorithme :
//
{
    vector<Command*>::iterator it;
    for (it = listCommands.begin(); it != listCommands.end(); ++it){
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
