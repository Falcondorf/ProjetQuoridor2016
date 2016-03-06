#ifndef QUORIDORCONSOLE_H
#define QUORIDORCONSOLE_H

#include "observer.h"
#include "subject.h"
#include "Game.h"
/*!
 * \brief The QuoridorConsole class classe charger de gerer le déroulement de la partie
 * et l'enchainement des étapes
 */
class QuoridorConsole : public nvs::Observer
{
private:
    /*!
     * \brief game_ la partie de Quoridor
     */
    Game * game_;
public:
    /*!
     * \brief QuoridorConsole le constructeur du déroulement de la partie
     * \param game la partie de Quoridor
     */
    QuoridorConsole( Game * game);
    /*!
     * \brief ~QuoridorConsole le destructeur de la partie
     */
    ~QuoridorConsole();
public:
    /*!
     * \brief update methode qui affiche le Board à chaque changement d'état de la partie
     * \param subject le sujet observé
     */
    virtual void update(const nvs::Subject *subject) override;
private:
    /*!
     * \brief movePion methode qui a pour rôle la gestion de déplacement du pion
     */
    void movePion();
    /*!
     * \brief placeMur methode qui a pour rôle la gestion de placement des murs
     */
    void placeMur();
public:
    /*!
     * \brief play gère le jeu entier, en demandant à tour de rôle, les inputs aux joueurs
     */
    void play();
};

#endif // QUORIDORCONSOLE_H
