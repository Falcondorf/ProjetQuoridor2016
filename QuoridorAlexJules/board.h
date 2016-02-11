#ifndef BOARD
#define BOARD
#include "Frame.h";

class Board{

private:
    unsigned len_;
    std::vector<std::vector<Frame *>> plateau;
public:
    inline Board(unsigned len);
};

Board::Board(unsigned len) : len_(len)
{
    unsigned hidden_len=len*2-1;
    plateau=vector<vector<Frame *>>(hidden_len, vector<Frame *>(hidden_len, nullptr);
    //TODO :
    //assigner les cases

}
#endif // BOARD

