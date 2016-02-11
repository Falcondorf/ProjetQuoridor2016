#include "Frame.h"
#include "Board.h"
using namespace std;

PlayerFrame::PlayerFrame(unsigned row, unsigned column,unsigned size){

    if(row==0){
        if(column==0){
            //nord ouest
        }else if(column == Board::len_){
            //nord est
        }else{
            //nord
        }
    }else if(row ==Board::getlen()){
        if(column==0){
            //sud ouest
        }else if(column == Board::len_){
            //sud est
        }else{
            //sud
        }
    }else if(column==0){
        //ouest
    }else if(column == Board::len_){
        //est
    }else{
        //blank
    }


    if(row ==Board::len_ && column == Board::len_ ){
        //sud est
    }

}
