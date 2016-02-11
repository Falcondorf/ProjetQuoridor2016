#include "Player.h"
#include <string>

Player::Player(std::string thename,unsigned num,unsigned nbOfPlayer, unsigned boardSize):
    name_(thename),number_(num),win_(false){

    switch (nbOfPlayer){
    case 2:
        wallstock_=boardSize+1;
        break;
    case 4:
        wallstock_=(boardSize+1)/2;
        break;
    default:
        throw "invalid";
    }

    if (nbOfPlayer == 1) {
        isPlaying_=true;
    } else {
        isPlaying_=false;
    }
}
