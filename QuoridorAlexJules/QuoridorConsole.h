#ifndef QUORIDORCONSOLE_H
#define QUORIDORCONSOLE_H

#include "observer.h"
#include "Game.h"

class QuoridorConsole : public nvs::Observer
{
private:
    Game game_;
public:
    QuoridorConsole(string n1, string n3, unsigned size);
    QuoridorConsole(string n1, string n2, string n3, string n4, unsigned size);
    ~QuoridorConsole();
public:
    virtual void update(const Subject *subject);
private:
    //ces deux mthodes divent demander à l'utilisateur
    // via le clavier de mover le pion ou placer un mur selon la
    //méthode appelée.
    //vous aurez bsoin de boucles qui boucleront tant que l(user
    //n'aura pas rentré des inputs valides.
    void movePion();
    void placeMur();
public:
    //gère le jeu entier, en demandant à tour de rôle, les inputs
    //aux joueurs
    void play();
};

#endif // QUORIDORCONSOLE_H
