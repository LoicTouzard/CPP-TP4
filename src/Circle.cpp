/*************************************************************************
                           Circle  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par Touzard Loïc et GOUZI Gaëtan
*************************************************************************/

//---------- Réalisation de la classe <Circle> (fichier Circle.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Circle.h"
#include "toString.h"
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés

//----------------------------------------------------------------- PUBLIC

//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Circle::Circle ( const Circle & unCircle ):Figure(unCircle)
// Algorithme : Constructeur par copie qui permet de créer cette figure
// On initialise le rectangle "fictif" dans lequel sera contenu la figure
{
    	leftUpCorner.x=origin.x-radius;
        leftUpCorner.y=origin.y+radius;
        downRightCorner.x=origin.x+radius;
        downRightCorner.y=origin.y-radius;
#ifdef MAP
    cout << "Appel au constructeur de copie de <Circle>" << endl;
#endif
} //----- Fin de Circle (constructeur de copie)


Circle::Circle (long circleRadius, Point figureOrigin, string graphicsName, string graphicsCommandLine)
		:Figure(figureOrigin, graphicsName, graphicsCommandLine), radius(circleRadius)
// Algorithme : Constructeur qui permet de créer cette figure
// On initialise le rectangle "fictif" dans lequel sera contenu la figure
{
        leftUpCorner.x=origin.x-radius;
        leftUpCorner.y=origin.y+radius;
        downRightCorner.x=origin.x+radius;
        downRightCorner.y=origin.y-radius;
#ifdef MAP
    cout << "Appel au constructeur de <Circle>" << endl;
#endif
} //----- Fin de Circle


Circle::~Circle ( )
// Algorithme : Supprime tous les points caractéristiques de cette figure et supprime la figure de toutes les sélections dont elle faisait partie
// On ne delete pas l'objet car il peut potentiellement être rappelé  par un UNDO
// Si c'est le cas, il ne fait plus partie des sélections dans lequelles il était présent
{
    vector<Selection*>::iterator it;
    for(it=whoOwnsMe.begin(); it!=whoOwnsMe.end(); ++it){
        (*it)->EraseFigure(this);
    }
#ifdef MAP
    cout << "Appel au destructeur de <Circle>" << endl;
#endif
} //----- Fin de ~Circle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


string Circle::description()
// Algorithme : Renvoie la commande propore à cette figure
//
{
	return commandLine+"\r\n";

} //----- Fin de description

void Circle::move(long dx, long dy)
// Algorithme : Déplace tous les points caractéristiques de cette figure de dx et dy et met à jour la commande propre à cette figure
//
{
	origin.x += dx;
	origin.y += dy;

    leftUpCorner.x+=dx;
    leftUpCorner.y+=dy;
    downRightCorner.x+=dx;
    downRightCorner.y+=dy;

	commandLine="C "+name+" "+toString(origin.x)+" "+toString(origin.y)+" "+toString(radius);

} //----- Fin de move
//------------------------------------------------------- Méthodes privées
