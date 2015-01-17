#include <iostream>
#include <vector>
#include <string>
#include "Point.h"
#include <algorithm>
#include "Container.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Selection.h"
#include "Polyline.h"
#include "Line.h"
using namespace std;

	int nombreEspaces(string s);
    bool separateur(string s);
    string decoupage(string s, int posSpace);

	int main(){

    Container espace;
    string entree;

    getline(cin,entree);

    while(entree.substr(0,4)!="EXIT"){

        if (entree.substr(0,4)=="LIST") {
			//Code pour afficher tous les descripteurs d'objets
            vector<Graphics*>::iterator it;
            for(it=espace.listeGraphics->begin(); it!=espace.listeGraphics->end();++it){
                cout<<(*it)->commandLine<<endl;
            }

            //Fin du code pour afficher tous les descripteurs d'objets
			getline(cin,entree);
        }

        else if (entree.substr(0,4)=="UNDO") {
           //Code pour UNDO

            getline(cin,entree);

        }

        else if (entree.substr(0,4)=="REDO") {
            //Code pour REDO

           getline(cin,entree);

        }

        else if (entree.substr(0,4)=="LOAD") {
            //Code pour LOAD

            getline(cin,entree);

        }

        else if (entree.substr(0,4)=="SAVE") {
            //Code pour SAVE

            getline(cin,entree);

        }

        else if (entree.substr(0,4)=="CLEAR") {
            //Code pour CLEAR
            //Réinitialiser le container

            getline(cin,entree);

        }

        else if (entree.substr(0,6)=="DELETE") {
            //Code pour DELETE

            getline(cin,entree);

        }

        else if (entree.substr(0,4)=="MOVE") {
            //Code pour MOVE

            getline(cin,entree);

        }

        else if (entree.substr(0,1)=="C") {

            string name;
            string radius, centerX, centerY;
            name=decoupage(entree,1);
            centerX=decoupage(entree,2);
            centerY=decoupage(entree,3);
            radius=decoupage(entree,4);
            if(nombreEspaces(entree)==4){
                if(atol(radius.c_str())<0){
                    cout<<"ERR"<<endl;
                    cout<<"#radius must be a postive interger"<<endl;
                }
                else if(separateur(name)){  //Tester si le nom contient des séparateurs
                    cout<<"ERR"<<endl;
                    cout<<"#invalid name"<<endl;
                }
                else{
                    //Code pour ajouter un cercle
                    Point center;
                    center.x=atol(centerX.c_str());
                    center.y=atol(centerY.c_str());
                    Circle *c=new Circle(atol(radius.c_str()), center, name, entree);
                    espace.listeGraphics->push_back(c);
                    //Fin du code pour ajouter un cerlce
                    cout<<"OK"<<endl;
                    cout<<"#New object :"<<name<<endl;
                }
            }
            else{
                cout<<"ERR"<<endl;
                cout<<"#invalid parameters"<<endl;
            }
            getline(cin,entree);

        }

        else if (entree.substr(0,1)=="R") {

            string name;
            string corner1X, corner1Y, corner2X, corner2Y;
            long coin1X, coin1Y, coin2X, coin2Y;
            name=decoupage(entree,1);
            corner1X=decoupage(entree,2);
            corner1Y=decoupage(entree,3);
            corner2X=decoupage(entree,4);
            corner2Y=decoupage(entree,5);

            coin1X=atol(corner1X.c_str());
            coin1Y=atol(corner1Y.c_str());
            coin2X=atol(corner2X.c_str());
            coin2Y=atol(corner2Y.c_str());


            if(nombreEspaces(entree)==5){
               /* if(coin1X>coin2X ||coin1Y<coin2Y){ //Pour éviter ce test, prendre les max et min des deux points dans la méthode isInside(p1,p2)
                    cout<<"ERR"<<endl;
                    cout<<"#The must add the coordinates of the top left corner after the name"<<endl;
                }*/
                if(separateur(name)){  //Tester si le nom contient des séparateurs
                    cout<<"ERR"<<endl;
                    cout<<"#invalid name"<<endl;
                }

                else{
                    //Code pour ajouter un rectangle
                    Point origin;
                    Point extremity;
                    if(coin1X>coin2X && coin1Y>coin2Y){
                        //On inverse que les X des deux coins
                        long temp1X;
                        coin1X=temp1X;
                        coin1X=coin2X;
                        coin2X=temp1X;
                        cout<<"#Reverse corner's X coordonates"<<endl;
                        //Modifier la commandLine
                    }
                    else if(coin1X<coin2X && coin1Y>coin2Y){
                        //OK
                    }
                    else if(coin1X>coin2X && coin1Y<coin2Y){
                        //On échange les coins
                        long tempX, tempY;
                        coin1X=tempX;
                        coin1Y=tempY;
                        coin1X=coin2X;
                        coin1Y=coin2Y;
                        coin2X=tempX;
                        coin2Y=tempY;
                        cout<<"#Reverse corners"<<endl;
                        //Modifier la commandLine
                    }
                    else if(coin1X<coin2X && coin1Y<coin2Y){
                        //On inverse que les Y des deux coins
                        long temp1Y;
                        coin1Y=temp1Y;
                        coin1Y=coin2Y;
                        coin2Y=temp1Y;
                        cout<<"#Reverse corner's Y coordonates"<<endl;
                        //Modifier la commandLine
                    }
                    origin.x=coin1X;
                    origin.y=coin1Y;
                    extremity.x=coin2X;
                    extremity.y=coin2Y;
                    Rectangle *r=new Rectangle(extremity, origin, name, entree);
                    espace.listeGraphics->push_back(r);
                    //Fin du code pour ajouter un rectangle
                    cout<<"OK"<<endl;
                    cout<<"#New object :"<<name<<endl;
                }
            }
            else{
                cout<<"ERR"<<endl;
                cout<<"#invalid parameters"<<endl;
            }

            getline(cin,entree);

        }

        else if (entree.substr(0,2)=="PL") {

            getline(cin,entree);

        }

        else if (entree.substr(0,1)=="L") {

            getline(cin,entree);

        }

        else if (entree.substr(0,1)=="S") {

            getline(cin,entree);

        }

        else{
            cout<<"#invalid command"<<endl;
            cin>>entree;

        }

    }

    return 0;

	}

    int nombreEspaces(string s){
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

    string decoupage(string s, int posSpace){
        int i;
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


