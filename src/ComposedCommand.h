/*************************************************************************
                           ComposedCommand  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par TOUZARD Loïc, GOUZI Gaëtan et GONZALEZ TOLEDO Gabriela
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

    virtual void Execute()=0;
    // Mode d'emploi :
    //  Fait l'action associée à la commande qui l'implémentera. Devra executer chacunes de ses commandes.
    //  Virtuelle pure pour obliger ses descendants à implémenter cette methode
    // Contrat :
    //

    virtual void UnExecute()=0;
    // Mode d'emploi :
    //  Defait l'action associée à la commande qui l'implémentera. Devra defaire chacunes de ses commandes.
    //  Virtuelle pure pour obliger ses descendants à implémenter cette methode
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

std::vector<Command*> listCommands; // Vecteur contenant d'autres commandes.
// Permet à cette classe d'être composée de plusieurs Command mais de n'être toujours considérée comme une seule Commande.

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
