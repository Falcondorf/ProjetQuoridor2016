#include <iostream>
#include <algorithm>
#include "QuoridorConsole.h"
#include "keyboard.hpp"
#include "test.h"
#include "QuoridorExceptions.h"

using namespace std;

void Test::TestPlayerCase1(){
    cout << "Creation simple d'un joueur partie à quatre joueurs" << endl;
    cout << "resultat attendu : Alex 3 EAST 3 " << endl;
    Player j1("Alex", 3, 4, 5);
    cout << "resultat obtenu  : " << j1.getName() << " " << j1.getNum() << " " << toString(j1.getObjective())  << " " << j1.getWallstock() << endl;
}
void Test::TestPlayerCase2(){
    cout << "Creation simple d'un joueur partie à deux joueurs dans un plateau 9x9" << endl;
    cout << "resultat attendu : Jules 2 SOUTH 10 " << endl;
    Player j2("Jules", 2, 2, 9);
    cout << "resultat obtenu  : " << j2.getName() << " " << j2.getNum() << " " << toString(j2.getObjective())  << " " << j2.getWallstock() << endl;
}
void Test::TestPlayerCase3(){
    cout << "resultat attendu : ERROR: Incorrect number of player" << endl;
    try{
        Player j3("Error", 2, 3, 9);
        cerr << "invisible" << endl;
    }catch(QuoridorExceptions const& e){
        cout << "resultat obtenu  : ERROR: "<< e.what() << endl;
    }
}
void Test::TestPlayerWallStock(){
     Player j5("Ed", 3, 4, 5);
     cout << "resultat attendu : Nombre de mur restant: 3" << endl;
    cout << "resultat obtenu  : Nombre de mur restant: " << j5.getWallstock() << endl;
    j5.pickWall();
     cout << "resultat attendu : Nombre de mur restant: 2" << endl;
    cout << "resultat obtenu  : Nombre de mur restant: " << j5.getWallstock() << endl;
    for (int i=1; i<=2; i++){
        j5.pickWall();
    }
    cout << "resultat attendu : Nombre de mur restant: 0" << endl;
    cout << "resultat obtenu  : Nombre de mur restant: " << j5.getWallstock() << endl;
    try{
      cout << "resultat attendu : No more walls" << endl;
      j5.pickWall();
      cerr << "ERROR :ligne inaccessible" << endl;
    }catch(QuoridorExceptions const& e){
        cout << "resultat obtenu  : " << e.what() << endl;
    }
}
void Test::TestPlayerPosition(){
    Player j6("Gary", 4, 4, 5);
    cout << "resultat attendu : 4, 8" << endl;
    cout << "resultat obtenu  : " << j6.getPos().first << ", " << j6.getPos().second << endl;

}

void Test::TestCaseSide(){
    PlayerFrame frm(0, 0, 9);
    cout << "resultat attendu : NORTHWEST" << endl;
    cout << "resultat obtenu  : "<< toString(frm.getSide()) << endl;
}
void Test::TestCaseSide2(){
    PlayerFrame frm2(6, 6, 9);
    cout << "resultat attendu : BLANK" << endl;
    cout << "resultat obtenu  : "<< toString(frm2.getSide()) << endl;
}

void  Test::runTest(){
/*-------------Tests sur joueurs-------------------------*/

    TestPlayerCase1();
    TestPlayerCase2();
    TestPlayerCase3();
    TestPlayerWallStock();
    TestPlayerPosition();
/*-------------Tests sur cases--------------------------*/
    TestCaseSide();
    TestCaseSide2();




#if 0

    /*--------------Tests sur plateau----------------------------*/
    try{
        Board platErr(6);
    }catch (std::exception const& e){
        cerr << "ERROR: " << e.what() << endl;
    }
    Board plate(9);
    cout << plate.toString() << endl;
    plate.place(1,11,1); // par surcharge on place un mur vertical
    plate.place(1,9,0);
    plate.place(0,0); //on place un pion
    cout << plate.toString() << endl;

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
    testG.move(Side::West, testG.getPlayer(2));
    testG.move(Side::West, testG.getPlayer(1));
    cout << testG.getBoard().toString() << endl;
    if(testG.victoryCond(testG.getPlayer(2))){
        testG.getPlayer(1).setWin();
        cout << testG.getPlayer(1).getName() << " est gagnant..." << endl;
    } else {
        cout << "La partie continue..." << endl;
    }

    /*-----------------------Eval position posible et mouvement------------------------------*/
    cout << testG.getNbP() << endl;
    for (unsigned i=1; i<=testG.getNbP(); i++){
        set<Side> pp = testG.possiblePositions(testG.getPlayer(i));
        cout << "J" << i << "possibilite:\n" << endl;
        for (auto s: pp){
            cout <<  "*" <<toString(s) << endl;
        }
    }
    /*-----------------------Test findPath enfermé------------------------------*/

  /*  try{
    testG.playWall(3,1,0);
    }catch(std::exception const& e){
        cerr << "ERROR: " << e.what() << endl;
        exit(1);
    }
    /*
    //testG.playWall(3,5,0);
    //testG.playWall(3,9,0);
   //bool hey =testG.findPath(make_pair(0,4),Side::South);
   // cout << hey<< endl;
    cout << plate.toString() << endl;
    /*---------------------Test findPath dans spirale------------------------------*/

    Game testG2("alex","ed",9);
    cout << testG2.getBoard().toString() << endl;
    try{
    testG2.playWall(1,1,1);
    testG2.playWall(5,1,1);
    testG2.playWall(9,1,1);
    testG2.playWall(13,1,1);
    testG2.playWall(15,3,0);
    testG2.playWall(15,7,0);
    testG2.playWall(15,11,0);
    testG2.playWall(13,13,1);
    testG2.playWall(9,13,1);
    testG2.playWall(5,13,1);
    testG2.playWall(3,11,0);
    testG2.playWall(3,7,0);
    testG2.playWall(5,5,1);
    testG2.playWall(9,5,1);
    testG2.playWall(11,7,0);
    testG2.playWall(9,9,1);
    testG2.playWall(3,15,0); // joueur blocké
    }catch(std::exception const& e){
        cerr << "ERROR: " << e.what() << endl;
    }

    cout << testG2.getBoard().toString() << endl;
    //cout << plat.findPath(make_pair(8,8), Side::West) <<endl;
#endif
}
