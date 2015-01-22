/*************************************************************************
                           Comand  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Command> (fichier Command.h) ------
#if ! defined ( COMMAND_H )
#define COMMAND_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Command>
//
//
//------------------------------------------------------------------------

class Command
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

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

//-------------------------------------------- Constructeurs - destructeur
    Command ( const Command & uneCommand );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Command ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Command ( );
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

//----------------------------------------- Types dépendants de <Command>

#endif // COMMAND_H
