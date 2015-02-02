/*************************************************************************
                           Container  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par TOUZARD Loïc, GOUZI Gaëtan et GONZALEZ TOLEDO Gabriela
*************************************************************************/

//---------- Interface de la classe <Container> (fichier Container.h) ------
#if ! defined ( CONTAINER_H )
#define CONTAINER_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
#include <vector>
#include <list>
#include "Graphics.h"
#include "Point.h"
#include "Command.h"

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

typedef map<string, Graphics*> MapGraphics;

//------------------------------------------------------------------------
// Rôle de la classe <Container>
// Le container est objet qui contient une liste de Graphics
// On peut 'assimiler à un espace dans lequels on manipule des objets Graphics
//------------------------------------------------------------------------

class Container
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

typedef MapGraphics::iterator Graphics_iterator;
typedef MapGraphics::const_iterator Graphics_const_iterator;

//-------------------------------------------- Constructeurs - destructeur
    Container ( const Container & unContainer );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Container ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Container ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Graphics_iterator Graphics_begin(){ return listeGraphics.begin(); }
    Graphics_iterator Graphics_end(){ return listeGraphics.end(); }

    void List();
	// Mode d'emploi : Affiche la commande de chaque Graphics
    //
    // Contrat :
    //

    void Clear();
	// Mode d'emploi : Vide le container de tous les Graphics
    //
    // Contrat :
    //

    void Save(string nomFichier);
	// Mode d'emploi : Sauvegarde tous les Graphics dans un fichier
    //
    // Contrat :
    //

    void moveElement(string name, long dX, long dY);
	// Mode d'emploi : Permet de déplacer un Graphics en ajoutant dX à sa coordonnée en X et dY à sa coordonnée en Y
    //
    // Contrat :
    //

    void Load(string nomFichier);
	// Mode d'emploi : Charge toutes les commandes présentent dans un fichier
    //
    // Contrat :
    //

    void Delete(vector<string> listeNoms);
	// Mode d'emploi : Permet de supprimer un ou plusieurs Graphics
    //
    // Contrat :
    //

	void AddCircle(string name, long radius, long centerX, long centerY, string commande);
    // Mode d'emploi : Ajoute un cercle qui s'appelle name au container (aux coordonnées centerX, centerY et de rayon radius)
    //
    // Contrat :
    //

	void AddRectangle(string name, long coin1X, long coin1Y, long coin2X, long coin2Y, string entree);
    // Mode d'emploi :Ajoute un rectangle qui s'appelle name au container
    // Coordonnées du coin supérieur droit (coin1X, coin1Y)
    // Coordonnées du coin inférieur gauche (coin2X, coin2Y)
    // Contrat :
    //

	void AddLine(string name, long coin1X, long coin1Y, long coin2X, long coin2Y, string commande);
    // Mode d'emploi : Ajoute une ligne qui s'appelle name au container
    // Coordonnées du coin supérieur droit (coin1X, coin1Y)
    // Coordonnées du coin inférieur gauche (coin2X, coin2Y)
    // Contrat :
    //

	void AddPolyline(string name, vector<Point> newPointList, Point origin, string commande);
    // Mode d'emploi : Ajoute une polyligne qui s'appelle name au container
    // La polyligne est une succession de lignes reliées entre elles
    // Contrat :
    //

    void AddSelection(string name, long coin1X, long coin1Y, long coin2X, long coin2Y, string commande);
    // Mode d'emploi : Ajoute une sélection qui s'appelle name au container
    // Coordonnées du coin supérieur droit (coin1X, coin1Y)
    // Coordonnées du coin inférieur gauche (coin2X, coin2Y)
    // Contrat :
    //

    void Undo();
    // Mode d'emploi : Annule la dernière commande
    //
    // Contrat :
    //

     void Redo();
    // Mode d'emploi : Re-éxécute la dernière commande annulée
    //
    // Contrat :
    //


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

    bool NomLibre(string name, MapGraphics* mapToAnalyse);
    // Mode d'emploi : Vérifie que le nom n'est pas déjà utilisé par un autre Graphics
    //
    // Contrat :
    //

    void insertCommand(Command* cmd);
    // Mode d'emploi :
    //
    // Contrat :
    //

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés


MapGraphics listeGraphics; //Map contenant tous les Graphics (figures et sélection)
//Clé = name
//Valeur = Graphics
list<Command*> undoCommands; //Liste des commandes que l'on peut annuler
list<Command*> redoCommands; //Liste des commandes que l'on peut ré-exécuter après les avoir annulé


//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Container>

#endif // CONTAINER_H
