#include "Frame.h"
#include "Board.h"
Board::Board(unsigned len) : len_(len)
{
    unsigned hidden_len=len*2-1;
    plateau_=std::vector<std::vector<Frame *> > (hidden_len, std::vector<Frame *>(hidden_len, nullptr));

}

string Board::toString(){
    string str="";
//    for (auto row=plateau_.begin(); row!=plateau_.end(); ++row){
//        str +=
//        str += "\n";

//        for (auto column=plateau_.begin(); column!=plateau_.end(); ++row){
//             str += plateau_[row][column] ;
//        }

//}

    for (int i=0;i<=getLen();i++){
         str += "\n";
        for (int j=0;j<=getLen();j++){
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
