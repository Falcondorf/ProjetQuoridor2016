#include "Game.h"
#include "QuoridorExceptions.h"
#include <iostream>

Game::Game(string n1, string n2, unsigned size){
    Board * b = new Board(size);
    board_ = b;
    gameover_ = false;
    listPlayer.push_back(new Player(n1, 1, 2, size));
    listPlayer.push_back(new Player(n2, 2, 2, size));
    board_->place(*listPlayer[1]);
    board_->place(*listPlayer[2]);
}

Game::Game(string n1, string n2, string n3, string n4, unsigned size){
    /*Board * b = new Board(size);
    board_ = b;
    gameover_ = false;
    listPlayer.push_back(n1);
    std::cout << listPlayer[1].getName() << std::endl;
    listPlayer.push_back(n2);
    listPlayer.push_back(n3);
    std::cout << listPlayer[3].getName() << std::endl;
    listPlayer.push_back(n4);
    /*board_->place(listPlayer[1]);
    board_->place(listPlayer[2]);
    board_->place(listPlayer[3]);
    board_->place(listPlayer[4]);*/
}

void Game::move (Side dir, Player currPlay){
    //Gestion des collision à dévelloper ici


    //suppr bool de la case courante
    board_->empty(currPlay.getPos().first, currPlay.getPos().second);

    switch (dir){
    case Side::North:
       //déplacement du pion sur la nouvelle case
        board_->place(currPlay.getPos().first+2, currPlay.getPos().second);
        //mise à jour de la position du joueur
        currPlay.setPos(currPlay.getPos().first+2, currPlay.getPos().second);
        break;
    case Side::South:
        board_->place(currPlay.getPos().first-2, currPlay.getPos().second);
        currPlay.setPos(currPlay.getPos().first-2, currPlay.getPos().second);
        break;
    case Side::West:
        board_->place(currPlay.getPos().first, currPlay.getPos().second-2);
        currPlay.setPos(currPlay.getPos().first, currPlay.getPos().second-2);
        break;
    case Side::East:
        board_->place(currPlay.getPos().first, currPlay.getPos().second+2);
        currPlay.setPos(currPlay.getPos().first, currPlay.getPos().second+2);
        break;
    default:
        throw QuoridorExceptions(1,"Direction chosen is not appliable",1);
    }
}
