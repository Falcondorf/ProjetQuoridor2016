#include "Frame.h"
#include <tuple>
#include <iostream>
#include <algorithm>
#include "Board.h"
#include "QuoridorExceptions.h"

using namespace std;

Board::Board(unsigned len) : len_(len)
{
    if(len%2==0 || len<5 || len >19){
        throw QuoridorExceptions(1, "Incorrect input of size(Only 5 to 19 and not pair)", 1);
    }
    unsigned hidden_len=len*2-1;
    plateau_=std::vector<std::vector<Frame *> > (hidden_len, std::vector<Frame *>(hidden_len, nullptr));
    for (unsigned i=0;i<hidden_len;i++){
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

Board::~Board(){
    unsigned size=getLen()*2-1;
    for (unsigned i=0;i<size;i++){
        for (unsigned j=0;j<size;j++){
            delete plateau_[i][j];
        }
    }
}

string Board::toString(){
    string str="  ";
   for (unsigned f=0;f<getLen()*2-1;f++){
       if (f< 10){
            str += "   ";
             str += std::to_string(f);
       }else{
           str += "  ";
          str += std::to_string(f);
       }
   }
    for (unsigned i=0;i<getLen()*2-1;i++){
         str +=" \n";
         for(unsigned a=0;a<getLen()*7.9;a++){
             str+="-";
         }
        str += "\n";
        if (i<10){
           str +=" ";
           str += std::to_string(i);
        }else{
             str += std::to_string(i);
        }
        for (unsigned j=0;j<getLen()*2-1;j++){
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

bool Board::isFree(unsigned row, unsigned column){
    return row < getLen()*2-1 && column < getLen()*2-1 && plateau_[row][column]->isFree();
}

//Peut-être devoir moduler cette algo pour différencier les placements de pions et de murs
void Board::place(unsigned row, unsigned column, bool vertical){
    //Envisager cette condition afin de vérifier qu'on puisse placer un mur sans problème
    //Dans le cas d'un pion, traitement différent lié aux obstacles etc...

     unsigned hidden_len=len_*2-1;  //rendre ca GLOBAL
     if (row%2!=0 &&column%2!=0 && column>=1 && column < hidden_len-1 && !vertical){
         if(plateau_[row][column]->isFree()&&plateau_[row][column-1]->isFree()&& plateau_[row][column+1]->isFree()){
             plateau_[row][column]->place();
             plateau_[row][column-1]->place();
             plateau_[row][column+1]->place();
         }else{
             throw QuoridorExceptions(1,"collision of walls",1);
         }

     }else if(column%2!=0 && row%2!=0 && row>=1 && row< hidden_len-1 && vertical ){
         if(plateau_[row][column]->isFree()&& plateau_[row+1][column]->isFree()&& plateau_[row-1][column]->isFree()){
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

void Board::empty(unsigned row, unsigned column, bool vertical){
    unsigned hidden_len=len_*2-1;  //rendre ca GLOBAL
    if (row%2!=0 &&column%2!=0 && column>=1 && column < hidden_len-1 && !vertical){
        if(!plateau_[row][column]->isFree()&&!plateau_[row][column-1]->isFree()&& !plateau_[row][column+1]->isFree()){
            plateau_[row][column]->empty();
            plateau_[row][column-1]->empty();
            plateau_[row][column+1]->empty();
        }else{
            throw QuoridorExceptions(1,"There is no wall here",1);
        }

    }else if(column%2!=0 && row%2!=0 && row>=1 && row< hidden_len-1 && vertical ){
        if(!plateau_[row][column]->isFree()&& !plateau_[row+1][column]->isFree()&& !plateau_[row-1][column]->isFree()){
            plateau_[row][column]->empty();
            plateau_[row+1][column]->empty();
            plateau_[row-1][column]->empty();
        }else{
             throw QuoridorExceptions(1,"There is no wall here",1);
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

void Board::empty(unsigned row, unsigned column){
    unsigned hidden_len=len_*2-1;  //rendre ca GLOBAL
    if (row%2==0 && column%2==0 && row<=hidden_len && column <= hidden_len){
        plateau_[row][column]->empty();
    }else{
        throw QuoridorExceptions(1,"pawn wrongly placed",1);
    }
}
Side Board::getside(unsigned row, unsigned column){
    return plateau_[row][column]->getSide();
}

void Board::tourner(int *cpt, Side *dir, bool gauche){
    switch (*dir){
    case Side::North:
        if (gauche){
            *dir = Side::West;
            *cpt -= 1;
        } else {
            *dir = Side::East;
            *cpt += 1;
        }
        break;
    case Side::South:
        if (gauche){
            *dir = Side::East;
            *cpt -= 1;
        } else {
            *dir = Side::West;
            *cpt += 1;
        }
        break;
    case Side::East:
        if (gauche){
            *dir = Side::North;
            *cpt -= 1;
        } else {
            *dir = Side::South;
            *cpt += 1;
        }
        break;
    case Side::West:
        if (gauche){
            *dir = Side::South;
            *cpt -= 1;
        } else {
            *dir = Side::North;
            *cpt += 1;
        }
        break;
    default:
        throw QuoridorExceptions(1,"Not applicable side(tourner)" ,1);
    }
}

void Board::displace(Side dir, std::pair<unsigned, unsigned> *pos){
    switch (dir){
    case Side::North:
        pos->first -= 2 ;
        break;
    case Side::South:
        pos->first += 2;
        break;
    case Side::West:
        pos->second -=2;
        break;
    case Side::East:
        pos->second += 2;
        break;
    default:
        throw QuoridorExceptions(1,"Not applicable Side(displace)", 1);
    }
}
//renvoie true si pas de mur face à soi et true si pas le vide
bool Board::verifWall(unsigned row, unsigned column, Side dir){
    unsigned hidden_len=len_*2-1;
    switch (dir){
    case Side::North:
        return row-1<hidden_len && plateau_[row-1][column]->isFree() ;
        break;
    case Side::South:
        return row+1<hidden_len && plateau_[row+1][column]->isFree();
        break;
    case Side::West:
        return column-1<hidden_len && plateau_[row][column-1]->isFree();
        break;
    case Side::East:
        return column+1<hidden_len &&  plateau_[row][column+1]->isFree();
        break;
    default:
        throw QuoridorExceptions(1,"Not applicable Side(verifWall)", 1);
    }
}
//renvoie true lorsque le bras est dans le vent
bool Board::verifLeftArm(unsigned row, unsigned column, Side dir){
     unsigned hidden_len=len_*2-1;
    switch (dir){
    case Side::North:
        return column-1<hidden_len &&  plateau_[row][column-1]->isFree();
        break;
    case Side::South:
        return  column+1<hidden_len && plateau_[row][column+1]->isFree();
        break;
    case Side::West:
        return row+1<hidden_len && plateau_[row+1][column]->isFree();
        break;
    case Side::East:
        return row-1<hidden_len && plateau_[row-1][column]->isFree();
        break;
    default:
        throw QuoridorExceptions(1,"Not applicable Side", 1);
    }
}

bool Board::reachEnd(Side currFrame, Side obj){
    switch (currFrame){
    case Side::North: return obj == Side::North;break;
    case Side::NorthWest: return obj == Side::North || obj == Side::West;break;
    case Side::NorthEast: return obj == Side::North || obj == Side::East;break;
    case Side::South: return obj == Side::South;break;
    case Side::SouthWest: return obj == Side::South || obj == Side::West;break;
    case Side::SouthEast: return obj == Side::South || obj == Side::East;break;
    case Side::West: return obj == Side::West;break;
    case Side::East: return obj == Side::East;break;
    case Side::Blank: return false;
    }
    throw QuoridorExceptions(1, "Bug", 1);
}

bool Board::findPath(pair<unsigned, unsigned> pos, Side obj){
    vector<tuple<pair<unsigned,unsigned>,int >> save;
    int cpt =0;
    Side nose =obj;
    bool blocked =false;
    while (!reachEnd(getside(pos.first, pos.second), obj) && !blocked && cpt<15){
        if (cpt == 0){
            //avancer juqu'au mur : move until wall
            if (verifWall(pos.first, pos.second, nose)){
                save.push_back(std::make_tuple(pos,cpt));
                displace(nose, &pos);
            } else { //si mur cpt + 1 et tourner vers la droite
                tourner(&cpt, &nose, false);

            }
        } else {
            //vérif bras gauche (si bras contre mur, vérif nez:Si il y
            // a pas de mur devant on avance Sinon tourner droite et cpt + 1
            //Si bras dans le vent, tourner gauche cpt - 1)
            if (verifLeftArm(pos.first, pos.second, nose)){
                tourner(&cpt, &nose, true);
                save.push_back(std::make_tuple(pos,cpt));
                displace(nose, &pos);
            } else {
                if (verifWall(pos.first, pos.second, nose)){
                    save.push_back(std::make_tuple(pos,cpt));
                    displace(nose, &pos); //avancer
                } else {
                    tourner(&cpt, &nose, false);
                }
            }
        }
        tuple<pair<unsigned,unsigned>,int>  search;
        search= std::make_tuple(pos,cpt);
        auto it = find (save.begin(), save.end(), search);
        if (it != save.end()){
            blocked=true;
        }
        if (cpt >= 15){
            blocked = true;
        }
    }
    return !blocked;   // evalPath renvoie true si il existe un chemin (pas blocké)
}
