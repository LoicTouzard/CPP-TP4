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


    static int NombreEspaces(std::string s);
    // Mode d'emploi : Compte le nombre d'espaces dans une chaine de caractères
    //
    // Contrat :
    //

    static bool Separateur(std::string s);
    // Mode d'emploi :Vérifie si la chaine de caractères contient des espaces
    //
    // Contrat :
    //

    static std::string Decoupage(std::string s, int posSpace);
    // Mode d'emploi : Récupère la chaine de caractères comprise entre deux espaces consécutifs
    // On passe en paramètre le numéro du premier espace à partir duquel on commence à récupérer
    // la chaine de caractères et on s'arrête au prochain espace
    //
    // Contrat :
    //

    static bool TestFichierExiste(std::string nomFichier);
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
