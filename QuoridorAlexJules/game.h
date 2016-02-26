#ifndef GAME
#define GAME
#include "Board.h"
#include <vector>

class Game {
private:
    Board * board_;
    vector<Player> listPlayer_;
    bool gameover_;

    void oblicNorth(std::vector <Side> ListOfDirections, Player p);

    void evalNorth(std::vector <Side> ListOfDirections, Player p);

    void oblicSouth(std::vector <Side> ListOfDirections, Player p);

    void evalSouth(Player p, std::vector <Side> ListOfDirections);

    void oblicEast(std::vector <Side> ListOfDirections, Player p);

    void evalEast(Player p, std::vector <Side> ListOfDirections);

    void oblicWest(std::vector <Side> ListOfDirections, Player p);

    void evalWest(std::vector <Side> ListOfDirections, Player p);

public:

    Game(string n1, string n3, unsigned size);
    Game(string n1, string n2, string n3, string n4, unsigned size);
    inline void setOver();
    inline bool isOver();
    inline Board & getBoard();
    inline Player &getPlayer(unsigned nb);
    void move (Side dir, Player & play);
    bool collisionWall(Side dir, Player play);
    bool collisionPiece(Side dir, Player play);
    bool victoryCond(Player play);
    std::vector<Side> possiblePositions(Player p);
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

Player &Game::getPlayer(unsigned nb){
    return listPlayer_[nb-1];
}

#endif // GAME

