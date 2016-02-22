#include "Game.h"
#include "QuoridorExceptions.h"
#include <iostream>

Game::Game(string n1, string n2, unsigned size):gameover_(false){
    Board * b = new Board(size);
    board_ = b;
    listPlayer_.push_back(Player(n1, 1, 2, size));
    listPlayer_.push_back(Player(n2, 2, 2, size));
    board_->place(listPlayer_[0].getPos().first, listPlayer_[0].getPos().second);
    board_->place(listPlayer_[1].getPos().first, listPlayer_[1].getPos().second);
}

Game::Game(string n1, string n2, string n3, string n4, unsigned size): gameover_(false){
    Board * b = new Board(size);
    board_ = b;
    listPlayer_.push_back(Player(n1,1, 4, size));
    listPlayer_.push_back(Player(n2,2, 4, size));
    listPlayer_.push_back(Player(n3,3, 4, size));
    listPlayer_.push_back(Player(n4,4, 4, size));
    board_->place(listPlayer_[0].getPos().first, listPlayer_[0].getPos().second);
    board_->place(listPlayer_[1].getPos().first, listPlayer_[1].getPos().second);
    board_->place(listPlayer_[2].getPos().first, listPlayer_[2].getPos().second);
    board_->place(listPlayer_[3].getPos().first, listPlayer_[3].getPos().second);
}

void Game::move (Side dir, Player play){
    //Gestion des collision à dévelloper ici
    if(Game::colision(dir, play)){
        throw QuoridorExceptions(1,"Mur sur le chemin, choisissez une autre voie...", 1);
    }

    //suppr bool de la case courante
    board_->empty(play.getPos().first, play.getPos().second);

    switch (dir){
    case Side::North:
       //déplacement du pion sur la nouvelle case
        board_->place(play.getPos().first-2, play.getPos().second);
        //mise à jour de la position du joueur
        play.setPos(play.getPos().first-2, play.getPos().second);
        break;
    case Side::South:
        board_->place(play.getPos().first+2, play.getPos().second);
        play.setPos(play.getPos().first+2, play.getPos().second);
        break;
    case Side::West:
        board_->place(play.getPos().first, play.getPos().second-2);
        play.setPos(play.getPos().first, play.getPos().second-2);
        break;
    case Side::East:
        board_->place(play.getPos().first, play.getPos().second+2);
        play.setPos(play.getPos().first, play.getPos().second+2);
        break;
    default:
        throw QuoridorExceptions(1,"Direction chosen is not appliable",1);
    }
}

bool Game::colision(Side dir, Player play){
    switch (dir){
    case Side::North:
        if (board_->isFree(play.getPos().first-1, play.getPos().second)){
            return true;
        } else if (!board_->isFree(play.getPos().first-2, play.getPos().second)){
            //Saut de pion
        }
        break;
    case Side::South:
        if (board_->isFree(play.getPos().first+1, play.getPos().second)){
            return true;
        } else if (!board_->isFree(play.getPos().first+2, play.getPos().second)){
            //Saut de pion
        }
        break;
    case Side::West:
        if (board_->isFree(play.getPos().first, play.getPos().second-1)){
            return true;
        } else if (!board_->isFree(play.getPos().first, play.getPos().second-2)){
            //Saut de pion
        }
        break;
    case Side::East:
        if (board_->isFree(play.getPos().first, play.getPos().second+1)){
            return true;
        } else if (!board_->isFree(play.getPos().first, play.getPos().second+2)){
            //Saut de pion
        }
        break;
    default:
        throw QuoridorExceptions(1,"Incorrect direction provided",1);
    }
    return false;
}
