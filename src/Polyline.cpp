/*************************************************************************
                           Polyline  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par Touzard Loïc et GOUZI Gaëtan
*************************************************************************/

//---------- Réalisation de la classe <Polyline> (fichier Polyline.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
//------------------------------------------------------ Include personnel
#include "Polyline.h"
#include "toString.h"
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Polyline::Polyline ( const Polyline & unPolyline ):Figure(unPolyline)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Polyline>" << endl;
#endif
} //----- Fin de Polyline (constructeur de copie)


Polyline::Polyline (vector<Point> newPointList, Point figureOrigin, string graphicsName, string graphicsCommandLine)
	:Figure(figureOrigin, graphicsName, graphicsCommandLine), pointList(newPointList)
// Algorithme : Constructeur qui permet de créer cette figure
// On initialise le rectangle "fictif" dans lequel sera contenu la figure
{

    vector<Point>::iterator it;
    leftUpCorner.x=pointList[0].x;
    leftUpCorner.y=pointList[0].y;
    downRightCorner.x=pointList[0].x;
    downRightCorner.y=pointList[0].y;
    for(it=pointList.begin(); it!=pointList.end(); ++it)
    {
        if(it->x > downRightCorner.x)
        {
            downRightCorner.x=it->x;
        }
        else if(it->x < leftUpCorner.x)
        {
            leftUpCorner.x=it->x;
        }

        if(it->y > leftUpCorner.y)
        {
            leftUpCorner.y=it->y;
        }
        else if(it->y < downRightCorner.y)
        {
            downRightCorner.y=it->y;
        }
    }

#ifdef MAP
    cout << "Appel au constructeur de <Polyline>" << endl;
#endif
} //----- Fin de Polyline


Polyline::~Polyline ( )
// Algorithme : Supprime tous les points caractéristiques de cette figure et supprime la figure de toutes les sélections dont elle faisait partie
// On ne delete pas l'objet car il peut potentiellement être rappelé  par un UNDO
// Si c'est le cas, il ne fait plus partie des sélections dans lequelles il était présent
{
    vector<Selection*>::iterator it;
    for(it=whoOwnsMe.begin(); it!=whoOwnsMe.end(); ++it){
        (*it)->EraseFigure(this);
    }

#ifdef MAP
    cout << "Appel au destructeur de <Polyline>" << endl;
#endif
} //----- Fin de ~Polyline


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

string Polyline::description()
// Algorithme : Renvoie la commande propore à cette figure
//
{
	return commandLine+"\r\n";

} //----- Fin de description

void Polyline::move(long dx, long dy)
// Algorithme : Déplace tous les points caractéristiques de cette figure de dx et dy et met à jour la commande propre à cette figure
//
{

	vector<Point>::iterator it;
	origin.x += dx;
	origin.y += dy;

    leftUpCorner.x+=dx;
    leftUpCorner.y+=dy;
    downRightCorner.x+=dx;
    downRightCorner.y+=dy;

	commandLine="PL "+name+" "+toString(origin.x)+" "+toString(origin.y);
	for(it = pointList.begin(); it!=pointList.end(); ++it){
		it->x += dx;
		it->y += dy;
		commandLine +=" "+toString(it->x)+" "+toString(it->y);
	}

} //----- Fin de move


//------------------------------------------------------- Méthodes privées
