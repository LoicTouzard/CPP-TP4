/*************************************************************************
                           Selection  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
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

    Selection (vector <Figure*> newFigureList, Point p1, Point p2, string graphicsName, string graphicsCommandLine)
    :Graphics(graphicsName, graphicsCommandLine), figureList(newFigureList), coinGauche(p1), coinDroit(p2){}
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Selection ( );
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

vector<Figure*> figureList;
Point coinGauche;
Point coinDroit;


private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Selection>

#endif // SELECTION_H
