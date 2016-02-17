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
    void place(unsigned row, unsigned column, unsigned direction);
    string toString();
};


 int Board::getLen(){
    return len_;
}

#endif // BOARD

