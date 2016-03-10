#ifndef FRAME
#define FRAME
#include "Side.h"
#include "Player.h"

/*!
 * \brief Class gérant tout ce qui concerne les cases du plateau
 */
class Frame{
protected:
    Frame()=default;
public:
    /*!
     * \brief Méthode permettant l'affichage de représentation du contenu d'une case.
     * \return  "X" si il y a un pion à l'interieur d'une case pion "-" sinon
     * et "#" si il y a un mur à l'interieur d'une case mur et " " sinon
     */
    virtual std::string toString()=0;
    /*!
     * \brief Donne le type de coté de la case
     * \return le type de coté de la case si c'est une case pion
     *  ou blank si c 'est une case mur
     */
    virtual Side getSide()=0;
    /*!
     * \brief Place un mur ou un pion
     */
    virtual void place()=0;
    /*!
     * \brief Indique si une case mur ou pion est sans mur ou sans pion
     * \return vrai si la case est libre
     */
    virtual bool isFree()=0;
    /*!
     * \brief Vide la case donnée de ses occupants
     */
    virtual void empty()=0;
    /*!
     * \brief Destructeur de Case
     */
    virtual ~Frame()=default;
    /*!
     * \brief Constructeur par recopie.
     *
     * Le destructeur a des effets en cascade en virtuel
     */
    Frame(const Frame &)=default;
    /*!
     * \brief Constructeur par déplacement.
     *
     * Le destructeur a des effets en cascade en virtuel
     */
    Frame(Frame &&)=default;
    /*!
     * \brief Opérateur d'assignation par recopie par défaut.
     *
     * Le destructeur virtuel par défaut a des effets en cascade.
     */
    Frame &operator=(const Frame &)=default;
    /*!
     * \brief Opérateur d'assignation par déplacement par défaut.
     *
     * Le destructeur virtuel par défaut a des effets en cascade.
     */
    Frame &operator=(Frame &&)=default;
};

/*!
 * \brief Classe héritant de la classe mère Frame spécifique aux cases pouvant contenir des joueurs
 */
class PlayerFrame : public Frame{
private:
    /*!
     * \brief Indique si une case possède un pion
     */
    bool hasPiece_;
    /*!
     * \brief Indique le type de coté de la case
     */
    Side side_;

public:
    /*!
     * \brief Constructeur d'une case de joueur
     * \param row la ligne
     * \param column la colonne
     * \param size taille maximale du plateau
     */
    PlayerFrame(unsigned row, unsigned column, unsigned size);
    /*!
     * \brief Donne la direction orienté de la case. C'est-à-dire sur quel côté
     * du taleau elle se trouve par rapport au oint cardinaux.
     * \return  le type de coté de la case
     */
    inline Side getSide();
    /*!
     * \brief Place un pion à la case
     */
    inline void place();
    /*!
     * \brief Vide la case de son pion
     */
    inline void empty();
    /*!
     * \brief Indique si il y n'y a pas de pion sur la case
     * \return vrai si il y n'y a pas de pion sur la case
     */
    bool isFree();
    /*!
     * \brief Affiche si il y a un pion ou pas dans la case?
     * \return "X" si il y a un pion à l'interieur d'une case pion "_" si la case est libre
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
 * \brief Classe hérite de la classe mère Frame spécifique aux cases pouvant contenir des murs
 */
class WallFrame : public Frame{
private:
    /*!
     * \brief Attribut déterminant quand une case est murée.
     */
    bool isWalled_;

public:
    /*!
     * \brief Constructeur de case mur
     */
    inline WallFrame();
    /*!
     * \brief Donne le type de coté de la case (Tjrs blank puisque c est une case mur et
     * qu'il n'est as nécssaire de l'évalué par raport au déplacement des pions).
     * \return Le type de coté de la case
     */
    inline Side getSide();
    /*!
     * \brief Place un mur sur la case
     */
    inline void place();
    /*!
     * \brief Libère la case de son mur
     */
    inline void empty();
    /*!
     * \brief Indique si la case ne contient pas de mur
     * \return
     */
    bool isFree();
    /*!
     * \brief Affiche si il y a un mur ou pas
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

