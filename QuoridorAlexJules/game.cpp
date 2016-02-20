#include "Game.h"
#include "QuoridorExceptions.h"

Game::Game(Player p1, Player p2, unsigned size){
    Board * b = new Board(size);
    board_ = b;
    gameover_ = false;
    listPlayer.push_back(p1);
    listPlayer.push_back(p2);
}

Game::Game(Player p1, Player p2, Player p3, Player p4, unsigned size){
    Board * b = new Board(size);
    board_ = b;
    gameover_ = false;
    listPlayer.push_back(p1);
    listPlayer.push_back(p2);
    listPlayer.push_back(p3);
    listPlayer.push_back(p4);
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
