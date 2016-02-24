#ifndef BOARD
#define BOARD
#include "Frame.h"
#include <vector>

using namespace std;

class Board{

private:
    unsigned len_;
    vector<vector<Frame *> > plateau_;
public:
    Board(unsigned len);
    inline int getLen();
    Side getside(unsigned row, unsigned column);
    bool isFree(unsigned row, unsigned column);
    void place(unsigned row, unsigned column, unsigned direction);
    void place(unsigned row, unsigned column);
    void empty(unsigned row, unsigned column);

    string toString();
};


 int Board::getLen(){
    return len_;
}

#endif // BOARD

