/*************************************************************************
                           Figure  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par TOUZARD Loïc, GOUZI Gaëtan et GONZALEZ TOLEDO Gabriela
*************************************************************************/

//---------- Interface de la classe <Figure> (fichier Figure.h) ------
#if ! defined ( FIGURE_H )
#define FIGURE_H
#include <sstream>
#include <vector>
#include "Point.h"
#include "Graphics.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
class Selection;

//------------------------------------------------------------------------
// Rôle de la classe <Figure>
// Une figure est un objet Graphics abstrait depuis lequel vont descendre toutes les formes
//
//------------------------------------------------------------------------

class Figure : public Graphics
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    Figure ( const Figure & unFigure ):Graphics(unFigure){}
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //


    Figure (Point figureOrigin, string graphicsName2, string graphicsCommandLine2)
    :Graphics(graphicsName2, graphicsCommandLine2), origin(figureOrigin){}
    // Mode d'emploi : Création d'une figure définie par son point d'origine, son nom et sa commande
    //
    // Contrat :
    //

    virtual ~Figure ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual bool IsInside(Point p1, Point p2) const;
    // Mode d'emploi :
    //	Vérifie que la figure appartient au rectangle formé par p1, p2
    //
    // Contrat :
    //	P1 = coin supérieur gauche du rectangle
    //	P2 = coin inférieur droit du rectangle
    //

    void AddSelect(Selection* const s);
    // Mode d'emploi : Ajoute une sélection au vecteur whoOwnsMe
    // Permet de savoir qu'une nouvelle sélection contient la figure
    // Contrat :
    //

    void EraseSelect(Selection* const s);
    // Mode d'emploi : Supprime une sélection du vecteur whoOwnsMe
    // Permet de savoir qu'une sélection dont faisait partie la figure a été détruite
    // Contrat :
    //
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées



    virtual string description() const =0;
    // Mode d'emploi : Renvoie la commande propre à chaque figure
    //
    // Contrat :
    //


    virtual void move(const long dx, const long dy)=0;
    // Mode d'emploi : Déplace la figure en ajoutant dx et dy à ses coordonnées
    //
    // Contrat :
    //

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

	Point origin; //Center pour un cercle, coin supérieur gauche pour un rectangle et le premier point pour une ligne/polyligne
    vector<Selection*> whoOwnsMe; //Liste de toutes les sélections qui contiennent la figure
    Point leftUpCorner; //Cooronnées du coin supérieur gauche du rectangle "fictif" dans lequel est inscrit la figure
    Point downRightCorner; //Cooronnées du coin inférieur droit du rectangle "fictif" dans lequel est inscrit la figure

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

friend class Selection;
//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Figure>

#endif // FIGURE_H
