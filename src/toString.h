/*************************************************************************
                           toString  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Figure> (fichier Figure.h) ------
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
