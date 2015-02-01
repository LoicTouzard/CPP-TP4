/*************************************************************************
                           Rectangle  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par Touzard Loïc et GOUZI Gaëtan
*************************************************************************/

//---------- Interface de la classe <Rectangle> (fichier Rectangle.h) ------
#if ! defined ( RECTANGLE_H )
#define RECTANGLE_H
#include "Figure.h"
#include "Point.h"
#include "Selection.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types


//------------------------------------------------------------------------
// Rôle de la classe <Rectangle>
// Crée une figure particulière : le rectangle
// Le rectangle est composée de deux points (origin et extremity)
// qui correspondent aux coin supérieur gauche et au coin inférieur droit
//------------------------------------------------------------------------

class Rectangle : public Figure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Rectangle ( const Rectangle & unRectangle );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Rectangle (Point recExtremity, Point figureOrigin, string graphicsName, string graphicsCommandLine);
    // Mode d'emploi :Création d'un rectangle définie par son point d'origine, son point d'extremité, son nom et sa commande
    // Origin correspond au premier point (le coin supérieur gauche) et extremity correspond au second point (le coin inférieur droit)
    // Initialise aussi le rectangle "fictif" dans lequel est inscrit le rectangle
    // Contrat :
    //

    virtual ~Rectangle ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

    string description();
    // Mode d'emploi :Renvoie la commande propre à chaque figure
    //
    // Contrat :
    //

    void move(long dx, long dy);
    // Mode d'emploi :Déplace la figure en ajoutant dx et dy à ses coordonnées
    //
    // Contrat :
    //


private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés

Point extremity; //Coin inférieur droit du rectangle (le coin supérieur gauche étant origin)

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Rectangle>

#endif // RECTANGLE_H
