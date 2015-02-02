#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime> //Juste pour les tests de perfromances

#include "Tools.h"
#include "Point.h"
#include "Container.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Selection.h"
#include "Polyline.h"
#include "Line.h"
using namespace std;


int main(){
		Container espace; //Espace qui contient toutes les figures et selections
        
        
		/*ofstream fichier;
		fichier.open("doc/Load_10000000_formes.txt", ios::trunc);
        for(int i=1; i<=2500000;i++){
			fichier<<"C "<<"cercle"<<i<<" 0 0 "<<i<<endl;
		}
		for(int i=1; i<=2500000;i++){
			fichier<<"R "<<"rect"<<i<<" 0 0 "<<i<<" "<<i+1<<endl;
		}
		for(int i=1; i<=2500000;i++){
			fichier<<"L "<<"line"<<i<<" 0 0 "<<i<<" "<<i+1<<endl;
		}
		for(int i=1; i<=2500000;i++){
			fichier<<"PL "<<"poly"<<i<<" 0 0 "<<i<<" "<<i+1<<" "<<i+2<<" "<<i+3<<endl;
		}
        
        */
        
        //A décommenter pour les tests
       
        string entree;
        getline(cin,entree);
        
        clock_t    start;
        start = clock();
        espace.Load("doc/Load_"+entree+"_formes.txt");
        cout << "Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;

        /*Commenter tout ce qui suit si on veut juste faire les tests*/

       /* string entree;
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
                //Lancer le timer pour les tests de performances


                //Code pour LOAD
                if(Tools::NombreEspaces(entree)==1){
                    string nomFichier;
                    nomFichier=Tools::Decoupage(entree,1);
                    if(!Tools::TestFichierExiste(nomFichier))
                    {
                        cout<<"ERR"<<endl;
                        cout<<"#can't find "<<nomFichier<<endl;
                    }
                    else
                    {
                        espace.Load(nomFichier);
                    }
                }
                else{
                    cout<<"ERR"<<endl;
                    cout<<"#invalid parameters"<<endl;
                }

                 //Arreter le timer pour les tests de performances
            }

            else if (entree.substr(0,4)=="SAVE") {
                //Code pour SAVE
                if(Tools::NombreEspaces(entree)==1){
                    string nomFichier;
                    nomFichier=Tools::Decoupage(entree,1);
                    if(Tools::TestFichierExiste(nomFichier)){
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
                for(int i=0; i<Tools::NombreEspaces(entree); ++i){
                    name=Tools::Decoupage(entree,i+1);
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
                name=Tools::Decoupage(entree,1);
                deltaX=Tools::Decoupage(entree,2);
                deltaY=Tools::Decoupage(entree,3);
                dX=atol(deltaX.c_str());
                dY=atol(deltaY.c_str());

                //Faire les tests si on ne rentre pas des entiers

                if(Tools::NombreEspaces(entree)==3){
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
                name=Tools::Decoupage(entree,1);
                centerX=Tools::Decoupage(entree,2);
                centerY=Tools::Decoupage(entree,3);
                radius=Tools::Decoupage(entree,4);

                if(Tools::NombreEspaces(entree)==4)
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
                name=Tools::Decoupage(entree,1);
                corner1X=Tools::Decoupage(entree,2);
                corner1Y=Tools::Decoupage(entree,3);
                corner2X=Tools::Decoupage(entree,4);
                corner2Y=Tools::Decoupage(entree,5);

                coin1X=atol(corner1X.c_str());
                coin1Y=atol(corner1Y.c_str());
                coin2X=atol(corner2X.c_str());
                coin2Y=atol(corner2Y.c_str());

                if(Tools::NombreEspaces(entree)==5){
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
                name=Tools::Decoupage(entree,1);

                if( Tools::NombreEspaces(entree)%2==1 && Tools::NombreEspaces(entree)>=3){ //Un point minimum
                    //Code pour ajouter un polyligne
                    int nbPoints=(Tools::NombreEspaces(entree)-1)/2;
                    Point origin;
                    vector<Point> newPointList;
                    cornerX=Tools::Decoupage(entree,2);
                    cornerY=Tools::Decoupage(entree,3);
                    coinX=atol(cornerX.c_str());
                    coinY=atol(cornerY.c_str());
                    origin.x=coinX;
                    origin.y=coinY;
                    for(int i=2; i<=nbPoints; i++){
                        //Améliorer performances de découpage
                        cornerX=Tools::Decoupage(entree,i*2);
                        cornerY=Tools::Decoupage(entree,i*2+1);
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
                name=Tools::Decoupage(entree,1);
                corner1X=Tools::Decoupage(entree,2);
                corner1Y=Tools::Decoupage(entree,3);
                corner2X=Tools::Decoupage(entree,4);
                corner2Y=Tools::Decoupage(entree,5);

                coin1X=atol(corner1X.c_str());
                coin1Y=atol(corner1Y.c_str());
                coin2X=atol(corner2X.c_str());
                coin2Y=atol(corner2Y.c_str());

                 if(Tools::NombreEspaces(entree)==5){
                    espace.AddLine(name, coin1X, coin1Y, coin2X, coin2Y, entree);
                }
                else{
                    cout<<"ERR"<<endl;
                    cout<<"#invalid parameters"<<endl;
                }
            }

            else if (entree.substr(0,1)=="S") {

                string name;
                string corner1X, corner1Y, corner2X, corner2Y;
                long coin1X, coin1Y, coin2X, coin2Y;
                name=Tools::Decoupage(entree,1);
                corner1X=Tools::Decoupage(entree,2);
                corner1Y=Tools::Decoupage(entree,3);
                corner2X=Tools::Decoupage(entree,4);
                corner2Y=Tools::Decoupage(entree,5);

                coin1X=atol(corner1X.c_str());
                coin1Y=atol(corner1Y.c_str());
                coin2X=atol(corner2X.c_str());
                coin2Y=atol(corner2Y.c_str());

                if(Tools::NombreEspaces(entree)==5){
                    espace.AddSelection(name, coin1X, coin1Y, coin2X, coin2Y, entree);
                }
                else{
                    cout<<"ERR"<<endl;
                    cout<<"#invalid parameters"<<endl;
                }
            }
            else
            {
                cout<<"#invalid command"<<endl;
            }
            getline(cin,entree);
        }*/
        return 0;
    }


