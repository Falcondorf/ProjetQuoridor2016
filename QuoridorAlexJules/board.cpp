#include "Board.h"
Board::Board(unsigned len) : len_(len)
{
    unsigned hidden_len=len*2-1;
    plateau_=std::vector<std::vector<Frame *> > (hidden_len, std::vector<Frame *>(hidden_len, nullptr));

}
/*  En pleine réflexion....
string Board::toString(){
    string str="";
    for (auto row=plateau_.begin(); row!=plateau_.end(); ++row){
        str += "\n";
        for (auto column=plateau_.begin(); column!=plateau_.end(); ++row){

        }
    }
}*/
