#include "Game.h"
#include "QuoridorExceptions.h"
#include <iostream>

using namespace std;

Game::Game(string n1, string n2, unsigned size)
    :board_(size), currentPlayer_(1){
    listPlayer_.push_back(Player(n1, 1, 2, size));
    listPlayer_.push_back(Player(n2, 2, 2, size));
    board_.place(getPlayer(1).getPos().first, getPlayer(1).getPos().second);
    board_.place(getPlayer(2).getPos().first, getPlayer(2).getPos().second);
}

Game::Game(string n1, string n2, string n3, string n4, unsigned size)
    :board_(size), currentPlayer_(1){
    listPlayer_.push_back(Player(n1,1, 4, size));
    listPlayer_.push_back(Player(n2,2, 4, size));
    listPlayer_.push_back(Player(n3,3, 4, size));
    listPlayer_.push_back(Player(n4,4, 4, size));
    for (unsigned i=1; i<=4;i++){
        board_.place(getPlayer(i).getPos().first, getPlayer(i).getPos().second);
    }

}

bool Game::move (Side dir, Player &play){
    auto directions = possiblePositions(play);
    if (directions.find(dir) == directions.end()){
        return false;
    }
    //suppr bool de la case courante
    board_.empty(play.getPos().first, play.getPos().second);

    switch (dir){
    case Side::North:
        //revérif si pion pour saut pion
        if(!board_.isFree(play.getPos().first-2, play.getPos().second)){
            board_.place(play.getPos().first-4, play.getPos().second);
            play.setPos(play.getPos().first-4, play.getPos().second);
        }else{
           //déplacement du pion sur la nouvelle case
            board_.place(play.getPos().first-2, play.getPos().second);
            //mise à jour de la position du joueur
            play.setPos(play.getPos().first-2, play.getPos().second);
        }
        break;
    case Side::South:
        if(!board_.isFree(play.getPos().first+2, play.getPos().second)){
            board_.place(play.getPos().first+4, play.getPos().second);
            play.setPos(play.getPos().first+4, play.getPos().second);
        }else{
            board_.place(play.getPos().first+2, play.getPos().second);
            play.setPos(play.getPos().first+2, play.getPos().second);
        }
        break;
    case Side::West:
        if(!board_.isFree(play.getPos().first, play.getPos().second-2)){
            board_.place(play.getPos().first, play.getPos().second-4);
            play.setPos(play.getPos().first, play.getPos().second-4);
        }else{
            board_.place(play.getPos().first, play.getPos().second-2);
            play.setPos(play.getPos().first, play.getPos().second-2);
        }
        break;
    case Side::East:
        if(!board_.isFree(play.getPos().first, play.getPos().second+2)){
            board_.place(play.getPos().first, play.getPos().second+4);
            play.setPos(play.getPos().first, play.getPos().second+4);
        }else{
            board_.place(play.getPos().first, play.getPos().second+2);
            play.setPos(play.getPos().first, play.getPos().second+2);
        }
        break;
    case Side::NorthWest:
        board_.place(play.getPos().first-2, play.getPos().second-2);
        play.setPos(play.getPos().first-2, play.getPos().second-2);
        break;
    case Side::NorthEast:
        board_.place(play.getPos().first-2, play.getPos().second+2);
        play.setPos(play.getPos().first-2, play.getPos().second+2);
        break;
    case Side::SouthWest:
        board_.place(play.getPos().first+2, play.getPos().second-2);
        play.setPos(play.getPos().first+2, play.getPos().second-2);
        break;
    case Side::SouthEast:
        board_.place(play.getPos().first+2, play.getPos().second+2);
        play.setPos(play.getPos().first+2, play.getPos().second+2);
        break;
    default:
        throw QuoridorExceptions(1,"Direction chosen is not appliable",1);
    }
    next();
    notifyObservers();
    return true;
}

bool Game::collisionWall(Side dir, Player play){
    switch (dir){
    case Side::North:
        return !board_.isFree(play.getPos().first-1, play.getPos().second);
        break;
    case Side::South:
        return !board_.isFree(play.getPos().first+1, play.getPos().second);
        break;
    case Side::West:
        return !board_.isFree(play.getPos().first, play.getPos().second-1);
        break;
    case Side::East:
        return !board_.isFree(play.getPos().first, play.getPos().second+1);
        break;
    default:
        throw QuoridorExceptions(1,"Incorrect direction provided",1);
    }
}

bool Game::collisionPiece(Side dir, Player play){
    switch (dir){
    case Side::North:
        return !board_.isFree(play.getPos().first-2, play.getPos().second);
        break;
    case Side::South:
        return !board_.isFree(play.getPos().first+2, play.getPos().second);
        break;
    case Side::West:
        return !board_.isFree(play.getPos().first, play.getPos().second-2);
        break;
    case Side::East:
        return !board_.isFree(play.getPos().first, play.getPos().second+2);
        break;
    default:
        throw QuoridorExceptions(1,"Incorrect direction provided",1);
    }
    return false;
}
void Game::oblicNorth(std::set<Side> *ListOfDirections, Player p){
    if(board_.isFree(p.getPos().first-2,p.getPos().second+1)
            && board_.isFree(p.getPos().first-2, p.getPos().second+2)){ //droit libre
         ListOfDirections->insert(Side::NorthEast);
    }
    if(board_.isFree(p.getPos().first-2,p.getPos().second-1)
            && board_.isFree(p.getPos().first-2, p.getPos().second-2)){ //gauche libre
        ListOfDirections->insert(Side::NorthWest);
    }
}

void Game::evalNorth(std::set<Side> *ListOfDirections, Player p){
    if (!collisionWall(Side::North,p)){ //pas de mur
        if(!collisionPiece(Side::North,p)){ //pas de piece
            ListOfDirections->insert(Side::North);
        }else{
            //saut ou oblique
            if(board_.isFree(p.getPos().first-3, p.getPos().second)){ //pas de mur derrière la pièce
                if(board_.isFree(p.getPos().first-4, p.getPos().second)){ //pas de pion -> saut
                     ListOfDirections->insert(Side::North);
                }else{
                    oblicNorth(ListOfDirections, p);
                }
            }else{ //il y a soit un mur soit un pion -> oblique droit ou gauche
                oblicNorth(ListOfDirections, p);
            }
        }
    }
}

void Game::oblicSouth(std::set<Side> *ListOfDirections, Player p){
    if(board_.isFree(p.getPos().first+2,p.getPos().second-1)
            && board_.isFree(p.getPos().first+2, p.getPos().second-2)){ //gauche libre
         ListOfDirections->insert(Side::SouthWest);
    }
    if(board_.isFree(p.getPos().first+2,p.getPos().second+1)
            && board_.isFree(p.getPos().first+2, p.getPos().second+2)){ //droit libre
        ListOfDirections->insert(Side::SouthEast);
    }
}

void Game::evalSouth(Player p, std::set <Side> *ListOfDirections){
    if (!collisionWall(Side::South,p)){ //pas de mur
        if(!collisionPiece(Side::South,p)){ //pas de piece
            ListOfDirections->insert(Side::South);
        }else{
            //saut ou oblique
            if(board_.isFree(p.getPos().first+3, p.getPos().second)){ //pas de mur derrière la pièce
                if(board_.isFree(p.getPos().first+4, p.getPos().second)){ //pas de pion -> saut
                     ListOfDirections->insert(Side::South);
                }else{
                    oblicSouth(ListOfDirections, p);
                }
            }else{ //il y a soit un mur soit un pion -> oblique droit ou gauche
               oblicSouth(ListOfDirections, p);
            }
        }
    }
}

void Game::oblicEast(std::set<Side> *ListOfDirections, Player p){
    if(board_.isFree(p.getPos().first-1,p.getPos().second+2)
            && board_.isFree(p.getPos().first-2, p.getPos().second+2)){ //haut libre
         ListOfDirections->insert(Side::NorthEast);
    }

    if(board_.isFree(p.getPos().first+1,p.getPos().second+2)
            && board_.isFree(p.getPos().first+2, p.getPos().second+2)){ //bas libre
        ListOfDirections->insert(Side::SouthEast);
    }
}

void Game::evalEast(Player p, std::set <Side> *ListOfDirections){
    if (!collisionWall(Side::East,p)){ //pas de mur
        if(!collisionPiece(Side::East,p)){ //pas de piece
            ListOfDirections->insert(Side::East);
        }else{
            //saut ou oblique
            if(board_.isFree(p.getPos().first, p.getPos().second+3)){ //pas de mur derrière la pièce
                if(board_.isFree(p.getPos().first, p.getPos().second+4)){ //pas de pion -> saut
                     ListOfDirections->insert(Side::East);
                }else{
                    oblicEast(ListOfDirections, p);
                }
            }else{ //il y a soit un mur soit un pion -> oblique droit ou gauche
                oblicEast(ListOfDirections, p);
            }
        }
    }
}

void Game::oblicWest(std::set<Side> *ListOfDirections, Player p){
    if(board_.isFree(p.getPos().first-1,p.getPos().second-2)
            && board_.isFree(p.getPos().first-2, p.getPos().second-2)){ //haut libre
         ListOfDirections->insert(Side::NorthWest);
    }
    if(board_.isFree(p.getPos().first+1,p.getPos().second-2)
            && board_.isFree(p.getPos().first+2, p.getPos().second-2)){ //bas libre
        ListOfDirections->insert(Side::SouthWest);
    }
}

void Game::evalWest(std::set<Side> *ListOfDirections, Player p){
    if (!collisionWall(Side::West,p)){ //pas de mur
        if(!collisionPiece(Side::West,p)){ //pas de piece
            ListOfDirections->insert(Side::West);
        }else{ //saut ou oblique
            if(board_.isFree(p.getPos().first, p.getPos().second-3)){ //pas de mur derrière la pièce
                if(board_.isFree(p.getPos().first, p.getPos().second-4)){ //pas de pion -> saut
                     ListOfDirections->insert(Side::West);
                }else{
                    oblicWest(ListOfDirections, p);
                }
            }else{ //il y a soit un mur soit un pion -> oblique droit ou gauche
                 oblicWest(ListOfDirections, p);
            }
        }
    }
}

std::set <Side> Game::possiblePositions(Player p){
    std::set <Side> ListOfDirections;
    evalNorth(&ListOfDirections, p);
    evalSouth(p, &ListOfDirections);
    evalEast(p, &ListOfDirections);
    evalWest(&ListOfDirections, p);
    return ListOfDirections;
}

bool Game::victoryCond(Player play){
    Side bSide;
    bSide = board_.getside(play.getPos().first, play.getPos().second);
    switch (play.getObjective()){
    case Side::North:
        return (bSide == Side::North || bSide == Side::NorthEast || bSide == Side::NorthWest);
        break;
    case Side::South:
        return (bSide == Side::South || bSide == Side::SouthEast || bSide == Side::SouthWest);
        break;
    case Side::West:
        return (bSide == Side::West || bSide == Side::NorthWest || bSide == Side::SouthWest);
        break;
    case Side::East:
        return (bSide == Side::East || bSide == Side::NorthEast || bSide == Side::SouthEast);
        break;
    default:
        throw QuoridorExceptions(1,"invalid objective provided", 1);
    }
}
bool Game::playWall(unsigned row, unsigned column, bool vertical){
    board_.place(row,column,vertical);
    for(unsigned i=1;i<=getNbP();i++){
        if(!board_.findPath(make_pair(getPlayer(i).getPos().first,getPlayer(i).getPos().second),getPlayer(i).getObjective())){
            //enelver le mur
            board_.empty( row,column,vertical);
            return false;
        }
    }
    getPlayer(currentPlayer_).pickWall();
    next();
    notifyObservers();
    return true;
}
std::set<Side> Game::possiblePositions(){
    return possiblePositions(getPlayer(currentPlayer_));
}
bool Game::move (Side dir){
    return move(dir,getPlayer(currentPlayer_));
}
void Game::next(){
    if(getNbP()==4){
        currentPlayer_ = (currentPlayer_%4)+1; //ca marche
    }else{
        currentPlayer_ = (currentPlayer_%2)+1; //ca marche
    }
}
bool Game::isOver(){
        for (unsigned i=1;i<= getNbP();i++ ){
            if(victoryCond(getPlayer(i))){
                return true;
            }
         }
    return false;
}
