/*************************************************************************
                           CreateElementCommand  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par TOUZARD Loïc, GOUZI Gaëtan et GONZALEZ TOLEDO Gabriela
*************************************************************************/

//---------- Interface de la classe <CreateElementCommand> (fichier CreateElementCommand.h) ------
#if ! defined ( CREATEELEMENTCOMMAND_H )
#define CREATEELEMENTCOMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include "SimpleCommand.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef map<string, Graphics*> MapGraphics;

//------------------------------------------------------------------------
// Rôle de la classe <CreateElementCommand>
//
//
//------------------------------------------------------------------------

class CreateElementCommand : public SimpleCommand
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
    CreateElementCommand ( const CreateElementCommand & unCreateElementCommand );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CreateElementCommand ( MapGraphics* mapToLink, Graphics* name);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CreateElementCommand ( );
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

//----------------------------------------- Types dépendants de <CreateElementCommand>

#endif // CREATEELEMENTCOMMAND_H
