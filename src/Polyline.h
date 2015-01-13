/*************************************************************************
                           Polyline  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Polyline> (fichier Polyline.h) ------
#if ! defined ( POLYLINE_H )
#define POLYLINE_H
#include "Point.h"
using namespace std;
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Polyline>
//
//
//------------------------------------------------------------------------ 

class Polyline : public Figure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Polyline ( const Polyline & unPolyline );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Polyline (vector<Point> newPointList, Point figureOrigin, string graphicsName, string graphicsCommandLine)
		:Figure(figureOrigin, graphicsName, graphicsCommandLine), pointList(newPointList);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Polyline ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées


	virtual bool isInside(Point p1, Point p2);
    // Mode d'emploi :  
    //	Vérifie que le polyligne appartient au rectangle formé par p1, p2
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

vector<Point> pointList;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Polyline>

#endif // POLYLINE_H
