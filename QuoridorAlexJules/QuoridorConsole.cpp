#include "QuoridorConsole.h"

#include <iostream>
using namespace std;
using namespace nvs;

QuoridorConsole::QuoridorConsole(string n1, string n3, unsigned size)
    : game_(n1, n3, size)
{
    game_.registerObserver(this);
}

QuoridorConsole::QuoridorConsole(string n1, string n2, string n3, string n4, unsigned size)
    : game_(n1, n2, n3, n4, size)
{
    game_.registerObserver(this);
}

QuoridorConsole::~QuoridorConsole()
{
    game_.unregisterObserver(this);
}

void QuoridorConsole::update(const Subject *subject)
{
    if (subject!=&game_) return;
    cout << game_.getBoard().toString() << endl;
}
void QuoridorConsole::play(){
    bool gameOver=false;
    unsigned currPlayer =game_.getPlayer(1).getNum();
    while (!gameOver){

        cout<< "Tapez 1 pour placer un pion, tapez 2 pour placer un mur" << endl;
        int nb;
        cin >> nb;
        while(nb!=1 && nb!=2){
            cout << "choix invalide" << endl;
            cin >> nb;
        }
        if (nb==1){



            movePion();
        }else{
            placeMur();
        }
    }
    cout << game_.getPlayer(currPlayer).getName() << "a gagné !" << endl;
}
void QuoridorConsole::movePion(){
    set<Side> possiblePos = game_.possiblePositions(); //position possible du joueur courant
    for (Side pos : possiblePos){
        cout << toString(pos);
    }
    cout<< "Tapez N,S,E,O,NE,NO pour déplacer votre pion"<< endl;
    string direction;

    cin >> direction;
    while(direction!="n"&& direction!="s" &&direction!="e" &&
          direction!="o"&& direction!="ne"&&direction!="no"&&
          direction!="se"&&direction!="so"){
        cout << "choix invalide" << endl;
        cin >> direction;
    }
    if(direction =="n"){
        game_.move(Side::North);
    }else if(direction =="s"){
        game_.move(Side::South);
    }else if(direction =="e"){
        game_.move(Side::East);
    }else if(direction =="o"){
        game_.move(Side::West);
    }else if(direction =="ne"){
        game_.move(Side::NorthEast);
    }else if(direction =="no"){
        game_.move(Side::NorthWest);
    }else if(direction =="so"){
        game_.move(Side::SouthWest);
    }else if(direction =="se"){
        game_.move(Side::SouthEast);
    }

}

void QuoridorConsole::placeMur(){

}


