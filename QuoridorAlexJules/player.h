#ifndef PLAYER
#define PLAYER
#include <string>
#include "Side.h"

/*!
 * \brief Classe définissant un joueur et les interactions qu'il peut faire lors du jeu.
 */
class Player{
private:
    /*!
     * \brief Le nom du joueur
     */
    std::string name_;
    /*!
     * \brief Le numéro du joueur
     */
    unsigned number_;
    /*!
     * \brief La condition verifiant si le joueur a gagné la partie
     */
    bool win_ = false;
    /*!
     * \brief Le côté qu'un joueur doit atteindre pour gagné la partie
     */
    Side sideObjective_;
    /*!
     * \brief Le nombre de mur restant au joueur
     */
    unsigned wallstock_;
    /*!
     * \brief La osition du joueur dans le plateau
     */
    std::pair<unsigned, unsigned> pos_;

public:
    /*!
     * \brief Constructeur de joueur.
     * \param thename Le nom du joueur.
     * \param num Le numéro d'ordre du joueur.
     * \param nbOfPlayer Le nombre de joueur dans la partie.
     * \param boardSize La taille du plateau de jeu.
     */
    Player(std::string thename, unsigned num, unsigned nbOfPlayer, unsigned boardSize) ;
    /*!
     * \brief Accesseur qui retourne le nom du joueur.
     * \return  Retourne le nom du joueur.
     */
    inline std::string getName();
    /*!
     * \brief Accesseur qui retourne le numéro d'ordre du joueur.
     * \return Retourne le numéro du joueur.
     */
    inline unsigned getNum();
    /*!
     * \brief Accesseur qui retourne le booléen définissant si un joueur est gagnant.
     * \return Retourne le boolée définissant si le joueur est vainqueur.
     */
    inline bool hasWon();
    /*!
     * \brief Mutateur permettant de passer un joueur à l'état de vainqueur.
     */
    inline void setWin();
    /*!
     * \brief Accesseur retournant le nombre de murs que le joueur peut encore poser sur le plateau.
     * \return Retourne le nombre de mur encore posable.
     */
    inline unsigned getWallstock();
    /*!
     * \brief Méthode retirant un mur du stock du joueur
     */
    void pickWall();
    /*!
     * \brief Accesseur de position du joueur.
     * \return  Retourne la position du joueur.
     */
    inline std::pair<unsigned, unsigned> getPos();
    /*!
     * \brief Mutateur de position, On modifir l'emplacement du joueur sur le plateau.
     * \param row La ligne dans le plateau de jeu
     * \param column La colonne dans le plateau de jeu
     */
    inline void setPos(unsigned row, unsigned column);
    /*!
     * \brief Accesseur du côté que doit atteindre le joueur.
     * \return Retourne le côté objectif attribué au joueur.
     */
    inline Side getObjective();
};

std::string Player::getName(){
    return name_;
}
unsigned Player::getNum(){
    return number_;
}
bool Player::hasWon(){
    return win_;
}
void Player::setWin(){
    win_=true;
}

unsigned Player::getWallstock(){
    return wallstock_;
}

std::pair<unsigned, unsigned> Player::getPos(){
    return pos_;
}

void Player::setPos(unsigned row, unsigned column){
    pos_.first = row;
    pos_.second = column;
}
Side Player::getObjective(){
    return sideObjective_;
}

#endif // PLAYER

