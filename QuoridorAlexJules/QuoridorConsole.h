#ifndef QUORIDORCONSOLE_H
#define QUORIDORCONSOLE_H

#include "observer.h"
#include "subject.h"
#include "Game.h"
/*!
 * \brief Classe charger de gerer le déroulement de la partie
 * et l'enchainement des étapes
 */
class QuoridorConsole : public nvs::Observer
{
private:
    /*!
     * \brief La partie de Quoridor
     */
    Game * game_;
public:
    /*!
     * \brief Le constructeur du déroulement de la partie
     * \param game la partie de Quoridor
     */
    QuoridorConsole( Game * game);
    /*!
     * \brief Le destructeur de la partie
     */
    ~QuoridorConsole();
public:
    /*!
     * \brief Méthode qui affiche le Board à chaque changement d'état de la partie
     * \param subject le sujet observé
     */
    virtual void update(const nvs::Subject *subject) override;
private:
    /*!
     * \brief Méthode qui a pour rôle la gestion de déplacement du pion
     */
    void movePion();
    /*!
     * \brief Méthode qui a pour rôle la gestion de placement des murs
     */
    void placeMur();
public:
    /*!
     * \brief Gère le jeu entier, en demandant à tour de rôle, les inputs aux joueurs
     */
    void play();
    /*!
     * \brief Affiche l'écran titre du jeu.
     */
    static void displayTitle();
};

#endif // QUORIDORCONSOLE_H
