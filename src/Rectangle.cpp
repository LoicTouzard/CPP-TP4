/*************************************************************************
                           Rectangle  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par TOUZARD Loïc, GOUZI Gaëtan et GONZALEZ TOLEDO Gabriela
*************************************************************************/

//---------- Réalisation de la classe <Rectangle> (fichier Rectangle.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Rectangle.h"
#include "toString.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Rectangle::Rectangle ( const Rectangle & unRectangle ):Figure(unRectangle)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle (constructeur de copie)


Rectangle::Rectangle (Point recExtremity, Point figureOrigin, string graphicsName, string graphicsCommandLine)
    :Figure(figureOrigin, graphicsName, graphicsCommandLine), extremity(recExtremity)
// Algorithme : Constructeur qui permet de créer cette figure
// On initialise le rectangle "fictif" dans lequel sera contenu la figure
{
    leftUpCorner.x=(origin.x<extremity.x)?origin.x:extremity.x;
	leftUpCorner.y=(origin.y<extremity.y)?extremity.y:origin.y;

	downRightCorner.x=(origin.x<extremity.x)?extremity.x:origin.x;
	downRightCorner.y=(origin.y<extremity.y)?origin.y:extremity.y;
#ifdef MAP
    cout << "Appel au constructeur de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle*/


Rectangle::~Rectangle ( )
// Algorithme : Supprime tous les points caractéristiques de cette figure et supprime la figure de toutes les sélections dont elle faisait partie
// On ne delete pas l'objet car il peut potentiellement être rappelé  par un UNDO
// Si c'est le cas, il ne fait plus partie des sélections dans lequelles il était présent
{
    vector<Selection*>::iterator it;
    for(it=whoOwnsMe.begin(); it!=whoOwnsMe.end(); ++it){
        (*it)->EraseFigure(this);
    }
#ifdef MAP
    cout << "Appel au destructeur de <Rectangle>" << endl;
#endif
} //----- Fin de ~Rectangle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


string Rectangle::description()
// Algorithme : Renvoie la commande propore à cette figure
//
{
	return commandLine+"\r\n";

} //----- Fin de description

void Rectangle::move(long dx, long dy)
// Algorithme : Déplace tous les points caractéristiques de cette figure de dx et dy et met à jour la commande propre à cette figure
//
{
	origin.x += dx;
	origin.y += dy;
	extremity.x += dx;
	extremity.y += dy;

    leftUpCorner.x+=dx;
    leftUpCorner.y+=dy;
    downRightCorner.x+=dx;
    downRightCorner.y+=dy;

	commandLine="R "+name+" "+toString(origin.x)+" "+toString(origin.y)+" "+toString(extremity.x)+" "+toString(extremity.y);

} //----- Fin de move

//------------------------------------------------------- Méthodes privées
