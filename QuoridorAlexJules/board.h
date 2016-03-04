#ifndef BOARD
#define BOARD
#include "Frame.h"
#include <vector>

using namespace std;

class Board{

private:
    unsigned len_;
    vector<vector<Frame *> > plateau_;
    void tourner (int *cpt, Side *dir, bool gauche);
    void displace(Side dir, std::pair<unsigned, unsigned> *pos);
    bool verifWall(unsigned row, unsigned column, Side dir);
    bool verifLeftArm(unsigned row, unsigned column, Side dir);
    bool reachEnd(Side currFrame, Side obj);
public:
    Board(unsigned len);
    inline unsigned getLen();
    Side getside(unsigned row, unsigned column);
    bool isFree(unsigned row, unsigned column);
    void place(unsigned row, unsigned column, bool vertical);
    void place(unsigned row, unsigned column);
    void empty(unsigned row, unsigned column);
    void empty(unsigned row, unsigned column, bool vertical);
    bool findPath(pair<unsigned, unsigned> pos, Side obj);
    string toString();
};


 unsigned Board::getLen(){
    return len_;
}

#endif // BOARD

