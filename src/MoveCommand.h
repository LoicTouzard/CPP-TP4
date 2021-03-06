/*************************************************************************
                           MoveCommand  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par TOUZARD Loïc, GOUZI Gaëtan et GONZALEZ TOLEDO Gabriela
*************************************************************************/

//---------- Interface de la classe <MoveCommand> (fichier MoveCommand.h) ------
#if ! defined ( MOVECOMMAND_H )
#define MOVECOMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include "SimpleCommand.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef map<string, Graphics*> MapGraphics;

//------------------------------------------------------------------------
// Rôle de la classe <MoveCommand>
//
//
//------------------------------------------------------------------------

class MoveCommand : public SimpleCommand
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    virtual void Execute();
    // Mode d'emploi :
    //  Déplace de origin.x et origin.y le Graphics associé
    // Contrat :
    //

    virtual void UnExecute();
    // Mode d'emploi :
    //  Déplace de -origin.x et -origin.y le Graphics associé
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    MoveCommand ( const MoveCommand & unMoveCommand );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    MoveCommand ( MapGraphics* mapToLink, unordered_set<string>* hashToLink, Graphics* name, Point newOrigin );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~MoveCommand ( );
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
Point origin;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <MoveCommand>

#endif // MOVECOMMAND_H
