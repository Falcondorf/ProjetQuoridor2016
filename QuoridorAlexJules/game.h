#ifndef GAME
#define GAME
#include "Board.h"
#include <vector>

class Game {
private:
    Board * board_;
    vector<Player> listPlayer;

public:
    inline Game(Board &board, Player p1, Player p2);
    inline Game(Board &board, Player p1, Player p2, Player p3, Player p4);
};

Game::Game(Board &board, Player p1, Player p2){
    board_ = board;
    listPlayer.push_back(p1);
    listPlayer.push_back(p2);
}

Game::Game(Board &board, Player p1, Player p2, Player p3, Player p4){
    Game::Game(&board, p1, p2);
    listPlayer.push_back(p3);
    listPlayer.push_back(p4);
}

#endif // GAME

