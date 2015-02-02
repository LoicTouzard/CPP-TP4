/*************************************************************************
                           Graphics  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par TOUZARD Loïc, GOUZI Gaëtan et GONZALEZ TOLEDO Gabriela
*************************************************************************/

//---------- Interface de la classe <Graphics> (fichier Graphics.h) ------
#if ! defined ( GRAPHICS_H )
#define GRAPHICS_H
#include <string>
#include "Point.h"
//--------------------------------------------------- Interfaces utilisées
using namespace std;
//------------------------------------------------------------- Constantes

const short GRAPHICS_STATE_IN_DRAW = 0;
const short GRAPHICS_STATE_NOT_IN_DRAW = 1;

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Graphics>
// Classe définissant tout ce qui est commun à toutes les formes et sélections
// Les classes Figure et Selection sont héritées de Graphics
//
//------------------------------------------------------------------------

class Graphics
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs
    string GetName()
    {
        return this->name;
    }

    void SetInDraw(short inDraw){
        state = inDraw;
    }
//-------------------------------------------- Constructeurs - destructeur
    Graphics ( const Graphics & unGraphics );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //


    Graphics (string graphicsName, string graphicsCommandLine )
        :name(graphicsName), commandLine(graphicsCommandLine), state(GRAPHICS_STATE_IN_DRAW) {}
    // Mode d'emploi : Création d'un Graphics qui sera défini par son nom et sa commade
    //
    // Contrat :
    //

    virtual ~Graphics ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

	virtual void move(long dx, long dy)=0;
    // Mode d'emploi : Déplace le Graphics en ajoutant dx et dy à ses coordonnées
    //
    // Contrat :
    //

    virtual string description()=0;
    // Mode d'emploi : Renvoie la commande propre à chaque Graphics
    //
    // Contrat :
    //


private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

	string name; //Nom du Graphics
	string commandLine; //Commande permettant de créer le Graphics (tapée par l'utilisateur)
    short state;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies
    friend class Container;
    friend class MoveCommand;
//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Graphics>

#endif // GRAPHICS_H
