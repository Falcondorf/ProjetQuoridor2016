#include "QuoridorConsole.h"
#include "keyboard.hpp"
#include <iostream>

using namespace std;
using namespace nvs;

QuoridorConsole::QuoridorConsole(Game *game)
    : game_(game)
{
    cout << game_->stringBoard() << endl;
    game_->registerObserver(this);
}

QuoridorConsole::~QuoridorConsole()
{
    game_->unregisterObserver(this);
}

void QuoridorConsole::update(const Subject *subject)
{
    if (subject!=game_) return;
    cout << game_->stringBoard() << endl;
}
void QuoridorConsole::play(){

    while (!game_->isOver()){
        cout << "A " << game_->getPlayer(game_->getCurrentPlayer()).getName() << " de jouer" << endl;
        if (game_->getPlayer(game_->getCurrentPlayer()).getWallstock()==0
                && game_->possiblePositions().empty()){
            cout << "Match nul; plus de mur ni aucun déplacment possible." << endl;
            return;
        } else if (game_->getPlayer(game_->getCurrentPlayer()).getWallstock()==0){
            cout << "Plus de mur vous devez vous déplacer." << endl;
            movePion();
        } else if (game_->possiblePositions().empty()){
            cout << "Vous n'avez aucun déplacement possible mais vous pouvez poser des murs." << endl;
            placeMur();
        } else {
            cout<< "Tapez 1 pour placer un pion, tapez 2 pour placer un mur" << endl;
            int nb;
            //cin >> nb;
            try {
                nb = lineFromKbd<int>();
            } catch (exception const & e){
                cerr << e.what() << endl;
            }

            while(nb!=1 && nb!=2){
                cout << "choix d'action invalide" << endl;
                //cin >> nb;
                try {
                    nb = lineFromKbd<int>();
                } catch (exception const & e){
                    cerr << e.what() << endl;
                }
            }
            if (nb==1){
                movePion();
            }else{
                placeMur();
            }
        }
    }
    cout << game_->getPlayer(game_->getCurrentPlayer()-1%game_->getNbP()).getName() << " a gagne en "
         << toString(game_->getPlayer(game_->getCurrentPlayer()-1%game_->getNbP()).getObjective()) << endl;
}
void QuoridorConsole::movePion(){
    bool moveAccepted = false;
    while (!moveAccepted){
        set<Side> possiblePos = game_->possiblePositions(); //position possible du joueur courant
        for (Side pos : possiblePos){
            cout << toString(pos) << endl;
        }
        cout<< "Tapez N, S, E, W, NE, NW, SE, SW pour déplacer votre pion"<< endl;
        string direction;

        //cin >> direction;
        direction = lineFromKbd<string>();

        while(direction!="N"&& direction!="S" &&direction!="E" &&
              direction!="W"&& direction!="NE"&&direction!="NW"&&
              direction!="SE"&&direction!="SW"){
            cout << "choix de direction invalide" << endl;
            //cin >> direction;
            direction = lineFromKbd<string>();
        }

        if(direction =="N"){
            moveAccepted = game_->move(Side::North);
        }else if(direction =="S"){
            moveAccepted = game_->move(Side::South);
        }else if(direction =="E"){
            moveAccepted = game_->move(Side::East);
        }else if(direction =="W"){
            moveAccepted = game_->move(Side::West);
        }else if(direction =="NE"){
            moveAccepted = game_->move(Side::NorthEast);
        }else if(direction =="NW"){
            moveAccepted = game_->move(Side::NorthWest);
        }else if(direction =="SW"){
            moveAccepted = game_->move(Side::SouthWest);
        }else if(direction =="SE"){
            moveAccepted = game_->move(Side::SouthEast);
        }
        if (!moveAccepted){
            cout << "Mouvement non autorisé, Réessayez" << endl;
        }
    }
}

void QuoridorConsole::placeMur(){
     unsigned row;
     unsigned column;
     bool vertical;
     bool hasPlayed=false;
     while (!hasPlayed){
         cout << "Il vous reste: " << game_->getPlayer(game_->getCurrentPlayer()).getWallstock() << endl;
         cout<< "Entrez les coordonnées du milieu du mur que vous souhaitez placer"<< endl;
         cout << "la ligne : ";
         //cin>>row;
         try {
             row = lineFromKbd<unsigned>();
         } catch (exception const & e){
             cerr << e.what() << endl;
         }

         cout << "la colonne : ";
         //cin>>column;
         try {
             column = lineFromKbd<unsigned>();
         } catch (exception const & e){
             cerr << e.what() << endl;
         }
         cout<< "Entrez 1 pour un mur vertical, 0 pour horizontal"<< endl;
         //cin >> vertical ;
         try {
             vertical = lineFromKbd<bool>();
         } catch (exception const & e){
             cerr << e.what() << endl;
         }
         try{
         hasPlayed = game_->playWall(row,column,vertical);
         }catch(std::exception const & e){
             cerr << "ERROR: " << e.what() << endl;
         }
     }

}

void QuoridorConsole::displayTitle(){
    cout << ".______    __   _______ .__   __. ____    ____  _______ .__   __.  __    __   _______\n"
            "|   _  \\  |  | |   ____||  \\ |  | \\   \\  /   / |   ____||  \\ |  | |  |  |  | |   ____|\n"
            "|  |_)  | |  | |  |__   |   \\|  |  \\   \\/   /  |  |__   |   \\|  | |  |  |  | |  |__\n"
            "|   _  <  |  | |   __|  |  . `  |   \\      /   |   __|  |  . `  | |  |  |  | |   __|\n"
            "|  |_)  | |  | |  |____ |  |\\   |    \\    /    |  |____ |  |\\   | |  `--'  | |  |____\n"
            "|_______  |__| ________|.__| \\__.     \\_______.|_______||__| \\__|  \\______/  |_______|\n"
            "|       \\     /   \\     |  \\ |  |     /       |\n"
            "|  .--.  |   /  ^  \\    |   \\|  |    |   (----`\n"
            "|  |  |  |  /  /_\\  \\   |  . `  |     \\   \\\n"
            "|  '--'  | /  _____  \\  |  |\\   | .----)   |\n"
            "|_______/ /__/__   \\__\\ |_______| |.______/     __   _______   ______   .______\n"
            " /  __  \\    |  |  |  |  /  __  \\  |   _  \\    |  | |       \\ /  __  \\  |   _  \\\n"
            "|  |  |  |   |  |  |  | |  |  |  | |  |_)  |   |  | |  .--.  |  |  |  | |  |_)  |\n"
            "|  |  |  |   |  |  |  | |  |  |  | |      /    |  | |  |  |  |  |  |  | |      /\n"
            "|  `--'  '--.|  `--'  | |  `--'  | |  |\\  \\----|  | |  '--'  |  `--'  | |  |\\  \\----.\n"
            " \\_____\\_____\\\\______/   \\______/  | _| `._____|__| |_______/ \\______/  | _| `._____|"<< endl;
}
