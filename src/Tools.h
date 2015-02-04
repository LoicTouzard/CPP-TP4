/*************************************************************************
                           Tools  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par TOUZARD Loïc, GOUZI Gaëtan et GONZALEZ TOLEDO Gabriela
*************************************************************************/

//---------- Interface de la classe <Tools> (fichier Tools.h) ------
#if ! defined ( TOOLS_H )
#define TOOLS_H

#include <iostream>
#include <string>
#include <list>


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Tools>
// Classe où sont stockées toutes les méthodes qui permettent de gérer le traitement des commandes et des fichiers
// Tout est public et accessible depuis les autres classes
// Permet une meilleure visibilité
// Tout est mis ensemble pour être plus simple et facile d'accès
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



    static std::list<std::string> &Split(const std::string &s, std::list<std::string> &elems, char delim=' ');
    // Mode d'emploi : Renvoie une liste où chaque élément correspond à chaque mot de la chaine de caractères (séparation des mots par des délimiteurs)
    //  Cette version prend une list par référence en parametre et effectue ses ajouts de mots dans celle ci
    // Contrat :
    //
    static std::list<std::string> Split(const std::string &s, char delim=' ');
    // Mode d'emploi : Renvoie une liste où chaque élément correspond à chaque mot de la chaine de caractères (séparation des mots par des délimiteurs)
    //
    // Contrat :
    //


    static bool FileExists(const std::string nomFichier);
    // Mode d'emploi : Vérifie si le nom du fichier est déjà présent dans le répertoire courant
    //
    // Contrat :
    //
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
