#ifndef BOARD
#define BOARD
#include "Frame.h"
#include <vector>

/*!
 * \brief Classe chargée des opération sur le plateau.
 */
class Board{

private:
    /*!
     * \brief La longueur du coté plateau
     */
    unsigned len_;
    /*!
     * \brief Le plateau de jeu corridor
     */
    std::vector< std::vector<Frame *> > plateau_;
    /*!
     * \brief Méthode qui a pour rôle de faire pivoter le pion vers la droite ou
     * la gauche et en se faisant changer la direction vers laquelle il pointe
     * \param cpt le compteur qui determine si il faut tourner à gauche ou aller tout droit
     * \param dir la direction vers laquelle le pion "regarde"
     * \param gauche indique si il tourne a gauche (vrai) ou si il tourne a droite(faut)
     */
    void tourner (int *cpt, Side *dir, bool gauche);
    /*!
     * \brief Sert à faire avancer le pion dans la direction indiquée
     * \param dir la direction vers laquelle le pion avance
     * \param pos la position actuelle du pion
     */
    void displace(Side dir, std::pair<unsigned, unsigned> *pos);
    /*!
     * \brief Indique si il y a un mur entre le pion courant et la case pion suivante dans
     * la direction donnée
     * \param row la ligne
     * \param column la colonne
     * \param dir la direction vers laquelle la vérification s'effectue
     * \return vrai si il n'y a pas de mur entre le pion et la case suivante
     */
    bool verifWall(unsigned row, unsigned column, Side dir);
    /*!
     * \brief Méthode qui vérifie si il n'y a pas de mur à gauche du pion
     * \param row la ligne
     * \param column la colonne
     * \param dir la direction vers laquelle le pion pointe
     * \return
     */
    bool verifLeftArm(unsigned row, unsigned column, Side dir);
    /*!
     * \brief Lors de l'évaluation de position, cette méthode sert à arrêter le processus
     * lorsque la case évaluée est de même valeur que l'objectif.
     * \param currFrame La case sur laquelle on passe l'évaluation.
     * \param obj La direction d'objectif.
     * \return Retourne Vrai si la case évalué à la même valeure de direction que l'objectif.
     */
    bool reachEnd(Side currFrame, Side obj);
public:
    /*!
     * \brief Constructeur du plateau de jeu quoridor
     * \param len la longueur du coté du plateau
     */
    Board(unsigned len);
    /*!
     * \brief Destructeur de plateau du jeu
     */
    ~Board();
    /*!
     * \brief On evite ainsi la construction par copie
     * \param board un pointeur de plateau
     */
    Board(const Board &board)=delete;
    /*!
     * \brief On evite d'attribuer un plateau par copie
     * \param board un pointeur de plateau
     * \return pas de retour
     */
    Board &operator=(const Board &board)=delete;
    /*!
     * \brief On evite la construction par recopie
     */
    Board(const Board &&)=delete;
    /*!
     * \brief On evite l'attribution par recopie
     * \return aucun retour
     */
    Board &operator=(const Board &&)=delete;
    /*!
     * \brief Renvoie la longueur du coté du plateau
     * \return la longueur du coté du plateau
     */
    inline unsigned getLen();
    /*!
     * \brief Donne le type de coté de la case donnée
     * à savoir (Blank (cases du milieu), North, NorthWest,East,South etc...)
     * \param row la ligne
     * \param column la colonne
     * \return le type de coté de la case donnée
     */
    Side getside(unsigned row, unsigned column);
    /*!
     * \brief Vérifie qu'une case ne contient pas de pion et que la ligne et la colonne
     * soit compris dans les dimensions du plateau
     * \param row la ligne
     * \param column la colonne
     * \return vrai si la case demandée ne contient pas de pion
     */
    bool isFree(unsigned row, unsigned column);
    /*!
     * \brief Place un mur aux coordonnées données verticalement ou horizontalement
     * \param row la ligne
     * \param column la colonne
     * \param vertical la verticalité du mur (vrai vertical , faux horizontal)
     */
    void place(unsigned row, unsigned column, bool vertical);
    /*!
     * \brief Place un pion aux coordonnées données
     * \param row la ligne
     * \param column la colonne
     */
    void place(unsigned row, unsigned column);
    /*!
     * \brief Retire un pion à la position cartésienne donnée
     * \param row la ligne
     * \param column la colonne
     */
    void empty(unsigned row, unsigned column);
    /*!
     * \brief Retire un mur à la position cartésienne donnée la verticalité du mur
     * doit etre précisé
     * \param row la ligne
     * \param column la colonne
     * \param vertical la verticalité du mur (vrai vertical , faux horizontal)
     */
    void empty(unsigned row, unsigned column, bool vertical);
    /*!
     * \brief Renvoie vrai si il existe un chemin entre la position donnée
     * et l'objectif (qui est un coté du plateau)
     * \param pos la postion
     * \param obj l'objectif, le coté à atteindre pour la victoire
     * \return vrai si il existe un chemin entre la position donnée
     * et l'objectif
     */
    bool findPath( std::pair<unsigned, unsigned> pos, Side obj);
    /*!
     * \brief Affichage du plateau de jeu
     * \return une chaîne de caractères représentant le plateau
     */
    std::string toString();
};

 unsigned Board::getLen(){
    return len_;
}

#endif // BOARD

