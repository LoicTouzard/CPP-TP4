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
    bool NomLibre(string s);
    bool TestFichierExiste(string nomFichier);

    template <typename T>
	// Mode d'emploi :Convertir un entier en chaine de caractere
	//
	// Contrat :
	//
	string Long_to_string(T valeur)
	{
		ostringstream oss;
		oss<<valeur;
		return oss.str();
	}

    Container espace; //Espace qui contient toutes les figures et selections

	int main(){
        string entree;
        getline(cin,entree);

        while(entree.substr(0,4)!="EXIT"){

        if (entree.substr(0,4)=="LIST") {
			//Code pour afficher tous les descripteurs d'objets
            vector<Graphics*>::iterator it;

            if(espace.listeGraphics->size()==0){
                cout<<"#The list is empty"<<endl;
            }
            else{
                for(it=espace.listeGraphics->begin(); it!=espace.listeGraphics->end();++it){
                    cout<<(*it)->commandLine<<endl;
                }
            }
            //Fin du code pour afficher tous les descripteurs d'objets
			getline(cin,entree);
        }

        else if (entree.substr(0,4)=="UNDO") {
            //Code pour UNDO


            //Fin du code pour UNDO
            getline(cin,entree);
        }

        else if (entree.substr(0,4)=="REDO") {
            //Code pour REDO


            //Fin du code pour REDO
           getline(cin,entree);

        }

        else if (entree.substr(0,4)=="LOAD") {
            //Code pour LOAD

            getline(cin,entree);

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
                else if(!TestFichierExiste(nomFichier)){
                    ofstream fichier;
                    fichier.open(nomFichier.c_str(),ios::trunc);
                    if(fichier){
                        vector<Graphics*>::iterator it;
                        for(it=espace.listeGraphics->begin(); it!=espace.listeGraphics->end();++it){
                            fichier<<(*it)->commandLine<<endl;
                        }
                        fichier.close();
                        cout<<"OK"<<endl;
                    }
                    else{
                        cout<<"#Can't create the file "<<nomFichier<<endl;
                    }
                }
            }
            else{
                cout<<"ERR"<<endl;
                cout<<"#invalid parameters"<<endl;
            }
            //Fin du code pour SAVE
            getline(cin,entree);
        }

        else if (entree.substr(0,5)=="CLEAR") {
            //Code pour CLEAR
            if(espace.listeGraphics->size()==0){
                espace.listeGraphics->clear();
                cout<<"OK"<<endl;
                cout<<"#The list was empty"<<endl;
            }
            else{
                espace.listeGraphics->clear();
                cout<<"OK"<<endl;
            }
            //Fin du code pour CLEAR
            getline(cin,entree);

        }

        else if (entree.substr(0,6)=="DELETE") {
            //Code pour DELETE
            string name;
            string *temp=new string[NombreEspaces(entree)];
            vector<Graphics*>::iterator it;
            bool erreur=false;
            for(int i=1; i<=NombreEspaces(entree); i++){
                name=Decoupage(entree,i);
                temp[i-1]=name;
                //Tester si chaque nom existe dans la liste
                if( NomLibre(name) ){
                    cout<<"#ERR"<<endl;
                    cout<<"#Can't find "<<name<<" as an object"<<endl;
                    erreur=true;
                    break;
                }
            }
            if(!erreur){
                for(it=espace.listeGraphics->begin(); it!=espace.listeGraphics->end();++it){
                    for(int j=0; j<NombreEspaces(entree); j++){
                        if( (*it)->name==temp[j]){
                           //espace.listeGraphics->erase(it);
                           //Rajouter une méthode virtuelle delete sur toutes les formes (éviter les fuites mémoire)
                        }
                    }
                }
               // cout<<"OK"<<endl;
            }
            //Fin du code pour DELETE
            getline(cin,entree);
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

            if(NombreEspaces(entree)==3){
                vector<Graphics*>::iterator it;
                bool found=false;
                for(it=espace.listeGraphics->begin(); it!=espace.listeGraphics->end();++it){
                    if( (*it)->name==name){
                        (*it)->move(dX,dY);
                        found=true;
                    }
                }
                if(found){
                    cout<<"OK"<<endl;
                }
                else{
                    cout<<"ERR"<<endl;
                    cout<<"#"<<name<<" not found"<<endl;
                }
            }
            else{
                cout<<"ERR"<<endl;
                cout<<"#invalid parameters"<<endl;
            }
            getline(cin,entree);

        }

        else if (entree.substr(0,1)=="C") {

            string name;
            string radius, centerX, centerY;
            name=Decoupage(entree,1);
            centerX=Decoupage(entree,2);
            centerY=Decoupage(entree,3);
            radius=Decoupage(entree,4);
            if(NombreEspaces(entree)==4){
                 if(!NomLibre(name)){
                    cout<<"ERR"<<endl;
                    cout<<"#name already taken"<<endl;
                }
                else{
                    if(atol(radius.c_str())<0){
                        cout<<"ERR"<<endl;
                        cout<<"#radius must be a postive interger"<<endl;
                    }
                    else if(Separateur(name)){  //Tester si le nom contient des séparateurs
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
               /* if(coin1X>coin2X ||coin1Y<coin2Y){ //Pour éviter ce test, prendre les max et min des deux points dans la méthode isInside(p1,p2)
                    cout<<"ERR"<<endl;
                    cout<<"#The must add the coordinates of the top left corner after the name"<<endl;
                }*/
                if(Separateur(name)){  //Tester si le nom contient des séparateurs
                    cout<<"ERR"<<endl;
                    cout<<"#invalid name"<<endl;
                    break;
                }
                else if(!NomLibre(name)){
                    cout<<"ERR"<<endl;
                    cout<<"#name already taken"<<endl;
                }

                else if(NomLibre(name)){
                    //Code pour ajouter un rectangle
                    Point origin;
                    Point extremity;
                    if(coin1X>coin2X && coin1Y>coin2Y){
                        //On inverse que les X des deux coins
                        long temp1X;
                        temp1X=coin1X;
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
                        tempX=coin1X;
                        tempY=coin1Y;
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
                        temp1Y=coin1Y;
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
            string name;
            string cornerX, cornerY;
            long coinX, coinY;
            name=Decoupage(entree,1);

            if( NombreEspaces(entree)%2==1 && NombreEspaces(entree)>=3){ //Un point minimum
                if(Separateur(name)){  //Tester si le nom contient des séparateurs
                    cout<<"ERR"<<endl;
                    cout<<"#invalid name"<<endl;
                    break;
                }
                else if( !NomLibre(name) ){
                    cout<<"ERR"<<endl;
                    cout<<"#name already taken"<<endl;
                }
                else if( NomLibre(name) ){
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
                        for(int i=1; i<nbPoints; i++){
                            cornerX=Decoupage(entree,i+2);
                            cornerY=Decoupage(entree,i+3);
                            coinX=atol(cornerX.c_str());
                            coinY=atol(cornerY.c_str());
                            Point p;
                            p.x=coinX;
                            p.y=coinY;
                            newPointList.push_back(p);
                        }
                        Polyline *pl =new Polyline (newPointList, origin, name, entree);
                        espace.listeGraphics->push_back(pl);
                        //Fin du code pour ajouter un polyligne
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
               /* if(coin1X>coin2X ||coin1Y<coin2Y){ //Pour éviter ce test, prendre les max et min des deux points dans la méthode isInside(p1,p2)
                    cout<<"ERR"<<endl;
                    cout<<"#The must add the coordinates of the top left corner after the name"<<endl;
                }*/
                if(Separateur(name)){  //Tester si le nom contient des séparateurs
                    cout<<"ERR"<<endl;
                    cout<<"#invalid name"<<endl;
                }

                 else if(!NomLibre(name)){
                    cout<<"ERR"<<endl;
                    cout<<"#name already taken"<<endl;
                }

                else if(NomLibre(name)){
                    //Code pour ajouter une ligne
                    Point origin;
                    Point extremity;

                    origin.x=coin1X;
                    origin.y=coin1Y;
                    extremity.x=coin2X;
                    extremity.y=coin2Y;
                    Line *l=new Line(extremity, origin, name, entree);
                    espace.listeGraphics->push_back(l);
                    //Fin du code pour ajouter une ligne
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

        else if (entree.substr(0,1)=="S") {

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



            //Code pour ajouter une selection
            getline(cin,entree);
            //Fin du code pour ajouter une selection
        }

        else{
            cout<<"#invalid command"<<endl;
            cin>>entree;

        }
    }

    return 0;

	}

int NombreEspaces(string s)
// Algorithme : Compte le nombre d'espaces dans un string (utile pour savoir si le format d'entrée est respecté)
//
{
        int nbEspaces=0;
        for(int i=0; i<s.length()-1; i++){
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
        if(s.find(" ")==-1){
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

bool NomLibre(string s)
// Algorithme : Renvoie true si le nom de la figure n'est pas déjà utilisé
//
{
        vector<Graphics*>::iterator it;
         for(it=espace.listeGraphics->begin(); it!=espace.listeGraphics->end();++it){
            if( (*it)->name==s){
                return false;
             }
         }
         return true;
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


