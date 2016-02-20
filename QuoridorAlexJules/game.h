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
    inline Game(Board &board, Player p1, Player p2);
    inline Game(Board &board, Player p1, Player p2, Player p3, Player p4);
    inline void setOver();
    inline void isOver();
    void move (Side dir, Player currPlay);
};

Game::Game(Board &board, Player p1, Player p2){
    board_ = board;
    gameover_ = false;
    listPlayer.push_back(p1);
    listPlayer.push_back(p2);
}

Game::Game(Board &board, Player p1, Player p2, Player p3, Player p4){
    Game::Game(&board, p1, p2);
    listPlayer.push_back(p3);
    listPlayer.push_back(p4);
}

void Game::setOver(){
    gameover_ = true;
}

void Game::isOver(){
    return gameover_;
}

#endif // GAME

