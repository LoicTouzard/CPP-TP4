/*************************************************************************
                           Tools  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par TOUZARD Loïc, GOUZI Gaëtan et GONZALEZ TOLEDO Gabriela
*************************************************************************/

//---------- Réalisation de la classe <Tools> (fichier Tools.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
//------------------------------------------------------ Include personnel
#include "Tools.h"


//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


std::list<std::string> &Tools::Split(const std::string &s, std::list<std::string> &elems, char delim)
// Algorithme : Renvoie une liste où chaque élément correspond à chaque mot de la chaine de caractères (séparation des mots par des délimiteurs)
//  Cette version prend une list par référence en parametre et effectue ses ajouts de mots dans celle ci
{
    std::stringstream ss(s);    //creation d'une stringstream a partir de la string a split
    std::string item;
    while (std::getline(ss, item, delim))   //obtention des mot avec le séparateur
    {
        elems.push_back(item);
    }
    return elems;
}


std::list<std::string> Tools::Split(const std::string &s, char delim)
// Algorithme : Renvoie une liste contenant tous les mots de la chaine de caractères séparés par un délimiteur
//
{
    std::list<std::string> elems;
    Tools::Split(s, elems, delim);
    return elems;
}



bool Tools::FileExists(const std::string filename)
// Algorithme : Renvoie true si le fichier existe déjà
//
{
    std::ifstream file(filename.c_str());
    if (file.good()){
        file.close();
        return true;
    }
    else {
        return false;
    }
} //----- Fin de FileExists


//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
Tools::Tools ( const Tools & unTools )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Tools>" << endl;
#endif
} //----- Fin de Tools (constructeur de copie)


Tools::Tools ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Tools>" << endl;
#endif
} //----- Fin de Tools


Tools::~Tools ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Tools>" << endl;
#endif
} //----- Fin de ~Tools


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
