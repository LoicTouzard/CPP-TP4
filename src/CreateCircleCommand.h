/*************************************************************************
                           CreateCircleCommand  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <CreateCircleCommand> (fichier CreateCircleCommand.h) ------
#if ! defined ( CREATECIRCLECOMMAND_H )
#define CREATECIRCLECOMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include "SimpleCommand.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef map<string, Graphics*> MapGraphics;

//------------------------------------------------------------------------
// Rôle de la classe <CreateCircleCommand>
//
//
//------------------------------------------------------------------------

class CreateCircleCommand : public SimpleCommand
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
    CreateCircleCommand ( const CreateCircleCommand & unCreateCircleCommand );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CreateCircleCommand ( MapGraphics* mapToLink, Graphics* name, Point newOrigin );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CreateCircleCommand ( );
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

//----------------------------------------- Types dépendants de <CreateCircleCommand>

#endif // CREATECIRCLECOMMAND_H
