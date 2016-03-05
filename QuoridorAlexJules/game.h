#ifndef GAME
#define GAME
#include "Board.h"
#include <vector>
#include <set>

#include "subject.h"

class Game : public nvs::Subject {
private:
    Board * board_;
    unsigned currentPlayer_ ;
    std::vector<Player> listPlayer_;

    void oblicNorth(std::set<Side> *ListOfDirections, Player p);
    void evalNorth(std::set <Side> *ListOfDirections, Player p);
    void oblicSouth(std::set <Side> *ListOfDirections, Player p);
    void evalSouth(Player p, std::set <Side> *ListOfDirections);
    void oblicEast(std::set <Side> *ListOfDirections, Player p);
    void evalEast(Player p, std::set<Side> *ListOfDirections);
    void oblicWest(std::set <Side> *ListOfDirections, Player p);
    void evalWest(std::set<Side> *ListOfDirections, Player p);
    void move (Side dir, Player & play);
    void next();
    std::set<Side> possiblePositions(Player p);
public:

    Game( std::string n1,  std::string n3, unsigned size);
    Game( std::string n1,  std::string n2,  std::string n3,  std::string n4, unsigned size);

    bool isOver();
    inline Board & getBoard();
    inline Player &getPlayer(unsigned nb);
    inline unsigned getNbP();
    std::set<Side> possiblePositions();
    bool collisionWall(Side dir, Player play);
    bool collisionPiece(Side dir, Player play);
    bool victoryCond(Player play);
    bool playWall(unsigned row, unsigned column, bool vertical);
    void move (Side dir);

};

Board &Game::getBoard(){
    return *board_;
}

Player &Game::getPlayer(unsigned nb){
    return listPlayer_[nb-1];
}

unsigned Game::getNbP(){
    return listPlayer_.size();
}

#endif // GAME

