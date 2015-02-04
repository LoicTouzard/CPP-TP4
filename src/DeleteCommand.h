/*************************************************************************
                           DeleteCommand
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par TOUZARD Loïc, GOUZI Gaëtan et GONZALEZ TOLEDO Gabriela
*************************************************************************/

//---------- Interface de la classe <DeleteCommand> (fichier ComposedCommand.h) ------
#if ! defined ( DELETECOMMAND_H )
#define DELETECOMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include "ComposedCommand.h"
#include <vector>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <DeleteCommand>
//
//
//------------------------------------------------------------------------

class DeleteCommand : public ComposedCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    virtual void Execute();
    // Mode d'emploi :
    //  Execute tout les elements que contient la commande
    // Contrat :
    //

    virtual void UnExecute();
    // Mode d'emploi :
    //  UnExecute tout les elements que contient la commande
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    DeleteCommand ( const DeleteCommand & unDeleteCommand );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    DeleteCommand ( std::vector<Command*> listC );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~DeleteCommand ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <DeleteCommand>

#endif // DELETECOMMAND_H
