#include "Frame.h"
#include <iostream>
#include "Board.h"
#include "Side.h"
using namespace std;

PlayerFrame::PlayerFrame(unsigned row, unsigned column,unsigned size){
    if(row > size || column > size){
        throw "incorrect position";
    }
    hasPiece_ = false;

    if(row==0){
        if(column==0){
            //nord ouest
            side_ =Side::NorthWest;
        }else if(column == size){
            //nord est
            side_ =Side::NorthEast;
        }else{
            //nord
            side_ =Side::North;
        }
    }else if(row == size){
        if(column==0){
            //sud ouest
            side_ =Side::SouthWest;
        }else if(column == size){
            //sud est
            side_ =Side::SouthEast;
        }else{
            //sud
            side_ =Side::South;
        }
    }else if(column==0){
        //ouest
        side_ =Side::West;
    }else if(column == size){
        //est
        side_ =Side::East;
    }else{
        //blank
        side_ =Side::Blank;
    }
}

string PlayerFrame::toString(){
    if (hasPiece_){
        return "X";
    } else {
        return "_";
    }
}

bool PlayerFrame::isFree(){
    if (hasPiece_==true){
        return false;
    }else{
        return true;
    }
}

string WallFrame::toString(){
    if (isWalled()){
        return "#";
    } else {
        return " ";
    }
}

bool WallFrame::isFree(){
    if (isWalled()==true){
        return false;
    }else{
        return true;
    }
}
