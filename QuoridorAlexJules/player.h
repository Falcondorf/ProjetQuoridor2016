#ifndef PLAYER
#define PLAYER
#include <string>
class Player{
private:
    std::string name_;
    unsigned number_;
    bool isPlaying_;
    bool win_ = false;
    unsigned wallstock_;
public:
    inline Player();

    Player(std::string thename, unsigned num, unsigned nbOfPlayer, unsigned boardSize) ;
    
};

Player::Player(){

}

#endif // PLAYER

