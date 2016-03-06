#ifndef BOARD
#define BOARD
#include "Frame.h"
#include <vector>


/*!
 * \brief The Board class la classe chargée des opération sur le plateau
 */
class Board{

private:
    /*!
     * \brief len_ la longueur du coté plateau
     */
    unsigned len_;
    /*!
     * \brief plateau_ le plateau de jeu corridor
     */
    std::vector< std::vector<Frame *> > plateau_;
    /*!
     * \brief tourner methode qui a pour rôle de faire pivoter le pion vers la droite ou la gauche et en se
     * faisant changer la direction vers laquelle il pointe
     * \param cpt le compteur qui determine si il faut tourner à gauche ou aller tout droit
     * \param dir la direction vers laquelle le pion "regarde"
     * \param gauche indique si il tourne a gauche (vrai) ou si il tourne a droite(faut)
     */
    void tourner (int *cpt, Side *dir, bool gauche);
    /*!
     * \brief displace sert à faire avancer le pion dans la direction indiquée
     * \param dir la direction vers laquelle le pion avance
     * \param pos la position actuelle du pion
     */
    void displace(Side dir, std::pair<unsigned, unsigned> *pos);
    /*!
     * \brief verifWall indique si il y a un mur entre le pion courant et la case pion suivante dans
     * la direction donnée
     * \param row la ligne
     * \param column la colonne
     * \param dir la direction vers laquelle la vérification s'effectue
     * \return vrai si il n'y a pas de mur entre le pion et la case suivante
     */
    bool verifWall(unsigned row, unsigned column, Side dir);
    /*!
     * \brief verifLeftArm methode qui vérifie si il n'y a pas de mur à gauche du pion
     * \param row la ligne
     * \param column la colonne
     * \param dir la direction vers laquelle le pion pointe
     * \return
     */
    bool verifLeftArm(unsigned row, unsigned column, Side dir);
    /*!
     * \brief reachEnd A FAIRE ??????????
     * \param currFrame
     * \param obj
     * \return
     */
    bool reachEnd(Side currFrame, Side obj);
public:
    /*!
     * \brief Board constructeur du plateau de jeu quoridor
     * \param len la longueur du coté du plateau
     */
    Board(unsigned len);
    /*!
     * \brief getLen revoie la longueur du coté du plateau
     * \return la longueur du coté du plateau
     */
    inline unsigned getLen();
    /*!
     * \brief getside donne le type de coté de la case donnée
     * à savoir (Blank (cases du milieu), North, NorthWest,East,South etc...)
     * \param row la ligne
     * \param column la colonne
     * \return le type de coté de la case donnée
     */
    Side getside(unsigned row, unsigned column);
    /*!
     * \brief isFree vérifie qu'une case ne contient pas de pion et que la ligne et la colonne
     * soit compris dans les dimensions du plateau
     * \param row la ligne
     * \param column la colonne
     * \return vrai si la case demandée ne contient pas de pion
     */
    bool isFree(unsigned row, unsigned column);
    /*!
     * \brief place place un mur aux coordonnées données verticalement ou horizontalement
     * \param row la ligne
     * \param column la colonne
     * \param vertical la verticalité du mur (vrai vertical , faux horizontal)
     */
    void place(unsigned row, unsigned column, bool vertical);
    /*!
     * \brief place place un pion aux coordonnées données
     * \param row la ligne
     * \param column la colonne
     */
    void place(unsigned row, unsigned column);
    /*!
     * \brief empty retire un pion à la position cartésienne donnée
     * \param row la ligne
     * \param column la colonne
     */
    void empty(unsigned row, unsigned column);
    /*!
     * \brief empty retire un mur à la position cartésienne donnée la verticalité du mur doit etre précisé
     * \param row la ligne
     * \param column la colonne
     * \param vertical la verticalité du mur (vrai vertical , faux horizontal)
     */
    void empty(unsigned row, unsigned column, bool vertical);
    /*!
     * \brief findPath renvoie vrai si il existe un chemin entre la position donnée
     * et l'objectif (qui est un coté du plateau)
     * \param pos la postion
     * \param obj l'objectif, le coté à atteindre pour la victoire
     * \return vrai si il existe un chemin entre la position donnée
     * et l'objectif
     */
    bool findPath( std::pair<unsigned, unsigned> pos, Side obj);
    /*!
     * \brief toString l'affichage du plateau de jeu
     * \return une chaîne de caractères représentant le plateau
     */
    std::string toString();
};

/*!
 * \brief getLen revoie la longueur du coté du plateau
 * \return la longueur du coté du plateau
 */
 unsigned Board::getLen(){
    return len_;
}

#endif // BOARD

