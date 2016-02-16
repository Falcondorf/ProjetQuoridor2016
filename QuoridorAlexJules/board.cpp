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
                //joueur
               PlayerFrame pf = PlayerFrame(i,j,hidden_len);
              // std::cout << pf.toString();
                plateau_[i][j]= &pf;
                std::cout << plateau_[i][j]->toString();

            }else{
                WallFrame wf = WallFrame();
               //  std::cout << wf.toString();
                 plateau_[i][j]= &wf;
                 std::cout << plateau_[i][j]->toString();
                //mur
            }
        }
    }

}

string Board::toString(){
    string str="";
    std::cout << "debug :"<<str;
    for (int i=0;i<getLen()*2-1;i++){
         str += "\n";
        std::cout << "debug :"<<str;
        for (int j=0;j<getLen()*2-1;j++){
             std::cout << "debug :"<<str;
            if(plateau_[i][j] == nullptr){
                 std::cout << "debug :"<<str;
                str += "N ";
            }else {
                 std::cout << "debug :"<<str;
                str += plateau_[i][j]->toString();
                 std::cout << "debug :"<<str;
                str+=" ";
            }
        }
    }
    return str;
}
