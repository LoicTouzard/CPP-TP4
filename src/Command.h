/*************************************************************************
                           Comand  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par TOUZARD Loïc, GOUZI Gaëtan et GONZALEZ TOLEDO Gabriela
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
// Permet de définir si la figure caractérisée par cette commande se situe dans la pile des UNDO ou dans la pile des REDO
//
//------------------------------------------------------------------------

class Command
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    virtual void Execute()=0;
    // Mode d'emploi :
    //  Fait l'action associée à la commande qui l'implémentera.
    //  Virtuelle pure pour obliger ses descendants à implémenter cette methode
    // Contrat :
    //

    virtual void UnExecute()=0;
    // Mode d'emploi :
    //  Defait l'action associée à la commande qui l'implémentera.
    //  Virtuelle pure pour obliger ses descendants à implémenter cette methode
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
short whichList; //0=Pile UNDO 1=Pile REDO

// constante de classe, valeurs pour whichList
static const short IN_UNDO=0;
static const short IN_REDO=1;

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
