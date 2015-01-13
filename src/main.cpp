#include <iostream>
#include <string>
using namespace std;

class main{
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
            //Code pour ajouter un cercle

            cin>>entree;

        }
        
        else if (entree.substr(0,1)=="R") {

            //Code pour ajouter un rectangle

            cin>>entree;

        }
        
        else if (entree.substr(0,2)=="PL") {
            //Code pour ajouter une polyligne

            cin>>entree;

        }
        
        else if (entree.substr(0,1)=="L") {
            //Code pour ajouter une ligne

            cin>>entree;

        }
        
        else if (entree.substr(0,1)=="S") {
            //Code pour ajouter une selection

            cin>>entree;

        }

        else{

            cin>>entree;

        }

    }

    return 0;

	}
};

