/*************************************************************************
                           Polyline  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par Touzard Loïc et GOUZI Gaëtan
*************************************************************************/

//---------- Interface de la classe <Polyline> (fichier Polyline.h) ------
#if ! defined ( POLYLINE_H )
#define POLYLINE_H
#include "Point.h"
#include "Figure.h"
#include "Selection.h"
#include <vector>
using namespace std;
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Polyline>
// Crée une figure particulière : la polyligne
// La polyligne est composée de plusieurs ligne (donc de plusieurs points)
//
//------------------------------------------------------------------------

class Polyline : public Figure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Polyline ( const Polyline & unPolyline );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Polyline (vector<Point> newPointList, Point figureOrigin, string graphicsName, string graphicsCommandLine);
    // Mode d'emploi :Création d'une polyligne définie par son point d'origine, l'ensemble de ses points, son nom et sa commande
    // Origin correspond au premier point et les autres points sont stockés dans le vector
    // Initialise aussi le rectangle "fictif" dans lequel est inscrit la polyligne
    // Contrat :
    //

    virtual ~Polyline ( );
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

vector<Point> pointList; //Liste de tous les points composant la polyligne sauf le premier (origin)

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Polyline>

#endif // POLYLINE_H
