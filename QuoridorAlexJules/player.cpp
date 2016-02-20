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

    switch (nbOfPlayer){
       case 4:
           if(num == 3){
               sideObjective_ = Side::West;
           } else if(num == 4){
               sideObjective_ = Side::East;
           }
       case 2:
           if(num == 1){
               sideObjective_ = Side::North;
           } else if (num == 2){
               sideObjective_ = Side::South;
           } else {
               throw QuoridorExceptions(1,"Incorrect order number for player",1);
           }
           break;
       default:
           throw QuoridorExceptions(2,"Incorrect number of player provided",2);
       }
 }
void Player::pickWall(){
    if (wallstock_==0){
        throw QuoridorExceptions(1, "No more walls", 3);
    } else {
        wallstock_-= 1;
    }
}

