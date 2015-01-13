#include <iostream>
#include <vector>
#include <string.h>
#include <Point.h>
using namespace std;

	int main(){

    string entree;

    cin>>entree;

    while(entree.substr(0,4)!="EXIT"){

        if (entree.substr(0,4)=="LIST") {
			//Code pour afficher tous les descripteurs d'objets

			cin>>entree;
        }

        else if (entree.substr(0,4)=="UNDO") {
           //Code pour UNDO

            cin>>entree;

        }

        else if (entree.substr(0,4)=="REDO") {
            //Code pour REDO

            cin>>entree;

        }

        else if (entree.substr(0,4)=="LOAD") {
            //Code pour LOAD

            cin>>entree;

        }

        else if (entree.substr(0,4)=="SAVE") {
            //Code pour SAVE

            cin>>entree;

        }

        else if (entree.substr(0,4)=="CLEAR") {
            //Code pour CLEAR

            cin>>entree;

        }

        else if (entree.substr(0,6)=="DELETE") {
            //Code pour DELETE

            cin>>entree;

        }

        else if (entree.substr(0,4)=="MOVE") {
            //Code pour MOVE

            cin>>entree;

        }

        else if (entree.substr(0,1)=="C") {

            string name;
            long radius, centerX, centerY;

            cin>>name>>centerX>>centerY>>radius;

            //Code pour ajouter un cercle

            cin>>entree;

        }

        else if (entree.substr(0,1)=="R") {

            string name;
            long radius, coin1X, coin2X, coin1Y, coin2Y;

            cin>>name>>coin1X>>coin1Y>>coin2X>>coin2Y;

            //Code pour ajouter un rectangle

            cin>>entree;

        }

        else if (entree.substr(0,2)=="PL") {

            string name;
            long radius, coinX, coinY;

            cin>>name;

            int nbEspaces=0;

            //A revoir (traiter le cas où le dernier caractère est un espace)
            for(int i=0; i<entree.length()-1; ++i){
                    if(entree[i]==' ' && entree[i+1]!=' ' ){
                        nbEspaces++;
                    }
            }
            int nbPoints=(nbEspaces+1)/2;
            vector<Point> pointList;
            vector<Point>::iterator it;
            for(int j=0; j<nbPoints/2; j++){
                    cin>>coinX;
                    cin>>coinY;
                    pointList[j].x=coinX;
                    pointList[j].y=coinY;
            }

            //Code pour ajouter une polyligne

            cin>>entree;

        }

        else if (entree.substr(0,1)=="L") {

            string name;
            long radius, coin1X, coin2X, coin1Y, coin2Y;

            cin>>name>>coin1X>>coin1Y>>coin2X>>coin2Y;

            //Code pour ajouter une ligne

            cin>>entree;

        }

        else if (entree.substr(0,1)=="S") {

            string name;
            long radius, coin1X, coin2X, coin1Y, coin2Y;

            cin>>name>>coin1X>>coin1Y>>coin2X>>coin2Y;

            //Code pour ajouter une selection

            cin>>entree;

        }

        else{

            cin>>entree;

        }

    }

    return 0;

	}

