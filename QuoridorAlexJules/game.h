#ifndef GAME
#define GAME
#include "Board.h"
#include <vector>

class Game {
private:

    vector<Player> listPlayer;
    bool gameover_;

public:
    Board * board_;
    Game(Player p1, Player p2, unsigned size);
    Game(Player p1, Player p2, Player p3, Player p4, unsigned size);
    inline void setOver();
    inline bool isOver();
    void move (Side dir, Player currPlay);
};

void Game::setOver(){
    gameover_ = true;
}

bool Game::isOver(){
    return gameover_;
}

#endif // GAME

