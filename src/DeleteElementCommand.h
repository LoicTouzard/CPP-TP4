/*************************************************************************
                           DeleteElementCommand  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par Touzard Loïc et GOUZI Gaëtan
*************************************************************************/

//---------- Interface de la classe <DeleteElementCommand> (fichier DeleteElementCommand.h) ------
#if ! defined ( DELETEELEMENTCOMMAND_H )
#define DELETEELEMENTCOMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include "SimpleCommand.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef map<string, Graphics*> MapGraphics;

//------------------------------------------------------------------------
// Rôle de la classe <DeleteElementCommand>
//
//
//------------------------------------------------------------------------

class DeleteElementCommand : public SimpleCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    virtual void Execute();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual void UnExecute();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    DeleteElementCommand ( const DeleteElementCommand & unDeleteElementCommand );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    DeleteElementCommand ( MapGraphics* mapToLink, Graphics* elt);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~DeleteElementCommand ( );
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

//----------------------------------------- Types dépendants de <DeleteElementCommand>

#endif // DELETEELEMENTCOMMAND_H
