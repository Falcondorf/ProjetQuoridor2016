#ifndef FRAME
#define FRAME
#include "Side.h"
#include "Player.h"

/*!
 * \brief The Frame class gere tout ce qui concerne les cases du plateau
 */
class Frame{
protected:
    Frame()=default;
public:
    /*!
     * \brief toString
     * \return  "X" si il y a un pion à l'interieur d'une case pion "-" sinon
     * et "#" si il y a un mur à l'interieur d'une case mur et " " sinon
     */
    virtual std::string toString()=0;
    /*!
     * \brief getSide donne le type de coté de la case
     * \return le type de coté de la case si c'est une case pion
     *  ou blank si c 'est une case mur
     */
    virtual Side getSide()=0;
    /*!
     * \brief place un mur ou un pion
     */
    virtual void place()=0;
    /*!
     * \brief isFree indique si une case mur ou pion est sans mur ou sans pion
     * \return vrai si la case est libre
     */
    virtual bool isFree()=0;
    /*!
     * \brief empty vide la case donnée de ses occupants
     */
    virtual void empty()=0;
};

/*!
 * \brief The PlayerFrame class hérite de la classe mere Frame
 * est spécifique aux cases aux cases pouvant contenir des joueurs
 */
class PlayerFrame : public Frame{
private:
    /*!
     * \brief hasPiece_ indique si une case possède un pion
     */
    bool hasPiece_;
    /*!
     * \brief side_ indique le type de coté de la case
     */
    Side side_;

public:
    /*!
     * \brief PlayerFrame constructeur d'une case de joueur
     * \param row la ligne
     * \param column la colonne
     * \param size taille maximale du plateau
     */
    PlayerFrame(unsigned row, unsigned column, unsigned size);
    /*!
     * \brief getSide donne  le type de coté de la case
     * \return  le type de coté de la case
     */
    inline Side getSide();
    /*!
     * \brief place un pion à la case
     */
    inline void place();
    /*!
     * \brief empty libère la case de son pion
     */
    inline void empty();
    /*!
     * \brief isFree indique si il y n'y a pas de pion sur la case
     * \return vrai si il y n'y a pas de pion sur la case
     */
    bool isFree();
    /*!
     * \brief toString affiche si il y a un pion ou pas
     * \return "X" si il y a un pion à l'interieur d'une case pion "-" sinon
     */
    std::string toString();

};

void PlayerFrame::place(){
    hasPiece_=true;
}

Side PlayerFrame::getSide(){
    return side_;
}

void PlayerFrame::empty(){
    hasPiece_=false;
}

/*!
 * \brief The WallFrame class hérite de la classe mere Frame
 * est spécifique aux cases pouvant contenir des murs
 */
class WallFrame : public Frame{
private:
    /*!
     * \brief isWalled_ indique si il y a un mur sur la case
     */
    bool isWalled_;

public:
    /*!
     * \brief WallFrame constructeur des cases mur
     */
    inline WallFrame();
    /*!
     * \brief getSide donne  le type de coté de la case (blank puisque c est une case mur)
     * \return le type de coté de la case
     */
    inline Side getSide();
    /*!
     * \brief place place un mur sur la case
     */
    inline void place();
    /*!
     * \brief empty libère la case de son mur
     */
    inline void empty();
    /*!
     * \brief isFree indique si la case ne contient pas de mur
     * \return
     */
    bool isFree();
    /*!
     * \brief toString affiche si il y a un mur ou pas
     * \return "#" si il y a un mur à l'interieur d'une case mur et " " sinon
     */
    std::string toString();
};

WallFrame::WallFrame() : Frame(){
    isWalled_=false;
}

void WallFrame::place(){
    isWalled_=true;
}

void WallFrame::empty(){
    isWalled_=false;
}

Side WallFrame::getSide(){return Side::Blank;}
#endif // FRAME

