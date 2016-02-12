#ifndef BOARD
#define BOARD
#include "Frame.h"
#include <vector>
using namespace std;

class Board{

private:
    unsigned len_;
    std::vector<std::vector<Frame *> > plateau_;
public:
    inline Board(unsigned len);
    inline getLen();
};


 Board::getLen(){
    return len_;
}

#endif // BOARD

