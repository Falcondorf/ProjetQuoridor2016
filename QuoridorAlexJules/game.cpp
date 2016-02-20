#include "Game.h"
#include "QuoridorExceptions.h"

void Game::move (Side dir, Player currPlay){
    switch (dir){
    case Side::North:
        board_->empty(currPlay.getPos().first, currPlay.getPos().second);//suppr bool de la case courante
        board_->place(currPlay.getPos().first+2, currPlay.getPos().second);//déplacement du pion sur la nouvelle case
        //mise à jour de la position du joueur
        break;
    default:
        throw QuoridorExceptions(1,"Direction chosen is not appliable",1);
    }
}
