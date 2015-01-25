/*************************************************************************
                           ComposedCommand  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <ComposedCommand> (fichier ComposedCOmmand.h) ------
#if ! defined ( COMPOSEDCOMMAND_H )
#define COMPOSEDCOMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include "Command.h"
#include <vector>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ComposedCommand>
//
//
//------------------------------------------------------------------------

class ComposedCommand : public Command
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual void execute()=0;
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual void unexecute()=0;
    // Mode d'emploi :
    //
    // Contrat :
    //



//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    ComposedCommand ( const ComposedCommand & unComposedCommand );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ComposedCommand ( std::vector<Command*> listC );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ComposedCommand ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

std::vector<Command*> listCommands;

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

//----------------------------------------- Types dépendants de <ComposedCommand>

#endif // COMPOSEDCOMMAND_H