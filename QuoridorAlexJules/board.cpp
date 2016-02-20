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
    //row ne peut pas etre égal à
    switch(direction){
    case 0:
        //Placement de pièce à l'horizontale à prévoir
        plateau_[row][column]->place();
        plateau_[row][column-1]->place();
        plateau_[row][column+1]->place();
        break;
    case 1:
        //Placement de pièce à la verticale à prévoir
        plateau_[row][column]->place();
        plateau_[row+1][column]->place();
        plateau_[row-1][column]->place();

        break;
    default:
        throw QuoridorExceptions(1,"Incorrect case of direction: Only 0 or 1",1);
     }


}
void Board::place(unsigned row, unsigned column){
        plateau_[row][column]->place();
}
