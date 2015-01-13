/*************************************************************************
                           Graphics  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Graphics> (fichier Graphics.h) ------
#if ! defined ( GRAPHICS_H )
#define GRAPHICS_H
#include <string.h>
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Graphics>
//
//
//------------------------------------------------------------------------

class Graphics
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Graphics ( const Graphics & unGraphics );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Graphics (string graphicsName, string graphicsCommandLine )
		:name(graphicsName), commandLine(graphicsCommandLine){}
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Graphics ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

	virtual void move(long dx, long dy)=0;
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual string description()=0;
    // Mode d'emploi :
    //
    // Contrat :
    //



private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

	string name;
	string commandLine;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Graphics>

#endif // GRAPHICS_H
