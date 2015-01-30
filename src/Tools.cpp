/*************************************************************************
                           Tools  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par Touzard Loïc et GOUZI Gaëtan
*************************************************************************/

//---------- Réalisation de la classe <Tools> (fichier Tools.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>
#include <fstream>
//------------------------------------------------------ Include personnel
#include "Tools.h"


//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

int Tools::NombreEspaces(std::string s)
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


bool Tools::Separateur(std::string s)
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


std::string Tools::Decoupage(std::string s, int posSpace)
// Algotihme : On extrait la chaine de caractères à paritir du posSpace-ème espace
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
    return result;
}


bool Tools::TestFichierExiste(std::string nomFichier)
// Algorithme : Renvoie true si le fichier existe déjà
//
{
    std::ifstream fichierATester(nomFichier.c_str());
    if (fichierATester.good()){
        fichierATester.close();
        return true;
    }
    else {
        return false;
    }
} //----- Fin de TestFichierExiste


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
