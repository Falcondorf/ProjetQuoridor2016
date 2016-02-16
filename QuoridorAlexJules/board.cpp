#include "Frame.h"
#include <iostream>
#include "Board.h"
Board::Board(unsigned len) : len_(len)
{
    unsigned hidden_len=len*2-1;
    plateau_=std::vector<std::vector<Frame *> > (hidden_len, std::vector<Frame *>(hidden_len, nullptr));
    for (unsigned i=0;i<hidden_len;i++){
        std::cout << endl;
        for (unsigned j=0;j<hidden_len;j++){
            if(i%2==0 && j%2==0){
               PlayerFrame pf = PlayerFrame(i,j,hidden_len);
               plateau_[i][j]= &pf;
               std::cout << plateau_[i][j]->toString();

            }else{
                WallFrame wf = WallFrame();
                plateau_[i][j]= &wf;
                std::cout << plateau_[i][j]->toString();
            }
        }
    }

}

string Board::toString(){
    string str="";
    for (int i=0;i<getLen()*2-1;i++){
         str += "\n";
        for (int j=0;j<getLen()*2-1;j++){
            if(plateau_[i][j] == nullptr){
                str += "N ";
            }else {
                str += plateau_[i][j]->toString();
                str+=" ";
            }
        }
    }
    return str;
}

void Board::placeWall(unsigned row, unsigned column, unsigned direction){
    plateau_[row][column];//->placeWall();
}
