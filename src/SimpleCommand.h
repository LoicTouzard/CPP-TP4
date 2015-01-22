/*************************************************************************
                           SimpleCommand  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <SimpleCommand> (fichier SimpleCommand.h) ------
#if ! defined ( SIMPLECOMMAND_H )
#define SIMPLECOMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include "Graphics.h"
#include "Point.h"
#include "Command.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <SimpleCommand>
//
//
//------------------------------------------------------------------------

class SimpleCommand : public Command
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
    SimpleCommand ( const SimpleCommand & unSimpleCommand );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    SimpleCommand ( Graphics* elt, Point newOrigin );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~SimpleCommand ( );
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
Graphics* element;
Point origin;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <SimpleCommand>

#endif // SIMPLECOMMAND_H
