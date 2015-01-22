/*************************************************************************
                           ComposedCommand  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <ComposedCommand> (fichier ComposedCommand.h) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ComposedCommand.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type ComposedCommand::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
ComposedCommand::ComposedCommand ( const ComposedCommand & unComposedCommand )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ComposedCommand>" << endl;
#endif
} //----- Fin de ComposedCommand (constructeur de copie)


ComposedCommand::ComposedCommand ( std::vector<Command*> listC )
    :listCommands(listC)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ComposedCommand>" << endl;
#endif
} //----- Fin de ComposedCommand


ComposedCommand::~ComposedCommand ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ComposedCommand>" << endl;
#endif
} //----- Fin de ~ComposedCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
