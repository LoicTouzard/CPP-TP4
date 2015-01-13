/*************************************************************************
                           Selection  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Selection> (fichier Selection.h) ------
#if ! defined ( SELECTION_H )
#define SELECTION_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Selection>
//
//
//------------------------------------------------------------------------ 

class Selection : public Graphics
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Selection ( const Selection & unSelection );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Selection (vector<Figure*> newFigureLIst, Point figureOrigin, string graphicsName, string graphicsCommandLine)
		:Figure(figureOrigin, graphicsName, graphicsCommandLine), figureList(newFigureLIst);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Selection ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

    virtual bool description();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual void move(long dx, long dy);
    // Mode d'emploi :
    //
    // Contrat :
    //

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

vector<Figure*> figureList;


private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Selection>

#endif // SELECTION_H
