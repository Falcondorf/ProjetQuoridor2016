#ifndef PLAYER
#define PLAYER
#include <string>
#include "Side.h"

/*!
 * \brief Classe définissant un joueur et les interactions qu'il peut faire lors du jeu.
 */
class Player{
private:
    std::string name_;
    unsigned number_;
    bool win_ = false;
    Side sideObjective_;
    unsigned wallstock_;
    std::pair<unsigned, unsigned> pos_;

public:
    inline Player();
    Player(std::string thename, unsigned num, unsigned nbOfPlayer, unsigned boardSize) ;
    inline std::string getName();
    inline unsigned getNum();
    inline bool hasWon();
    inline void setWin();
    inline unsigned getWallstock();
    void pickWall();
    inline std::pair<unsigned, unsigned> getPos();
    inline void setPos(unsigned row, unsigned column);
    inline Side getObjective();
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
void Player::setWin(){
    win_=true;
}

unsigned Player::getWallstock(){
    return wallstock_;
}

std::pair<unsigned, unsigned> Player::getPos(){
    return pos_;
}

void Player::setPos(unsigned row, unsigned column){
    pos_.first = row;
    pos_.second = column;
}
Side Player::getObjective(){
    return sideObjective_;
}

#endif // PLAYER

