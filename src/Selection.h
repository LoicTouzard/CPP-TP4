/*************************************************************************
                           Selection  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par TOUZARD Loïc, GOUZI Gaëtan et GONZALEZ TOLEDO Gabriela
*************************************************************************/

//---------- Interface de la classe <Selection> (fichier Selection.h) ------
#if ! defined ( SELECTION_H )
#define SELECTION_H
#include "Figure.h"
#include <vector>
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Selection>
//
//
//------------------------------------------------------------------------

class Selection : public Graphics
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Selection ( const Selection & unSelection );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Selection (vector <Figure*> newFigureList, Point p1, Point p2, string graphicsName, string graphicsCommandLine);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Selection ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    vector<Figure*>* getElements(){
        return &figureList;
    }

    void EraseFigure(Figure* f);

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


private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

Point origin;
Point extremity;
vector<Figure*> figureList;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Selection>

#endif // SELECTION_H
