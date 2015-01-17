/*************************************************************************
                           Polyline  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Polyline> (fichier Polyline.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
//------------------------------------------------------ Include personnel
#include "Polyline.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Polyline::Polyline ( const Polyline & unPolyline )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Polyline>" << endl;
#endif
} //----- Fin de Polyline (constructeur de copie)


/*Polyline::Polyline (vector<Point> newPointList, Point figureOrigin, string graphicsName, string graphicsCommandLine)
// Algorithme :
//
{

name=graphicsName;
commandLine=graphicsCommandLine;
origin=figureOrigin;
pointList=newPointList;
#ifdef MAP
    cout << "Appel au constructeur de <Polyline>" << endl;
#endif
} //----- Fin de Polyline*/


Polyline::~Polyline ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Polyline>" << endl;
#endif
} //----- Fin de ~Polyline


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
bool Polyline::isInside(Point p1, Point p2)
// Algorithme :
//
{


	if( !(p1.x <=origin.x) ||
		!(p2.x >=origin.x) ||
		!(p1.y >=origin.y) ||
		!(p2.y <=origin.y) )
	{
		return false;
	}

	/*vector<Point>::iterator it;
	for(it = pointList.begin(); it!=pointList.end(); ++it){
		if( !(p1.x <=pointList[it].x) ||
			!(p2.x >=pointList[it].x) ||
			!(p1.y >=pointList[it].y) ||
			!(p2.y <=pointList[it].y) )
		{
			return false;
		}
	}
	return true;*/

} //----- Fin de isInside

string Polyline::description()
// Algorithme :
//
{
	return commandLine;

} //----- Fin de description

void Polyline::move(long dx, long dy)
// Algorithme :
//
{

	/*vector<Point>::iterator it;
	origin.x += dx;
	origin.y += dy;
	commandLine="PL "+name+" "+Long_to_string(origin.x)+" "+Long_to_string(origin.y);
	for(it = pointList.begin(); it!=pointList.end(); ++it){
		pointList[it].x += dx;
		pointList[it].y += dy;
		commandLIne +=" "+Long_to_string(pointList[it].x)+" "+Long_to_string(pointList[it].y);
	}*/

} //----- Fin de move


//------------------------------------------------------- Méthodes privées