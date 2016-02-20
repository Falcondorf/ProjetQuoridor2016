#ifndef GAME
#define GAME
#include "Board.h"
#include <vector>

class Game {
private:
    Board * board_;
    vector<Player> listPlayer;
    bool gameover_;

public:
    inline Game(Player p1, Player p2, unsigned size);
    inline Game(Player p1, Player p2, Player p3, Player p4, unsigned size);
    inline void setOver();
    inline bool isOver();
    void move (Side dir, Player currPlay);
};

Game::Game(Player p1, Player p2, unsigned size){
    Board * b = new Board(size);
    board_ = b;
    gameover_ = false;
    listPlayer.push_back(p1);
    listPlayer.push_back(p2);
}

Game::Game(Player p1, Player p2, Player p3, Player p4, unsigned size){
    Board * b = new Board(size);
    board_ = b;
    gameover_ = false;
    listPlayer.push_back(p1);
    listPlayer.push_back(p2);
    listPlayer.push_back(p3);
    listPlayer.push_back(p4);
}

void Game::setOver(){
    gameover_ = true;
}

bool Game::isOver(){
    return gameover_;
}

#endif // GAME

