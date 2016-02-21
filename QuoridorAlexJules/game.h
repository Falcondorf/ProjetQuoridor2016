#ifndef GAME
#define GAME
#include "Board.h"
#include <vector>

class Game {
private:
    Board * board_;
    vector<Player *> listPlayer;
    bool gameover_;

public:

    Game(string n1, string n3, unsigned size);
    Game(string n1, string n2, string n3, string n4, unsigned size);
    inline void setOver();
    inline bool isOver();
    inline Board & getBoard();
    void move (Side dir, Player currPlay);
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

#endif // GAME

