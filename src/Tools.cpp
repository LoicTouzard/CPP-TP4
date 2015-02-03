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

int Tools::NombreEspaces(const std::string s)
// Algorithme : Compte le nombre d'espaces dans un string (utile pour savoir si le format d'entrée est respecté)
//
{
    int nbEspaces=0;
    for(unsigned int i=0; i<s.length()-1; i++){
        if(s[i]==' '){
            nbEspaces++;
        }
    }
    return nbEspaces;
}


bool Tools::Separateur(const std::string s)
// Algorithme : Renvoie true si le nom de la figure ne contient pas de séparateur
//
{
    if(s.find(" ")==std::string::npos){
        return false;
    }
    else{
        return true;
    }
}

std::list<std::string> &Tools::Split(const std::string &s, std::list<std::string> &elems, char delim) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
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

std::string Tools::Decoupage(std::string s, int posSpace)
// Algorithme : On extrait la chaine de caractères à contenue entre deux espaces consécutifs
//
{
    unsigned int i;
    int n=0;
    std::string result;
    int *space=new int[s.length()];
    for(i=0; i<s.length();i++){
            if(s[i]==' '){
                space[n]=i;
                n++;
            }
    }

    for(i=space[posSpace-1]+1; i<s.length();i++){
        if(s[i]!=' '){
              result=result+s[i];
        }
        else if(s[i]==' '){
            break;
        }
    }
    delete space;
    return result;
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
