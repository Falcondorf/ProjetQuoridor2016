#ifndef GAME
#define GAME
#include "Board.h"
#include <vector>
#include <set>

#include "subject.h"

/*!
 * \brief Classe Game gérant les interactions entre les joueurs et le plateau de jeu.
 * Surtout tout ce qui concerne les mouvements et les déplacements.
 */
class Game : public nvs::Subject {
private:
    /*!
     * \brief attribut définissant le plateau de jeu.
     */
    Board board_;
    /*!
     * \brief attribut définissant le joueur courant. Soit celui qui est en train de jouer.
     */
    unsigned currentPlayer_ ;
    /*!
     * \brief attribut liste des joueurs de la partie.
     */
    std::vector<Player> listPlayer_;

    /*!
     * \brief Lors de la phase d'évaluation des directions de déplacements possible,
     * évaluation du cas des obliques nord.
     * \param ListOfDirections Set acceuillant les directions de déplacement possible.
     * \param p Le joueur autour duquel on évalue les déplacement possible.
     */
    void oblicNorth(std::set<Side> *ListOfDirections, Player p);
    /*!
     * \brief Lors de la phase d'évaluation des directions de déplacements possible,
     * évaluation des cas au nord.
     * \param ListOfDirections Set acceuillant les directions de déplacement possible.
     * \param p Le joueur autour duquel on évalue les déplacement possible.
     */
    void evalNorth(std::set <Side> *ListOfDirections, Player p);
    /*!
     * \brief Lors de la phase d'évaluation des directions de déplacements possible,
     * évaluation des obliques sud.
     * \param ListOfDirections Set acceuillant les directions de déplacement possible.
     * \param p Le joueur autour duquel on évalue les déplacement possible.
     */
    void oblicSouth(std::set <Side> *ListOfDirections, Player p);
     /*!
     * \brief Lors de la phase d'évaluation des directions de déplacements possible,
     * évaluation des cas au sud.
     * \param ListOfDirections Set acceuillant les directions de déplacement possible.
     * \param p Le joueur autour duquel on évalue les déplacement possible.
     */
    void evalSouth(Player p, std::set <Side> *ListOfDirections);
    /*!
     * \brief Lors de la phase d'évaluation des directions de déplacements possible,
     * évaluation des obliques est.
     * \param ListOfDirections Set acceuillant les directions de déplacement possible.
     * \param p Le joueur autour duquel on évalue les déplacement possible.
     */
    void oblicEast(std::set <Side> *ListOfDirections, Player p);
    /*!
     * \brief Lors de la phase d'évaluation des directions de déplacements possible,
     * évaluation des cas à l'est.
     * \param ListOfDirections Set acceuillant les directions de déplacement possible.
     * \param p Le joueur autour duquel on évalue les déplacement possible.
     */
    void evalEast(Player p, std::set<Side> *ListOfDirections);
    /*!
     * \brief Lors de la phase d'évaluation des directions de déplacements possible,
     * évaluation des obliques ouest.
     * \param ListOfDirections Set acceuillant les directions de déplacement possible.
     * \param p Le joueur autour duquel on évalue les déplacement possible.
     */
    void oblicWest(std::set <Side> *ListOfDirections, Player p);
    /*!
     * \brief Lors de la phase d'évaluation des directions de déplacements possible,
     * évaluation des cas à l'ouest.
     * \param ListOfDirections Set acceuillant les directions de déplacement possible.
     * \param p Le joueur autour duquel on évalue les déplacement possible.
     */
    void evalWest(std::set<Side> *ListOfDirections, Player p);
    /*!
     * \brief Cette méthode a pour but de déplcer un pion dans une direction donnée.
     * \param dir La direction vers laquelle se déplace le pion.
     * \param play Le joueur qui va être déplacé.
     * \return un booléen qui exprime si le déplacement s'est bien effectué.
     */
    bool move(Side dir, Player & play);
    /*!
     * \brief Cette méthode change le joueur courant vers le suivant.
     */
    void next();
    /*!
     * \brief Cette méthode calcule toutes le directions vers lesquelles un joueur
     * peut légalement se déplacer.
     * \param p Le joueur à qui ont veut évaluer les positions possibles de déplacements.
     * \return Retourne un set (éviter les doublons) contenant les directions de déplacements
     * possibles.
     */
    std::set<Side> possiblePositions(Player p);
public:
    /*!
     * \brief Constructeur de partie à deux joueurs.
     * \param n1 Le nom du premier joueur.
     * \param n3 Le nom du second joueur.
     * \param size La taille du tableau (<19, >5, impair).
     */
    Game( std::string n1,  std::string n3, unsigned size);
    /*!
     * \brief Constructeur de partie à deux joueurs.
     * \param n1 Le nom du premier joueur.
     * \param n2 Le nom du second joueur.
     * \param n3 Le nom du troisième joueur.
     * \param n4 Le nom du quatrième joueur.
     * \param size La taille du tableau (<19, >5, impair).
     */
    Game( std::string n1,  std::string n2,  std::string n3,  std::string n4, unsigned size);
    /*!
     * \brief Méthode de contrôle de fin de partie.
     * \return Déclare lorsqu'une partie est Game Over. Ecrit le nom du vainqueur.
     */
    bool isOver();
    /*!
     * \brief Cette méthode à pour fonction de retourner le joueur numéro nb.
     * \param nb le numéro du joueur.
     * \return Retourne le joueur numéro nb.
     */
    inline Player &getPlayer(unsigned nb);
    /*!
     * \brief Accesseur du nombre de joueur dans la partie.
     * \return retounre le nombre de joueurs dans la partie.
     */
    inline unsigned getNbP();
    /*!
     * \brief Accesseur de joueur courant.
     * return Retourne le joueur courant.
     */
    inline unsigned getCurrentPlayer();
    /*!
     * \brief Méthode fabriquant un set de toutes les directions que le joueur courant
     * peut choisir avant de se déplacer.
     * \return Retourne un set (éviter les doublons) des directions que le joueur courant
     * peut emprunter avant de se déplacer.
     */
    std::set<Side> possiblePositions();
    /*!
     * \brief Méthode vérifiant que dans une certaines direction, un joueur peut
     * se cogner contre un mur.
     * \param dir La direction à évaluer.
     * \param play Le joueur autour duquel on évalue la possibilité de se cogner.
     * \return retourne vrai si le joueur se cogne dans la direction évaluée.
     */
    bool collisionWall(Side dir, Player play);
    /*!
     * \brief Méthode vérifiant que dans une certaines direction, un joueur peut
     * rencontrer un autre pion.
     * \param dir La direction à évaluer.
     * \param play Le joueur autour duquel on évalue la possibilité de
     * rencontrer un autre joueurs.
     * \return retourne Vrai si le joueur en rencontre un autre.
     */
    bool collisionPiece(Side dir, Player play);
    /*!
     * \brief Cette méthode évalue si un pion a atteint son objectif.
     * \param play Le joueur dont on vérifie s'il a atteint son objectif.
     * \return retourne vrai lorsqu'un pion a atteint son objectif.
     */
    bool victoryCond(Player play);
    /*!
     * \brief Méthode permettant au joueur de choisir où placer un mur dans le plateau.
     * \param row La ligne du plateau
     * \param column La colonne du plateau
     * \param vertical Booléen désigant si la position est verticale ou non
     * \return Retourne Vrai si le placement du mur s'est bien déroulé.
     */
    bool playWall(unsigned row, unsigned column, bool vertical);
    /*!
     * \brief Méthode permettant de déplacer le joueur courant vers une direction donnée.
     * \param dir La direction du déplacement souhaité.
     * \return Retourne Vrai si le déplacement s'est bien effectué.
     */
    bool move(Side dir);
    /*!
     * \brief Méthode permettant l'affichage du plateau de jeu via la partie actuelle.
     * \return Retourne le plateau sous forme d'une chaîne.
     */
    inline std::string stringBoard();
};

Player &Game::getPlayer(unsigned nb){
    return listPlayer_[nb-1];
}

unsigned Game::getNbP(){
    return listPlayer_.size();
}

unsigned Game::getCurrentPlayer(){
    return currentPlayer_;
}

std::string Game::stringBoard(){
    return board_.toString();
}

#endif // GAME

