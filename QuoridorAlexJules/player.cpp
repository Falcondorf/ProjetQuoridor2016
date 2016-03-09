#include "Player.h"
#include <string>
#include "QuoridorExceptions.h"

Player::Player(std::string thename,unsigned num,unsigned nbOfPlayer, unsigned boardSize):
    name_(thename),number_(num),win_(false){

    unsigned altSize = boardSize*2-1;

    switch (nbOfPlayer){
    case 2:
        wallstock_=boardSize+1;
        break;
    case 4:
        wallstock_=(boardSize+1)/2;
        break;
    default:
        throw QuoridorExceptions(1,"Incorrect number of player",1);
    }

    switch (nbOfPlayer){
       case 4:
           if(num == 3){
               setPos(altSize/2, 0);//formule position ouest
               sideObjective_ = Side::East;//onjectif Est
           } else if(num == 4){
               setPos(altSize/2, altSize-1);//formule position est
               sideObjective_ = Side::West;//objectif Ouest
           }
       case 2:
           if(num == 1){
               setPos(altSize-1, altSize/2);//formule position nord
               sideObjective_ = Side::North;
           } else if (num == 2){
               setPos(0, altSize/2);//formule position sud
               sideObjective_ = Side::South;
           } /*else {
               throw QuoridorExceptions(1,"Incorrect order number for player",1);
           }
           break;*/
       default:
            if(num != 1 && num!= 2 && num != 3 && num !=4){
             throw QuoridorExceptions(2,"Incorrect number for the player",2);
            }
       }
 }
void Player::pickWall(){
    if (wallstock_==0){
        throw QuoridorExceptions(1, "No more walls", 3);
    } else {
        wallstock_-= 1;
    }
}

