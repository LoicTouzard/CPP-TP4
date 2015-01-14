#include <iostream>
#include <vector>
#include <string.h>
#include <Point.h>
#include <Container.h>
#include <Graphics.h>
using namespace std;

	int nombreEspaces(String s);
    bool separateur(string s);

	int main(){

    Container espace;
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
            //Réinitialiser le container

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

            if(nombreEspaces(entree)==4){
                cin>>name>>centerX>>centerY>>radius;
                if(radius<0){
                    cout<<"ERR"<<endl;
                    cout<<"#radius must be a postive interger"<<endl;
                }
                else if(separateur(name)){  //Tester si le nom contient des séparateurs
                    cout<<"ERR"<<endl;
                    cout<<"#invalid name"<<endl;
                }
                else{
                    //Code pour ajouter un cercle
                    cout<<"OK"<<endl;
                    cout<<"#New object :"<<name<<endl;
                }
            }
            else{
                cout<<"ERR"<<endl;
                cout<<"#invalid parameters"<<endl;
            }
            cin>>entree;

        }

        else if (entree.substr(0,1)=="R") {

            string name;
            long radius, coin1X, coin2X, coin1Y, coin2Y;
            if(nombreEspaces(entree)==5){
                cin>>name>>coin1X>>coin1Y>>coin2X>>coin2Y;
                if(coin1X>coin2X ||coin1Y<coin2Y){ //Pour éviter ce test, prendre les max et min des deux points dans la méthode isInside(p1,p2)
                    cout<<"ERR"<<endl;
                    cout<<"#The must add the coordinates of the top left corner after the name"<<endl;
                }
                else if(separateur(name)){  //Tester si le nom contient des séparateurs
                    cout<<"ERR"<<endl;
                    cout<<"#invalid name"<<endl;
                }

                else{
                    //Code pour ajouter un rectangle
                    cout<<"OK"<<endl;
                    cout<<"#New object :"<<name<<endl;
                }
            }
            else{
                cout<<"ERR"<<endl;
                cout<<"#invalid parameters"<<endl;
            }


            cin>>entree;

        }

        else if (entree.substr(0,2)=="PL") {

            string name;
            long radius, coinX, coinY;

            cin>>name;
            if(separateur(name)){ //Tester si le nom contient des séparateurs
                cout<<"ERR"<<endl;
                cout<<"#invalid name"<<endl;
            }

           else if(nombreEspaces(entree)<=2){
                cout<<"ERR"<<endl;
                cout<<"#invalid parameters"<<endl;
            }

            else if(nombreEspaces(entree)%2!=0){
                cout<<"ERR"<<endl;
                cout<<"#the last point has only one coordonate. Missing Y-axis coordonate"<<endl;
            }

            else{
                    int nbPoints=(nbEspaces+1)/2;
                    vector<Point> pointList;
                    vector<Point>::iterator it;
                    for(it=0; it<nbPoints/2;++it){
                            cin>>coinX;
                            cin>>coinY;
                            pointList[it].x=coinX;
                            pointList[it].y=coinY;
                    }

                     //Code pour ajouter un polyligne
                    cout<<"OK"<<endl;
                    cout<<"#New object :"<<name<<endl;
            }


            cin>>entree;

        }

        else if (entree.substr(0,1)=="L") {

            string name;
            long radius, coin1X, coin2X, coin1Y, coin2Y;

            if(nombreEspaces(entree)==5){
                cin>>name>>coin1X>>coin1Y>>coin2X>>coin2Y;
                if(separateur(name)){  //Tester si le nom contient des séparateurs
                    cout<<"ERR"<<endl;
                    cout<<"#invalid name"<<endl;
                }
                else{
                    //Code pour ajouter une ligne
                    cout<<"OK"<<endl;
                    cout<<"#New object :"<<name<<endl;
                }
            }
            else{
                cout<<"ERR"<<endl;
                cout<<"#invalid parameters"<<endl;
            }

            cin>>entree;

        }

        else if (entree.substr(0,1)=="S") {

            string name;
            long radius, coin1X, coin2X, coin1Y, coin2Y;


            if(nombreEspaces(entree)==5){
                cin>>name>>coin1X>>coin1Y>>coin2X>>coin2Y;
                if(separateur(name)){  //Tester si le nom contient des séparateurs
                    cout<<"ERR"<<endl;
                    cout<<"#invalid name"<<endl;
                }
                else{
                    //Code pour ajouter une selection
                    cout<<"OK"<<endl;
                    cout<<"#New object :"<<name<<endl;
                }
            }
            else{
                cout<<"ERR"<<endl;
                cout<<"#invalid parameters"<<endl;
            }

            cin>>entree;

        }

        else{
            cout<<"#invalid command"<<endl;
            cin>>entree;

        }

    }

    return 0;

	}

    int nombreEspaces(String s){
        int nbEspaces=0;
        for(int i=0; i<s.length()-1; ++i){
            if(s[i]==' '){
                nbEspaces++;
            }
        }
        return nbEspaces;
    }

    bool separateur(string s){
        if(s.find(" ")==-1){
            return false;
        }
        else{
            return true;
        }
    }


