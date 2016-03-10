#include "Frame.h"
#include <iostream>
#include "Board.h"
#include "Side.h"
#include "QuoridorExceptions.h"
using namespace std;

PlayerFrame::PlayerFrame(unsigned row, unsigned column,unsigned size){
    if(row > size || column > size){
        throw QuoridorExceptions(1,"incorrect position",1) ;
    }
    hasPiece_ = false;
    size -= 1;
    // Très important de refaire de module car il ne fonctionne pas correctement!!!
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
    return !hasPiece_;
}

string WallFrame::toString(){
    if (isWalled_){
        return "#";
    } else {
        return " ";
    }
}

bool WallFrame::isFree(){
    return !isWalled_;
}
