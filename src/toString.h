/*************************************************************************
                           toString  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par Touzard Loïc et GOUZI Gaëtan
*************************************************************************/

#if ! defined ( TOSTRING_H )
#define TOSTRING_H

#include <iostream>
#include <string>
template <typename T>
	// Mode d'emploi :Convertir un entier en chaine de caractere
	//
	// Contrat :
	//
	string toString(T valeur)
	{
		ostringstream oss;
		oss<<valeur;
		return oss.str();
	}
#endif // TOSTRING_H
