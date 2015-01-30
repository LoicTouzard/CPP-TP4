/*************************************************************************
                           Figure  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par Touzard Loïc et GOUZI Gaëtan
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
    Figure ( const Figure & unFigure ):Graphics(unFigure){}
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //


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

    virtual bool IsInside(Point p1, Point p2);
    // Mode d'emploi :
    //	Vérifie que la figure appartient au rectangle formé par p1, p2
    //
    // Contrat :
    //	P1 = coin supérieur gauche du rectangle
    //	P2 = coin inférieur droit du rectangle
    //

    void AddSelect(Selection* s);

    void EraseSelect(Selection* s);

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées



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
    vector<Selection*> whoOwnsMe;
	//Points facilitant le IsInside()
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
