/*************************************************************************
                           Rectangle  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Rectangle> (fichier Rectangle.h) ------
#if ! defined ( RECTANGLE_H )
#define RECTANGLE_H
#include "Figure.h"
#include "Point.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types


//------------------------------------------------------------------------
// Rôle de la classe <Rectangle>
//
//
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

    Rectangle (Point recExtremity, Point figureOrigin, string graphicsName, string graphicsCommandLine)
    :Figure(figureOrigin, graphicsName, graphicsCommandLine), extremity(recExtremity){}
    // Mode d'emploi :
    //
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

	bool isInside(Point p1, Point p2);
    // Mode d'emploi :
    //	Vérifie que le rectangle courant appartient au rectangle formé par p1, p2
    //
    // Contrat :
    //	P1 = coin supérieur gauche du rectangle
    //	P2 = coin inférieur droit du rectangle
    //

    string description();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void move(long dx, long dy);
    // Mode d'emploi :
    //
    // Contrat :
    //


private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés

Point extremity;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Rectangle>

#endif // RECTANGLE_H
