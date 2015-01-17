/*************************************************************************
                           Line  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Line> (fichier Line.h) ------
#if ! defined ( LINE_X )
#define LINE_X
#include "Point.h"
#include "Figure.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Line>
//
//
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

    Line (Point lineExtremity, Point figureOrigin, string graphicsName, string graphicsCommandLine)
    :Figure(figureOrigin, graphicsName, graphicsCommandLine), extremity(lineExtremity){}
    // Mode d'emploi :
    //
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

	bool isInside(Point p1, Point p2);
    // Mode d'emploi :
    //	Vérifie que la ligne appartient au rectangle formé par p1, p2
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

//----------------------------------------- Types dépendants de <Line>

#endif // LINE_X
