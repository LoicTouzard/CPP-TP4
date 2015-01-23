/*************************************************************************
                           MoveCommand  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
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
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual void execute();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual void unexecute();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    MoveCommand ( const MoveCommand & unMoveCommand );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    MoveCommand ( MapGraphics* mapToLink, Graphics* name, Point newOrigin );
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

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <MoveCommand>

#endif // MOVECOMMAND_H
