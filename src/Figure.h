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

    Figure (Point figureOrigin, string graphicsName, string graphicsCommandLine)
		:Graphics(graphicsName, graphicsCommandLine), origin(figureOrigin){}
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

	virtual bool isInside(Point p1, Point p2)=0;
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


	template <typename T>
	// Mode d'emploi :Convertir un entier en chaine de caractere
	//
	// Contrat :
	//
	string Long_to_string(T valeur)
	{
		ostringstream oss;
		oss<<valeur;
		return oss.str();
	}

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

	Point origin;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Figure>

#endif // FIGURE_H
