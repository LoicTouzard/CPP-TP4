/*************************************************************************
                           SimpleCommand  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par TOUZARD Loïc, GOUZI Gaëtan et GONZALEZ TOLEDO Gabriela
*************************************************************************/

//---------- Interface de la classe <SimpleCommand> (fichier SimpleCommand.h) ------
#if ! defined ( SIMPLECOMMAND_H )
#define SIMPLECOMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <string>
#include <unordered_set>
#include "Graphics.h"
#include "Point.h"
#include "Command.h"


//------------------------------------------------------------- Constantes

typedef map<string, Graphics*> MapGraphics;
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


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    SimpleCommand ( const SimpleCommand & unSimpleCommand );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    SimpleCommand ( MapGraphics* mapToLink, unordered_set<string>* hashToLink, Graphics* elt);
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
MapGraphics* linkedMap; // map cible pour les insertions et suppressions
unordered_set<string>* linkedHash;  // Table de Hash cible pour les insertions et suppressions
Graphics* element;  // Element cible de la commande, pourra etre enlevé/ajouté de la map/hashTable ou move

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <SimpleCommand>

#endif // SIMPLECOMMAND_H
