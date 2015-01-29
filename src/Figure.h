/*************************************************************************
                           Figure  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Figure> (fichier Figure.h) ------
#if ! defined ( FIGURE_H )
#define FIGURE_H
#include <sstream>
#include "Point.h"
#include "Graphics.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Figure>
//
//
//------------------------------------------------------------------------

class Figure : public Graphics
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    Figure ( const Figure & unFigure );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Figure ( );

    Figure (Point figureOrigin, string graphicsName2, string graphicsCommandLine2)
    :Graphics(graphicsName2, graphicsCommandLine2), origin(figureOrigin){}
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Figure ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

	virtual bool isInside(Point p1, Point p2);
    // Mode d'emploi :
    //	Vérifie que la figure appartient au rectangle formé par p1, p2
    //
    // Contrat :
    //	P1 = coin supérieur gauche du rectangle
    //	P2 = coin inférieur droit du rectangle
    //

    virtual string description()=0;
    // Mode d'emploi :
    //
    // Contrat :
    //


    virtual void move(long dx, long dy)=0;
    // Mode d'emploi :
    //
    // Contrat :
    //

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

	Point origin;

	//Points facilitant le isInside()
    Point leftUpCorner;
    Point downRightCorner;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies
friend class Selection;
//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Figure>

#endif // FIGURE_H
