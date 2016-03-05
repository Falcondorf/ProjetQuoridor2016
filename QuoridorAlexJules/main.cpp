#include <iostream>
#include <algorithm>
#include "QuoridorConsole.h"


using namespace std;

int main()
{
    cout << "Bienvenue dans le jeu Quoridor" << endl;
    cout << "Entrez le nombre de joueurs (2 ou 4 Joueurs)" << endl;
    int nbJoueurs =-1;

    cin >> nbJoueurs ;

    while(nbJoueurs!=2 && nbJoueurs!=4){

       cout << "ERROR : Reessayez" << endl;
       cin >> nbJoueurs ;
    }


    cout << "choisissez la taille du plateau de jeu (entre 5 et 19) de largeur" << endl;
    int taille =-1;
    cin >> taille ;
    while(taille%2==0 || taille<5 || taille>19){

       cout << "ERROR : mauvaise dimension" << endl;
       cin >> taille ;
    }

    QuoridorConsole * myConsole =nullptr;
    if(nbJoueurs==2){
        string name1;
        cout << "Entrez le nom du premier joueur" << endl;
        cin >> name1;
        while(name1.empty()){
            cout << "le nom est vide" << endl;
            cin >> name1;
        }
        string name2;
        cout << "Entrez le nom du deuxième joueur" << endl;
        cin >> name2;
        while(name2.empty()){
            cout << "le nom est vide";
            cin >> name2;
        }

        myConsole = new QuoridorConsole(name1,name2,taille);
    }else{
        string name1;
        cout << "Entrez le nom du premier joueur" << endl;
        cin >> name1;
        while(name1.empty()){
            cout << "le nom est vide" << endl;
            cin >> name1;
        }
        string name2;
        cout << "Entrez le nom du deuxième joueur" << endl;
        cin >> name2;
        while(name2.empty()){
            cout << "le nom est vide";
            cin >> name2;
        }
        string name3;
        cout << "Entrez le nom du troisième joueur" << endl;
        cin >> name3;
        while(name3.empty()){
            cout << "le nom est vide";
            cin >> name3;
        }
        string name4;
        cout << "Entrez le nom du quatrième joueur" << endl;
        cin >> name4;
        while(name4.empty()){
            cout << "le nom est vide";
            cin >> name4;
        }

        myConsole = new QuoridorConsole(name1,name2,name3,name4,taille);

    }
    myConsole->play();
    delete myConsole;
    return 0;
}

