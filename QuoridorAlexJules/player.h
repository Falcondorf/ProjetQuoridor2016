#ifndef PLAYER
#define PLAYER
#include <string>
#include "Side.h"

class Player{
private:
    std::string name_;
    unsigned number_;
    bool win_ = false;
    Side sideObjective_;
    unsigned wallstock_;

public:
    inline Player();
    Player(std::string thename, unsigned num, unsigned nbOfPlayer, unsigned boardSize) ;
    inline std::string getName();
    inline unsigned getNum();
    inline bool hasWon();
    inline unsigned getWallstock();
    void pickWall();


};

Player::Player(){}
    std::string Player::getName(){
    return name_;
}
unsigned Player::getNum(){
    return number_;
}
bool Player::hasWon(){
    return win_;
}
unsigned Player::getWallstock(){
    return wallstock_;
}


#endif // PLAYER

