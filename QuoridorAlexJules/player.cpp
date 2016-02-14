#include "Player.h"
#include <string>
#include "QuoridorExceptions.h"

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
 }
void Player::pickWall(){
    if (wallstock_==0){
        throw QuoridorExceptions(1, "No more walls", 3);
    } else {
        wallstock_-= 1;
    }
}

