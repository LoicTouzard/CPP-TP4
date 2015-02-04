/*************************************************************************
                           main
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par TOUZARD Loïc, GOUZI Gaëtan et GONZALEZ TOLEDO Gabriela
*************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime> //Juste pour les tests de performances

#include "Tools.h"
#include "Point.h"
#include "Container.h"

using namespace std;


int main(){
		Container espace; //Espace qui contient toutes les figures et selections
/*    
        //A décommenter pour les tests de performances de SAVE
        string entree;
        getline(cin,entree);
        espace.Load("doc/Load_"+entree+"_formes.txt");
        clock_t    start;
        start = clock();
        espace.Save("doc/Save_"+entree+"_formes.txt");
        cout << "Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
*/

/*		//A décommenter pour les tests de performances de LOAD
        string entree;
        getline(cin,entree);
        clock_t    start;
        start = clock();
        espace.Load("doc/Load_"+entree+"_formes.txt");
        cout << "Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
*/
		string entree;
        getline(cin,entree);    // on récupère la commande de l'utilisateur

        list<string> args;
        Tools::Split(entree, args); // séparation des mots d la commande
        if(args.size()==0)  //cas particulier si l'utilisateur rentre une ligne vide
        {
            args.push_back("");
        }
        string commandType = args.front();  // On récupère le mot clé représentant le type de la commande
        args.pop_front();


        while(commandType!="EXIT")
        {
            //les tests de detection de commande sont triés selon leur potentielle fréquence d'apparition pour optimiser la vitesse

            if (commandType=="C")
            {

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

                    //  ajout d'un cercle dans le container
                    espace.AddCircle(name, radiusl, centerlX, centerlY, entree );
                }
                else
                {
                    cout<<"ERR"<<endl;
                    cout<<"#invalid parameters : 4 parameters expected"<<endl;
                }

            }

            else if (commandType=="R")
            {

                if(args.size()==5)
                {
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

                    //  ajout d'un retangle dans le container
                    espace.AddRectangle(name, coin1X, coin1Y, coin2X, coin2Y, entree);
                }
                else
                {
                    cout<<"ERR"<<endl;
                    cout<<"#invalid parameters"<<endl;
                }

            }

            else if (commandType=="PL")
            {

                if( args.size()%2==1 && args.size()>=3)
                { //Un nombre pair de coordonnées + le nom => nombre impair obligatoire
                    int nbPoints=(args.size()-1)/2;

                    string name = args.front();
                    args.pop_front();

                    //on stocke le premier point a part c'est l'origine.
                    Point origin;
                    //Puis le reste des points dans un vecteur.
                    vector<Point> newPointList;
                    origin.x=atol(args.front().c_str());
                    args.pop_front();
                    origin.y=atol(args.front().c_str());
                    args.pop_front();

                    for(int i=2; i<=nbPoints; i++)
                    {
                        Point p;
                        p.x=atol(args.front().c_str());
                        args.pop_front();
                        p.y=atol(args.front().c_str());
                        args.pop_front();

                        newPointList.push_back(p);
                    }

                    //  ajout d'une polyligne dans le container
                    espace.AddPolyline(name, newPointList, origin, entree);
                }
                else
                {
                    cout<<"ERR"<<endl;
                    cout<<"#invalid parameters"<<endl;
                }
            }

            else if (commandType=="L")
            {

                 if(args.size()==5)
                 {
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

                    //  ajout d'une ligne dans le container
                    espace.AddLine(name, coin1X, coin1Y, coin2X, coin2Y, entree);
                }
                else
                {
                    cout<<"ERR"<<endl;
                    cout<<"#invalid parameters"<<endl;
                }
            }

            else if (commandType=="S") 
            {

                if(args.size()==5)
                {
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

                    //  ajout d'une selection dans le container
                    espace.AddSelection(name, coin1X, coin1Y, coin2X, coin2Y, entree);
                }
                else
                {
                    cout<<"ERR"<<endl;
                    cout<<"#invalid parameters"<<endl;
                }
            }

            else if (commandType=="LIST")
            {
                //demande au container d'afficher toutes ses figures
                espace.List();
            }

            else if (commandType=="DELETE")
            {

                if(args.size()>0)
                {
                    vector<string> listeNoms;
                    list<string>::iterator it;
                    for(it=args.begin();it!=args.end(); ++it)
                    {
                        listeNoms.push_back(*it);
                    }
                    espace.Delete(listeNoms);
                    //Fin du code pour DELETE
                }
                else
                {
                    cout<<"ERR"<<endl;
                    cout<<"#missing parameters"<<endl;
                }
            }

            else if (commandType=="MOVE") 
            {

                if(args.size()==3)
                {
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
                else
                {
                    cout<<"ERR"<<endl;
                    cout<<"#invalid parameters"<<endl;
                }
            }

            else if (commandType=="UNDO")
            {
                // demande d'annulation de la derniere modification
                espace.Undo();
            }

            else if (commandType=="REDO") 
            {
                // demande pour refaire la derniere modification
                espace.Redo();
            }

            else if (commandType=="LOAD")
            {
                if(args.size()==1)
                {
                    string Filename;
                    Filename=args.front();
                    if(!Tools::FileExists(Filename))
                    {
                        cout<<"ERR"<<endl;
                        cout<<"#can't find "<<Filename<<endl;
                    }
                    else
                    {
                        //demande de chargement en mémoire du fichier
                        espace.Load(Filename);
                    }
                }
                else
                {
                    cout<<"ERR"<<endl;
                    cout<<"#invalid parameters"<<endl;
                }
            }

            else if (commandType=="SAVE") 
            {
                if(args.size()==1)
                {
                    string filename;
                    filename=args.front();
                    if(Tools::FileExists(filename))
                    {
                        cout<<"ERR"<<endl;
                        cout<<"#"<<filename<<" already used"<<endl;
                    }
                    else
                    {
                        //demande de sauvegarde en fichier des elements
                        espace.Save(filename);
                    }
                }
                else
                {
                    cout<<"ERR"<<endl;
                    cout<<"#invalid parameters"<<endl;
                }
            }

            else if (commandType=="CLEAR")
            {
                //demande de suppression de tous les elements actifs
                espace.Clear();
            }

            else
            {
                cout<<"#invalid command"<<endl;
            }

            getline(cin,entree);    // on récupère la commande de l'utilisateur
            args.clear();           //on vide la liste des arguments précédents
            Tools::Split(entree, args);     //séparation des mots clés
            if(args.size()==0)
            {
                args.push_back("");
            }
            commandType = args.front();
            args.pop_front();
        }
        return 0;
    }


