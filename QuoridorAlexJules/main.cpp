#include <iostream>
#include <algorithm>
#include "QuoridorConsole.h"
#include "keyboard.hpp"

using namespace std;
using namespace nvs;

int main()
{
    cout << "Bienvenue dans le jeu Quoridor" << endl;
    cout << "Entrez le nombre de joueurs (2 ou 4 Joueurs)" << endl;
    int nbJoueurs =-1;

    //cin >> nbJoueurs ;
    try {
        nbJoueurs = lineFromKbd<int>();
    }catch (exception const & e){
        cerr << e.what() << endl;
    }

    while(nbJoueurs!=2 && nbJoueurs!=4){
       cout << "ERROR : Reessayez" << endl;
       //cin >> nbJoueurs ;
       try{
        nbJoueurs = lineFromKbd<int>();
       } catch(exception const & e){
           cerr << e.what() << endl;
       }
    }

    cout << "choisissez la taille du plateau de jeu (entre 5 et 19) de largeur" << endl;
    int taille =-1;
    //cin >> taille ;
    try{
     taille = lineFromKbd<int>();
    } catch (exception const & e){
        cerr << e.what() << endl;
    }

    while(taille%2==0 || taille<5 || taille>19){

       cout << "ERROR : mauvaise dimension" << endl;
       //cin >> taille ;
       try{
        taille = lineFromKbd<int>();
       } catch (exception const & e){
           cerr << e.what() << endl;
       }
    }

    Game * game =nullptr;
    if(nbJoueurs==2){
        string name1;
        cout << "Entrez le nom du premier joueur" << endl;
        //cin >> name1;
        name1 = lineFromKbd<string>();
        while(name1.empty()){
            cout << "le nom est vide" << endl;
            //cin >> name1;
            name1 = lineFromKbd<string>();
        }
        string name2;
        cout << "Entrez le nom du deuxième joueur" << endl;
        //cin >> name2;
        name2 = lineFromKbd<string>();
        while(name2.empty()){
            cout << "le nom est vide";
            //cin >> name2;
            name2 = lineFromKbd<string>();
        }

        game = new Game(name1,name2,taille);
    }else{
        string name1;
        cout << "Entrez le nom du premier joueur" << endl;
        //cin >> name1;
        name1 = lineFromKbd<string>();
        while(name1.empty()){
            cout << "le nom est vide" << endl;
            //cin >> name1;
            name1 = lineFromKbd<string>();
        }
        string name2;
        cout << "Entrez le nom du deuxième joueur" << endl;
        //cin >> name2;
        name2 = lineFromKbd<string>();
        while(name2.empty()){
            cout << "le nom est vide";
            //cin >> name2;
            name2 = lineFromKbd<string>();
        }
        string name3;
        cout << "Entrez le nom du troisième joueur" << endl;
        //cin >> name3;
        name3 = lineFromKbd<string>();
        while(name3.empty()){
            cout << "le nom est vide";
            //cin >> name3;
            name3 = lineFromKbd<string>();
        }
        string name4;
        cout << "Entrez le nom du quatrième joueur" << endl;
        //cin >> name4;
        name4 = lineFromKbd<string>();
        while(name4.empty()){
            cout << "le nom est vide";
            //cin >> name4;
            name4 = lineFromKbd<string>();
        }

        game = new Game(name1,name2,name3,name4,taille);

    }
    QuoridorConsole myConsole(game);

    myConsole.play();

    delete game;
    return 0;
}

