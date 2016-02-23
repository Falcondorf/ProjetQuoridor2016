#ifndef GAME
#define GAME
#include "Board.h"
#include <vector>

class Game {
private:
    Board * board_;
    vector<Player> listPlayer_;
    bool gameover_;

public:

    Game(string n1, string n3, unsigned size);
    Game(string n1, string n2, string n3, string n4, unsigned size);
    inline void setOver();
    inline bool isOver();
    inline Board & getBoard();
    inline Player getPlayer(unsigned nb);
    void move (Side dir, Player play);
    bool collision(Side dir, Player play);
    bool victoryCond(Player play);
};

void Game::setOver(){
    gameover_ = true;
}

bool Game::isOver(){
    return gameover_;
}

Board &Game::getBoard(){
    return *board_;
}

Player Game::getPlayer(unsigned nb){
    return listPlayer_[nb-1];
}

#endif // GAME

