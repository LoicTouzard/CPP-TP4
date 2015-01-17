/*************************************************************************
                           Container  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Container> (fichier Container.h) ------
#if ! defined ( CONTAINER_H )
#define CONTAINER_H

//--------------------------------------------------- Interfaces utilisées
#include <string.h>
#include <map>
#include <vector>
#include "Graphics.h"
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//typedef map<string, Graphics> MapGraphics;
//typedef map<string, Figure> MapFigure;

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

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

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

    void Save();
	// Mode d'emploi :
    //
    // Contrat :
    //

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés


//MapGraphics GraphicsList;
vector<Graphics*> *listeGraphics;


//---------------------------------------------------------- Classes amies
friend int main();
friend bool NomLibre(string s);
//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Container>

#endif // CONTAINER_H