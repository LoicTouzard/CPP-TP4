/*************************************************************************
                           DeleteCommand  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <DeleteCommand> (fichier DeleteCommand.h) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <vector>

//------------------------------------------------------ Include personnel
#include "DeleteCommand.h"
#include "Command.h"


//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type DeleteCommand::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void DeleteCommand::execute()
// Mode d'emploi :
//
// Contrat :
//
{
    vector<Command*>::iterator it;
    for(it=listCommands.begin(); it!=listCommands.end(); ++it)
    {
        (*it)->execute();
    }
    whichList=IN_UNDO;

}

void DeleteCommand::unexecute()
// Mode d'emploi :
//
// Contrat :
//
{
    vector<Command*>::iterator it;
    for(it=listCommands.begin(); it!=listCommands.end(); ++it)
    {
        (*it)->unexecute();
    }
    whichList=IN_REDO;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
DeleteCommand::DeleteCommand ( const DeleteCommand & unDeleteCommand )
    :ComposedCommand(unDeleteCommand)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <DeleteCommand>" << endl;
#endif
} //----- Fin de DeleteCommand (constructeur de copie)


DeleteCommand::DeleteCommand ( std::vector<Command*> listC )
    :ComposedCommand(listC)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <DeleteCommand>" << endl;
#endif
} //----- Fin de DeleteCommand


DeleteCommand::~DeleteCommand ( )
// Algorithme :
//
{
    vector<Command*>::iterator it;
    for (it = listCommands.begin(); it != listCommands.end(); ++it){
        delete *it;
    }
    listCommands.clear();
#ifdef MAP
    cout << "Appel au destructeur de <DeleteCommand>" << endl;
#endif
} //----- Fin de ~DeleteCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
