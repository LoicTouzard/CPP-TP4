#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime> //Juste pour les tests de performances

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
        /*
        string entree;
        getline(cin,entree);
        
        string nomFichier="doc/Save_"+entree"_formes.txt";
		ifstream loadFile(nomFichier.c_str());
		
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
		
        //Commenter tout ce qui suit si on veut juste faire les tests
/*
		string entree;
        getline(cin,entree);

        list<string> args;
        Tools::Split(entree, args);
        if(args.size()==0)
        {
            args.push_back("");
        }
        string commandType = args.front();
        args.pop_front();

        while(commandType!="EXIT"){
            //les tests de detection de commande sont triés selon leur potentielle fréquence d'apparition pour optimiser la vitesse

            if (commandType=="C") {

                if(args.size()==4)
                {
                    string name;
                    name = args.front();
                    args.pop_front();
                    long centerlX = atol(args.front().c_str());
                    args.pop_front();
                    long centerlY = atol(args.front().c_str());
                    args.pop_front();
                    long radiusl = atol(args.front().c_str());

                    espace.AddCircle(name, radiusl, centerlX, centerlY, entree );
                }
                else{
                    cout<<"ERR"<<endl;
                    cout<<"#invalid parameters : 4 parameters expected"<<endl;
                }

            }

            else if (commandType=="R") {

                if(args.size()==5){
                    string name;
                    long coin1X, coin1Y, coin2X, coin2Y;

                    name=args.front();
                    args.pop_front();
                    coin1X=atol(args.front().c_str());
                    args.pop_front();
                    coin1Y=atol(args.front().c_str());
                    args.pop_front();
                    coin2X=atol(args.front().c_str());
                    args.pop_front();
                    coin2Y=atol(args.front().c_str());
                    args.pop_front();

                    espace.AddRectangle(name, coin1X, coin1Y, coin2X, coin2Y, entree);
                }
                else{
                    cout<<"ERR"<<endl;
                    cout<<"#invalid parameters"<<endl;
                }

            }

            else if (commandType=="PL") {

                if( args.size()%2==1 && args.size()>=3){ //Un point minimum

                    int nbPoints=(args.size()-1)/2;
                    string name = args.front();
                    args.pop_front();

                    //Code pour ajouter un polyligne
                    Point origin;
                    vector<Point> newPointList;
                    origin.x=atol(args.front().c_str());
                    args.pop_front();
                    origin.y=atol(args.front().c_str());
                    args.pop_front();

                    for(int i=2; i<=nbPoints; i++){
                        Point p;
                        p.x=atol(args.front().c_str());
                        args.pop_front();
                        p.y=atol(args.front().c_str());
                        args.pop_front();

                        newPointList.push_back(p);
                    }
                    espace.AddPolyline(name, newPointList, origin, entree);
                }
                else{
                    cout<<"ERR"<<endl;
                    cout<<"#invalid parameters"<<endl;
                }
            }

            else if (commandType=="L") {

                 if(args.size()==5){
                    string name;
                    long coin1X, coin1Y, coin2X, coin2Y;

                    name=args.front();
                    args.pop_front();
                    coin1X=atol(args.front().c_str());
                    args.pop_front();
                    coin1Y=atol(args.front().c_str());
                    args.pop_front();
                    coin2X=atol(args.front().c_str());
                    args.pop_front();
                    coin2Y=atol(args.front().c_str());
                    espace.AddLine(name, coin1X, coin1Y, coin2X, coin2Y, entree);
                }
                else{
                    cout<<"ERR"<<endl;
                    cout<<"#invalid parameters"<<endl;
                }
            }

            else if (commandType=="S") {

                if(args.size()==5){
                    string name;
                    long coin1X, coin1Y, coin2X, coin2Y;

                    name=args.front();
                    args.pop_front();
                    coin1X=atol(args.front().c_str());
                    args.pop_front();
                    coin1Y=atol(args.front().c_str());
                    args.pop_front();
                    coin2X=atol(args.front().c_str());
                    args.pop_front();
                    coin2Y=atol(args.front().c_str());
                    espace.AddSelection(name, coin1X, coin1Y, coin2X, coin2Y, entree);
                }
                else{
                    cout<<"ERR"<<endl;
                    cout<<"#invalid parameters"<<endl;
                }
            }

            else if (commandType=="LIST"){
                //Code pour afficher tous les descripteurs d'objets
                espace.List();
                //Fin du code pour afficher tous les descripteurs d'objets
            }

            else if (commandType=="DELETE") {
                //Code pour DELETE
                if(args.size()>0){
                    vector<string> listeNoms;
                    list<string>::iterator it;
                    for(it=args.begin();it!=args.end(); ++it){
                        listeNoms.push_back(*it);
                    }
                    espace.Delete(listeNoms);
                    //Fin du code pour DELETE
                }
                else{
                    cout<<"ERR"<<endl;
                    cout<<"#missing parameters"<<endl;
                }
            }

            else if (commandType=="MOVE") {


                if(args.size()==3){
                    //Code pour MOVE
                    string name;
                    long dX,dY;
                    name=args.front();
                    args.pop_front();
                    dX=atol(args.front().c_str());
                    args.pop_front();
                    dY=atol(args.front().c_str());
                    espace.moveElement(name, dX, dY);
                }
                else{
                    cout<<"ERR"<<endl;
                    cout<<"#invalid parameters"<<endl;
                }
            }

            else if (commandType=="UNDO") {
                //Code pour UNDO
                espace.Undo();
                //Fin du code pour UNDO
            }

            else if (commandType=="REDO") {
                //Code pour REDO
                espace.Redo();
                //Fin du code pour REDO
            }

            else if (commandType=="LOAD") {
                //Lancer le timer pour les tests de performances


                //Code pour LOAD
                if(args.size()==1){
                    string Filename;
                    Filename=args.front();
                    if(!Tools::FileExists(Filename))
                    {
                        cout<<"ERR"<<endl;
                        cout<<"#can't find "<<Filename<<endl;
                    }
                    else
                    {
                        espace.Load(Filename);
                    }
                }
                else{
                    cout<<"ERR"<<endl;
                    cout<<"#invalid parameters"<<endl;
                }

                 //Arreter le timer pour les tests de performances
            }

            else if (commandType=="SAVE") {
                //Code pour SAVE
                if(args.size()==1){
                    string filename;
                    filename=args.front();
                    if(Tools::FileExists(filename)){
                        cout<<"ERR"<<endl;
                        cout<<"#"<<filename<<" already used"<<endl;
                    }
                    else
                    {
                        espace.Save(filename);
                    }
                }
                else{
                    cout<<"ERR"<<endl;
                    cout<<"#invalid parameters"<<endl;
                }
                //Fin du code pour SAVE
            }

            else if (commandType=="CLEAR") {
                //Code pour CLEAR
                espace.Clear();
                //Fin du code pour CLEAR
            }

            else
            {
                cout<<"#invalid command"<<endl;
            }

            getline(cin,entree);
            args.clear();
            Tools::Split(entree, args);
            if(args.size()==0)
            {
                args.push_back("");
            }
            commandType = args.front();
            args.pop_front();
        }*/
        return 0;
    }


