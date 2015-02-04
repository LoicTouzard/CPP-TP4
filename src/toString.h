/*************************************************************************
                           toString  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par TOUZARD Loïc, GOUZI Gaëtan et GONZALEZ TOLEDO Gabriela
*************************************************************************/

#if ! defined ( TOSTRING_H )
#define TOSTRING_H

#include <iostream>
#include <sstream>
#include <string>
template <typename T>
	// Mode d'emploi :Convertir un objet en chaine de caractere
	//
	// Contrat :
	//  Cette classe doit surcharger l'opérateur <<
	string toString(T valeur)
	{
		ostringstream oss;
		oss<<valeur;
		return oss.str();
	}
#endif // TOSTRING_H
