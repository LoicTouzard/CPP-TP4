/*************************************************************************
                           Circle  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par Touzard Loïc et GOUZI Gaëtan
*************************************************************************/

//---------- Interface de la classe <Circle> (fichier Circle.h) ------
#if ! defined ( CIRCLE_H )
#define CIRCLE_H
#include "Figure.h"
#include "Selection.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Circle>
// Créé une figure de type Circle caractérisée par son rayon
//
//------------------------------------------------------------------------

class Circle : public Figure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Circle ( const Circle & unCircle );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Circle (long circleRadius, Point figureOrigin, string graphicsName, string graphicsCommandLine);
    // Mode d'emploi : Initialise le rectangle "fictif" dans lequel est inscrit le cercle
    //
    // Contrat :
    //

    virtual ~Circle ( );
    // Mode d'emploi : Supprime le cercle des sélections qui le contiennent
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

    string description();
    // Mode d'emploi : Renvoie la commande propre à cette figure
    //
    // Contrat :
    //

    void move(long dx, long dy);
    // Mode d'emploi : Déplace l'objet en ajoutant dx et dy à ses coordonnées
    //
    // Contrat :
    //


private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés

	long radius; //Rayon qui caractérise un cercle (en plus de son origine) >0

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Circle>

#endif // CIRCLE_H
