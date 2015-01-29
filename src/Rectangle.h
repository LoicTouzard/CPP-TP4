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
#include "Selection.h"
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

    Rectangle (Point recExtremity, Point figureOrigin, string graphicsName, string graphicsCommandLine);
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
