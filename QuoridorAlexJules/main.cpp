#include <iostream>
#include <algorithm>
#include "Game.h"

using namespace std;

int main()
{
    /*-------------Tests sur joueurs-------------------------*/
    Player j1("Alex", 1, 4, 5);

    try{
        Player jerr("Error", 7, 3, 9);
    }catch(std::exception const& e){
        cerr << "ERROR: "<< e.what() << endl;
    }

    cout << j1.getName() << ", numero: " << j1.getNum() << " a gagne? ";
    cout << boolalpha;
    cout << j1.hasWon() << endl;
    cout << noboolalpha;
    cout << "Nombre de mur restant: " << j1.getWallstock() << endl;
    j1.pickWall();
    cout << "Nombre de mur restant: " << j1.getWallstock() << endl;
    for (int i=1; i<=2; i++){
        j1.pickWall();
    }
    cout << "Nombre de mur restant: " << j1.getWallstock() << endl;
    try{
      j1.pickWall();
      cout << "Nombre de mur restant: " << j1.getWallstock() << endl;
    }catch(std::exception const& e){
        cerr << "ERROR: "<< e.what() << endl;
    }
    cout << "Posi: " << j1.getPos().first << ", " << j1.getPos().second << endl;

    /*-------------Tests sur cases--------------------------*/
    PlayerFrame frm(0, 0, 9);
    cout << frm.toString() << " + Side: "<< toString(frm.getSide()) << endl;

    Frame * frm2;
    frm2 = &frm;
    cout << frm2->toString() << endl;

    /*--------------Tests sur plateau----------------------------*/
    try{
        Board platErr(6);
    }catch (std::exception const& e){
        cerr << "ERROR: " << e.what() << endl;
    }
    Board plat(9);
    cout << plat.toString() << endl;
    plat.place(1,11,1); // par surcharge on place un mur vertical
    plat.place(1,9,0);
    plat.place(0,0); //on place un pion
    cout << plat.toString() << endl;

    /*---------------Tests sur le jeux----------------------*/
    Game testG("Alex", "Jules","Marty", "Vanessa", 5);
    //testG.getBoard().place(0, 8);
    cout << testG.getPlayer(2).getName() << "::" << testG.getPlayer(2).getPos().first << "::" << testG.getPlayer(2).getPos().second << endl;
    cout << testG.getBoard().toString() << endl;
    testG.move(Side::South, testG.getPlayer(2));
    cout << testG.getBoard().toString() << endl;
    testG.getBoard().place(3,7,0);
    cout << testG.getBoard().toString() << endl;
    try{
        testG.move(Side::North, testG.getPlayer(4));
    } catch (std::exception const& e){
        cout << "ERROR: " << e.what() << endl;
    }
    cout << testG.getBoard().toString() << endl;

    /*-------------l'image seule est bougée. Les coordonée du player ne change pas réellement--------*/
    testG.move(Side::South, testG.getPlayer(2));
    cout << testG.getPlayer(2).getPos().first << "; " << testG.getPlayer(2).getPos().second << endl;
    testG.move(Side::East, testG.getPlayer(2));
    cout << testG.getPlayer(2).getPos().first << "; " << testG.getPlayer(2).getPos().second << endl;
    cout << testG.getBoard().toString() << endl;
    cout << toString(testG.getBoard().getside(0,0)) << endl;
    testG.getBoard().place(3,3,0);
    cout << testG.getBoard().toString() << endl;

    /*-----------------Mouvement vers l'objectif et test de victoire-------------------*/
    testG.move(Side::South, testG.getPlayer(2));
    testG.move(Side::South, testG.getPlayer(2));
    cout << testG.getBoard().toString() << endl;
    if(testG.victoryCond(testG.getPlayer(2))){
        testG.getPlayer(1).setWin();
        cout << testG.getPlayer(1).getName() << " a gagne..." << endl;
    } else {
        cout << "La partie continue..." << endl;
    }

    /*-----------------------Eval position posible et mouvement------------------------------*/
    set<Side> pp = testG.possiblePositions(testG.getPlayer(3));
    for (auto s: pp){
        cout << toString(s) << endl;
    }
    // for_each (pp.begin(), pp.end(), s);
        return 0;
}

