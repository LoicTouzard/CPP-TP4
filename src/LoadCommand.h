/*************************************************************************
                           LoadCommand  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <LoadCommand> (fichier LoadCommand.h) ------
#if ! defined ( LOADCOMMAND_H )
#define LOADCOMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include "ComposedCommand.h"
#include <vector>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LoadCommand>
//
//
//------------------------------------------------------------------------

class LoadCommand : public ComposedCommand
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
    LoadCommand ( const LoadCommand & unLoadCommand );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    LoadCommand ( std::vector<Command*> listC );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~LoadCommand ( );
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

//----------------------------------------- Types dépendants de <LoadCommand>

#endif // LOADCOMMAND_H