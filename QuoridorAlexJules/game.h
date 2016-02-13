#ifndef GAME
#define GAME
#include "Board.h"
#include <vector>
#include <string>

class Game {
private:
    Board * board_;
    vector<unsigned> listPlayer;

public:
    inline Game(Board &board, std::string name1, std::string name2);
    inline Game(Board &board, std::string name1, std::string name2, std::string name3, std::string name4);
};

Game::Game(Board &board, string name1, string name2){
    board_ = board;
    listPlayer.push_back(name1);
    listPlayer.push_back(name2);
}

Game::Game(Board &board, string name1, string name2, string name3, string name4){
    Game::Game(&board, name1, name2);
    listPlayer.push_back(name3);
    listPlayer.push_back(name4);
}

#endif // GAME

