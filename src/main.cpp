#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "Point.h"
#include "Container.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Selection.h"
#include "Polyline.h"
#include "Line.h"
using namespace std;

	int NombreEspaces(string s);
    bool Separateur(string s);
    string Decoupage(string s, int posSpace);
    bool TestFichierExiste(string nomFichier);

	int main(){
		Container espace; //Espace qui contient toutes les figures et selections
        string entree;
        getline(cin,entree);

        while(entree.substr(0,4)!="EXIT"){

        if (entree.substr(0,4)=="LIST") {
			//Code pour afficher tous les descripteurs d'objets
			espace.List();
            //Fin du code pour afficher tous les descripteurs d'objets
        }

        else if (entree.substr(0,4)=="UNDO") {
            //Code pour UNDO
            espace.Undo();
            //Fin du code pour UNDO
        }

        else if (entree.substr(0,4)=="REDO") {
            //Code pour REDO
            espace.Redo();
            //Fin du code pour REDO
        }

        else if (entree.substr(0,4)=="LOAD") {
            //Code pour LOAD
            if(NombreEspaces(entree)==1){
                string nomFichier;
                nomFichier=Decoupage(entree,1);
            	if(!TestFichierExiste(nomFichier))
            	{
                    cout<<"ERR"<<endl;
                    cout<<"#can't find "<<nomFichier<<endl;
                }
                else
                {
					espace.Load(nomFichier);
					cout<<"OK"<<endl;
                }
			}
			else{
                cout<<"ERR"<<endl;
                cout<<"#invalid parameters"<<endl;
            }
        }

        else if (entree.substr(0,4)=="SAVE") {
            //Code pour SAVE
            if(NombreEspaces(entree)==1){
                string nomFichier;
                nomFichier=Decoupage(entree,1);
                if(TestFichierExiste(nomFichier)){
                    cout<<"ERR"<<endl;
                    cout<<"#"<<nomFichier<<" already used"<<endl;
                }
                else
                {
					espace.Save(nomFichier);
                }
            }
            else{
                cout<<"ERR"<<endl;
                cout<<"#invalid parameters"<<endl;
            }
            //Fin du code pour SAVE
        }

        else if (entree.substr(0,5)=="CLEAR") {
            //Code pour CLEAR
            espace.Clear();
            //Fin du code pour CLEAR
        }

        else if (entree.substr(0,6)=="DELETE") {
            //Code pour DELETE
            string name;
            vector<string> listeNoms;
            vector<string>::iterator it;
            int compteur=0;
            for(it=listeNoms.begin(); it!=listeNoms.end(); ++it){
				compteur++;
                name=Decoupage(entree,compteur);
                listeNoms.push_back(name);
			}
			espace.Delete(listeNoms);
            //Fin du code pour DELETE
        }

        else if (entree.substr(0,4)=="MOVE") {
            //Code pour MOVE
            string name;
            string deltaX,deltaY;
            long dX,dY;
            name=Decoupage(entree,1);
            deltaX=Decoupage(entree,2);
            deltaY=Decoupage(entree,3);
            dX=atol(deltaX.c_str());
            dY=atol(deltaY.c_str());

			//Faire les tests si on ne rentre pas des entiers

            if(NombreEspaces(entree)==3){
				espace.moveElement(name, dX, dY);
            }
            else{
                cout<<"ERR"<<endl;
                cout<<"#invalid parameters"<<endl;
            }
        }

        else if (entree.substr(0,1)=="C") {
            string name;
            string radius, centerX, centerY;
            name=Decoupage(entree,1);
            centerX=Decoupage(entree,2);
            centerY=Decoupage(entree,3);
            radius=Decoupage(entree,4);

            if(NombreEspaces(entree)==4)
            {
				long centerlX=atol(centerX.c_str());
				long centerlY=atol(centerY.c_str());
				long radiusl=atol(radius.c_str());
				espace.AddCircle(name, radiusl, centerlX, centerlY, entree );
            }
            else{
                cout<<"ERR"<<endl;
                cout<<"#invalid parameters : 4 parameters expected"<<endl;
            }

        }

        else if (entree.substr(0,1)=="R") {

            string name;
            string corner1X, corner1Y, corner2X, corner2Y;
            long coin1X, coin1Y, coin2X, coin2Y;
            name=Decoupage(entree,1);
            corner1X=Decoupage(entree,2);
            corner1Y=Decoupage(entree,3);
            corner2X=Decoupage(entree,4);
            corner2Y=Decoupage(entree,5);

            coin1X=atol(corner1X.c_str());
            coin1Y=atol(corner1Y.c_str());
            coin2X=atol(corner2X.c_str());
            coin2Y=atol(corner2Y.c_str());

            if(NombreEspaces(entree)==5){
				espace.AddRectangle(name, coin1X, coin1Y, coin2X, coin2Y, entree);
            }
            else{
                cout<<"ERR"<<endl;
                cout<<"#invalid parameters"<<endl;
            }

        }

        else if (entree.substr(0,2)=="PL") {
            string name;
            string cornerX, cornerY;
            long coinX, coinY;
            name=Decoupage(entree,1);

            if( NombreEspaces(entree)%2==1 && NombreEspaces(entree)>=3){ //Un point minimum
				//Code pour ajouter un polyligne
				int nbPoints=(NombreEspaces(entree)-1)/2;
				Point origin;
				vector<Point> newPointList;
				cornerX=Decoupage(entree,2);
				cornerY=Decoupage(entree,3);
				coinX=atol(cornerX.c_str());
				coinY=atol(cornerY.c_str());
				origin.x=coinX;
				origin.y=coinY;
				for(int i=2; i<=nbPoints; i++){
					//Améliorer performances de découpage
					cornerX=Decoupage(entree,i*2);
					cornerY=Decoupage(entree,i*2+1);
					coinX=atol(cornerX.c_str());
					coinY=atol(cornerY.c_str());
					Point p;
					p.x=coinX;
					p.y=coinY;
					newPointList.push_back(p);
				}
				espace.AddPolyline(name, newPointList, origin, entree);
            }
            else{
                cout<<"ERR"<<endl;
                cout<<"#invalid parameters"<<endl;
            }
        }

        else if (entree.substr(0,1)=="L") {
            string name;
            string corner1X, corner1Y, corner2X, corner2Y;
            long coin1X, coin1Y, coin2X, coin2Y;
            name=Decoupage(entree,1);
            corner1X=Decoupage(entree,2);
            corner1Y=Decoupage(entree,3);
            corner2X=Decoupage(entree,4);
            corner2Y=Decoupage(entree,5);

            coin1X=atol(corner1X.c_str());
            coin1Y=atol(corner1Y.c_str());
            coin2X=atol(corner2X.c_str());
            coin2Y=atol(corner2Y.c_str());

             if(NombreEspaces(entree)==5){
				espace.AddLine(name, coin1X, coin1Y, coin2X, coin2Y, entree);
            }
            else{
                cout<<"ERR"<<endl;
                cout<<"#invalid parameters"<<endl;
            }
        }

        else if (entree.substr(0,1)=="S") {
/*
            string name;
            string corner1X, corner1Y, corner2X, corner2Y;
            long coin1X, coin1Y, coin2X, coin2Y;
            name=Decoupage(entree,1);
            corner1X=Decoupage(entree,2);
            corner1Y=Decoupage(entree,3);
            corner2X=Decoupage(entree,4);
            corner2Y=Decoupage(entree,5);

            coin1X=atol(corner1X.c_str());
            coin1Y=atol(corner1Y.c_str());
            coin2X=atol(corner2X.c_str());
            coin2Y=atol(corner2Y.c_str());


*/
            //Code pour ajouter une selection
            //Fin du code pour ajouter une selection
        }

        else{
            cout<<"#invalid command"<<endl;

        }
        getline(cin,entree);
    }

    return 0;

	}

int NombreEspaces(string s)
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

bool Separateur(string s)
// Algorithme : Renvoie true si le nom de la figure ne contient pas de séparateur
//
{
    if(s.find(" ")==string::npos){
        return false;
    }
    else{
        return true;
    }
}

string Decoupage(string s, int posSpace)
// Algotihme : On extrait la chaine de caractères à paritir du posSpace-ème espace
//
{
        unsigned int i;
        int n=0;
        string result;
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

bool TestFichierExiste(string nomFichier)
// Algorithme : Renvoie true si le fichier existe déjà
//
{
    ifstream fichierATester(nomFichier.c_str());
    if (fichierATester.good()){
        fichierATester.close();
        return true;
    }
    else {
        return false;
    }
} //----- Fin de TestFichierExiste


