/*************************************************************************
                           Container  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par Touzard Loïc et GOUZI Gaëtan
*************************************************************************/

//---------- Interface de la classe <Container> (fichier Container.h) ------
#if ! defined ( CONTAINER_H )
#define CONTAINER_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
#include <vector>
#include <list>
#include "Graphics.h"
#include "Point.h"
#include "Command.h"

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

typedef map<string, Graphics*> MapGraphics;

//------------------------------------------------------------------------
// Rôle de la classe <Container>
//
//
//------------------------------------------------------------------------

class Container
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

typedef MapGraphics::iterator Graphics_iterator;
typedef MapGraphics::const_iterator Graphics_const_iterator;

//-------------------------------------------- Constructeurs - destructeur
    Container ( const Container & unContainer );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Container ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Container ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Graphics_iterator Graphics_begin(){ return listeGraphics.begin(); }
    Graphics_iterator Graphics_end(){ return listeGraphics.end(); }

    void List();
	// Mode d'emploi :
    //
    // Contrat :
    //

    void Clear();
	// Mode d'emploi :
    //
    // Contrat :
    //

    void Save(string nomFichier);
	// Mode d'emploi :
    //
    // Contrat :
    //

    void moveElement(string name, long dX, long dY);
	// Mode d'emploi :
    //
    // Contrat :
    //

    void Load(string nomFichier);
	// Mode d'emploi :
    //
    // Contrat :
    //

    void Delete(vector<string> listeNoms);
	// Mode d'emploi :
    //
    // Contrat :
    //

	void AddCircle(string name, long radius, long centerX, long centerY, string commande);
    // Mode d'emploi :
    //
    // Contrat :
    //

	void AddRectangle(string name, long coin1X, long coin1Y, long coin2X, long coin2Y, string entree);
    // Mode d'emploi :
    //
    // Contrat :
    //

	void AddLine(string name, long coin1X, long coin1Y, long coin2X, long coin2Y, string commande);
    // Mode d'emploi :
    //
    // Contrat :
    //

	void AddPolyline(string name, vector<Point> newPointList, Point origin, string commande);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AddSelection(string name, long coin1X, long coin1Y, long coin2X, long coin2Y, string commande);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Undo();
    // Mode d'emploi :
    //
    // Contrat :
    //

     void Redo();
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

    bool NomLibre(string name, MapGraphics* mapToAnalyse);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void insertCommand(Command* cmd);
    // Mode d'emploi :
    //
    // Contrat :
    //

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés


MapGraphics listeGraphics;
list<Command*> undoCommands;
list<Command*> redoCommands;


//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Container>

#endif // CONTAINER_H
