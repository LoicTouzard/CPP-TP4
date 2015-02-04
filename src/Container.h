/*************************************************************************
                           Container
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
#include <unordered_set>
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
// On peut l'assimiler à un espace dans lequel on manipule des objets Graphics
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

    void List() const;
	// Mode d'emploi : Affiche la commande de chaque Graphics
    //
    // Contrat :
    //

    void Clear();
	// Mode d'emploi : Vide le container de tous les Graphics
    //
    // Contrat :
    //

    void Save(const string nomFichier) const;
	// Mode d'emploi : Sauvegarde tous les Graphics dans un fichier
    //
    // Contrat :
    //

    void moveElement(const string name, const long dX, const long dY);
	// Mode d'emploi : Permet de déplacer un Graphics en ajoutant dX à sa coordonnée en X et dY à sa coordonnée en Y
    //
    // Contrat :
    //

    void Load(const string nomFichier);
	// Mode d'emploi : Charge toutes les commandes présentes dans un fichier
    //
    // Contrat :
    //

    void Delete(const vector<string> listeNoms);
	// Mode d'emploi : Permet de supprimer un ou plusieurs Graphics
    //
    // Contrat :
    //

	void AddCircle(const string name, const long radius, const long centerX, const long centerY, const string commande);
    // Mode d'emploi : Ajoute un cercle qui s'appelle name au container (aux coordonnées centerX, centerY et de rayon radius)
    //
    // Contrat :
    //

	void AddRectangle(const string name, const long coin1X, const long coin1Y, const long coin2X, const long coin2Y, const string entree);
    // Mode d'emploi :Ajoute un rectangle qui s'appelle name au container
    // Contrat :
    //

	void AddLine(const string name, const long coin1X, const long coin1Y, const long coin2X, const long coin2Y, const string commande);
    // Mode d'emploi : Ajoute une ligne qui s'appelle name au container
    // Contrat :
    //

	void AddPolyline(const string name, const vector<Point> newPointList, const Point origin, const string commande);
    // Mode d'emploi : Ajoute une polyligne qui s'appelle name au container
    // La polyligne est une succession de lignes reliées entre elles
    // Contrat :
    //

    void AddSelection(const string name, const long coin1X, const long coin1Y, const long coin2X, const long coin2Y, const string commande);
    // Mode d'emploi : Ajoute une sélection qui s'appelle name au container
    // Elle contiendra les elements situés dans la zone formés par ses points.
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

    void insertCommand(Command* const cmd);
    // Mode d'emploi : Insère une nouvelle commande dans la pile des UNDO et vide la pile des REDO
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
unordered_set<string> hashedName;
list<Command*> undoCommands; //Liste des commandes que l'on peut annuler
list<Command*> redoCommands; //Liste des commandes que l'on peut ré-exécuter après les avoir annulé


//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Container>

#endif // CONTAINER_H
