/*************************************************************************
                           Circle  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Circle> (fichier Circle.h) ------
#if ! defined ( CIRCLE_H )
#define CIRCLE_H
#include "Figure.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Circle>
//
//
//------------------------------------------------------------------------ 

class Circle : public Figure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Circle ( const Circle & unCircle );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Circle (long circleRadius, Point figureOrigin, string graphicsName, string graphicsCommandLine)
		:Figure(figureOrigin, graphicsName, graphicsCommandLine), radius(circleRadius);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Circle ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

	virtual bool isInside(Point p1, Point p2);
    // Mode d'emploi :  
    //	Vérifie que le rectangle courant appartient au rectangle formé par p1, p2
    //
    // Contrat : 
    //	P1 = coin supérieur gauche du rectangle
    //	P2 = coin inférieur droit du rectangle
    //


    virtual string description();
    // Mode d'emploi :  
    //
    // Contrat : 
    //
    
    virtual void move(long dx, long dy);
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

	long radius;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Circle>

#endif // CIRCLE_H
