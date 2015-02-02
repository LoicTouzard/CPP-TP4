/*************************************************************************
                           Line  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par TOUZARD Loïc, GOUZI Gaëtan et GONZALEZ TOLEDO Gabriela
*************************************************************************/

//---------- Interface de la classe <Line> (fichier Line.h) ------
#if ! defined ( LINE_X )
#define LINE_X
#include "Point.h"
#include "Figure.h"
#include "Selection.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Line>
// Crée une figure particulière : la ligne
// La ligne est composée de deux points (origin et extremity)
//------------------------------------------------------------------------

class Line : public Figure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Line ( const Line & unLine );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Line (Point lineExtremity, Point figureOrigin, string graphicsName, string graphicsCommandLine);
    // Mode d'emploi :Création d'une ligne définie par son point d'origine, son point d'extremité, son nom et sa commande
    // Origin correspond au premier point et extremity correspond au second point
    // Initialise aussi le rectangle "fictif" dans lequel est inscrit la ligne
    // Contrat :
    //

    virtual ~Line ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

    string description();
    // Mode d'emploi : Renvoie la commande propre à chaque figure
    //
    // Contrat :
    //

    void move(long dx, long dy);
    // Mode d'emploi : Déplace la figure en ajoutant dx et dy à ses coordonnées
    //
    // Contrat :
    //

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés

Point extremity; //Dernier point de la ligne (le premier étant origin)
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Line>

#endif // LINE_X
