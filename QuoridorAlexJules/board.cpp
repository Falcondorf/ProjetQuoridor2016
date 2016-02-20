#include "Frame.h"
#include <iostream>
#include "Board.h"
#include "QuoridorExceptions.h"

Board::Board(unsigned len) : len_(len)
{
    if(len%2==0 && len>5 && len <19){
        throw QuoridorExceptions(1,"Incorrect input of size(Only 5 to 19 and not pair",1);
    }
    unsigned hidden_len=len*2-1;
    plateau_=std::vector<std::vector<Frame *> > (hidden_len, std::vector<Frame *>(hidden_len, nullptr));
    for (unsigned i=0;i<hidden_len;i++){
        std::cout << endl;
        for (unsigned j=0;j<hidden_len;j++){
            if(i%2==0 && j%2==0){
               PlayerFrame * pf = new PlayerFrame(i,j,hidden_len);
               plateau_[i][j]= pf;


// pf meurt
            }else{
                WallFrame * wf = new WallFrame();
                plateau_[i][j]= wf;

            }
        }
    }

}

string Board::toString(){
    string str="";
    for (int i=0;i<getLen()*2-1;i++){
         str += "\n";
         for(int a=0;a<getLen()*7.7;a++){
             str+="-";
         }

        str += "\n";
        for (int j=0;j<getLen()*2-1;j++){
            if(plateau_[i][j] == nullptr){
                str += "N ";
            }else {
                str+=" | ";
                str += plateau_[i][j]->toString();
            }
        }
        str+=" |";
    }

    return str;
}
//Peut-être devoir moduler cette algo pour différencier les placements de pions et de murs
void Board::place(unsigned row, unsigned column, unsigned direction){  ;
    //Envisager cette condition afin de vérifier qu'on puisse placer un mur sans problème
    //Dans le cas d'un pion, traitement différent lié aux obstacles etc...

     unsigned hidden_len=len_*2-1;  //rendre ca GLOBAL
     if (row%2!=0 && column>=1 && column < hidden_len-1 && direction==0){
         if(!plateau_[row][column]->isWalled()&&!plateau_[row][column-1]->isWalled()&& !plateau_[row][column+1]->isWalled()){
             plateau_[row][column]->place();
             plateau_[row][column-1]->place();
             plateau_[row][column+1]->place();
         }else{
             throw QuoridorExceptions(1,"collision of walls",1);
         }

     }else if(column%2!=0 && row>=1 && row< hidden_len-1 && direction==1){
         if(!plateau_[row][column]->isWalled()&&! plateau_[row+1][column]->isWalled()&& !plateau_[row-1][column]->isWalled()){
             plateau_[row][column]->place();
             plateau_[row+1][column]->place();
             plateau_[row-1][column]->place();
         }else{
              throw QuoridorExceptions(1,"collision of walls",1);
         }
      }else{
          throw QuoridorExceptions(1,"wall wrongly placed",1);
      }
}

void Board::place(unsigned row, unsigned column){
    unsigned hidden_len=len_*2-1;  //rendre ca GLOBAL
    if (row%2==0 && column%2==0 && row<=hidden_len && column <= hidden_len){
        plateau_[row][column]->place();
    }else{
        throw QuoridorExceptions(1,"pawn wrongly placed",1);
    }
}
