/*************************************************************************
                           Tools  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par Touzard Loïc et GOUZI Gaëtan
*************************************************************************/

//---------- Interface de la classe <Tools> (fichier Tools.h) ------
#if ! defined ( TOOLS_H )
#define TOOLS_H

#include <iostream>
#include <string>


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Tools>
//
//
//------------------------------------------------------------------------

class Tools
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Tools ( const Tools & unTools );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Tools ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Tools ( );
    // Mode d'emploi :
    //
    // Contrat :
    //


    static int NombreEspaces(std::string s);


    static bool Separateur(std::string s);


    static std::string Decoupage(std::string s, int posSpace);


    static bool TestFichierExiste(std::string nomFichier);

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Tools>

#endif // TOOLS_H
