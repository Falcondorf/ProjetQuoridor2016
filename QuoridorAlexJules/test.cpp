#include <iostream>
#include <algorithm>
#include "QuoridorConsole.h"
#include "keyboard.hpp"
#include "test.h"
#include "QuoridorExceptions.h"

using namespace std;

void Test::TestPlayerCase1(){
    cout << "resultat attendu : Alex 3 EAST 3 " << endl;
    Player j1("Alex", 3, 4, 5);
    cout << "resultat obtenu  : " << j1.getName() << " " << j1.getNum() << " " << toString(j1.getObjective())  << " " << j1.getWallstock() << endl;
}
void Test::TestPlayerCase2(){
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

void Test::TestFrameSide(){
    Frame * frmP;
    PlayerFrame frm(0, 0, 9);
    frmP = &frm;

    cout << "resultat attendu : NORTHWEST" << endl;
    cout << "resultat obtenu  : "<< toString(frmP->getSide()) << endl;
}
void Test::TestFrameSide2(){
    Frame * frmP2;
    PlayerFrame frm2(6, 6, 9);
    frmP2 = &frm2;
    cout << "resultat attendu : BLANK" << endl;
    cout << "resultat obtenu  : "<< toString(frmP2->getSide()) << endl;
}

void Test::TestFramePrintContent(){
    Frame * frmP3;
    WallFrame frm3;
    frmP3 = &frm3;
    frmP3->place();
    cout << "resultat attendu : #" << endl;
    cout << "resultat obtenu  : " << frmP3->toString() << endl;
}

void Test::TestBoardCreateOK(){
    Board plat (7);
    cout << "resultat attendu : 7" << endl;
    cout << "resultat obtenu  : " << plat.getLen() << endl;
}

void Test::TestBoardCreateKO(){
    cout << "resultat attendu : Incorrect input of size(Only 5 to 19 and not pair)" << endl;
    try{
        Board platErr(6);
        cerr << "invisible" << endl;
    }catch (std::exception const& e){
        cout << "resultat obtenu  : " << e.what() << endl;
    }
}

void Test::TestFindPath(){
    Board plat(9);
    plat.place(1,1,1);
    plat.place(5,1,1);
    plat.place(9,1,1);
    plat.place(13,1,1);
    plat.place(15,3,0);
    plat.place(15,7,0);
    plat.place(15,11,0);
    plat.place(13,13,1);
    plat.place(9,13,1);
    plat.place(5,13,1);
    plat.place(3,11,0);
    plat.place(3,7,0);
    plat.place(5,5,1);
    plat.place(9,5,1);
    plat.place(11,7,0);
    plat.place(9,9,1);

    cout << "resultat attendu  :  true" << endl;
    cout << "resultat obtenu   :  "<< boolalpha << plat.findPath(make_pair(8,8), Side::West) <<endl;
}
void Test::TestFindPathBlocked(){
    Board plat2(9);
        plat2.place(1,1,1);
        plat2.place(5,1,1);
        plat2.place(9,1,1);
        plat2.place(13,1,1);
        plat2.place(15,3,0);
        plat2.place(15,7,0);
        plat2.place(15,11,0);
        plat2.place(13,13,1);
        plat2.place(9,13,1);
        plat2.place(5,13,1);
        plat2.place(3,11,0);
        plat2.place(3,7,0);
        plat2.place(5,5,1);
        plat2.place(9,5,1);
        plat2.place(11,7,0);
        plat2.place(9,9,1);
        plat2.place(3,15,0); // joueur blocké

        cout << "resultat attendu  :  false" << endl;
        cout << "resultat obtenu   :  "<< boolalpha << plat2.findPath(make_pair(8,8), Side::West) <<endl;
}

void Test::TestEvalPosition(){
    Game testG("Alex", "Jules","Marty", "Vanessa", 5);

    set<Side> pp = testG.possiblePositions();
    cout << "Joueur " << testG.getCurrentPlayer() << " possibilites:\n" << endl;
    for (auto s: pp){
        cout <<  "*" << toString(s) << endl;
    }
}

void  Test::runTest(){
/*-------------Tests sur joueurs----------------------------*/


    cout << "Creation simple d'un joueur partie à quatre joueurs" << endl;
    TestPlayerCase1();
    cout << "\nCreation simple d'un joueur partie à deux joueurs dans un plateau 9x9" << endl;
    TestPlayerCase2();
    cout << "\nCréation d'un joueur qui envoie une erreur" << endl;
    TestPlayerCase3();
    cout << "\nMultiple tests sur le stock de murs: enlever 1 puis tous les murs et envoie d'erreur quand stock vide" << endl;
    TestPlayerWallStock();
    cout << "\nTest sur l'attribution d'un position de départ" << endl;
    TestPlayerPosition();
/*-------------Tests sur cases-----------------------------*/

    cout << "\nTest création d'une case pion et récupération de son orientation sur les contours" << endl;
    TestFrameSide();
    cout << "\nTest création d'une case pion dans l'intérieur du plateau et récupération de son orientation" << endl;
    TestFrameSide2();
    cout << "\nTest initialisant une case avec un placement et retourant le string du contenu" << endl;
    TestFramePrintContent();
/*-------------Tests dur Plateau---------------------------*/

    cout << "\nTest Création d'un plateau OK" << endl;
    TestBoardCreateOK();
    cout << "\nTest Création d'un plateau KO" << endl;
    TestBoardCreateKO();

/*--------------Test findPath sur Spirale-------------------*/

    cout << "\nTest sur la recherche de chemin dans une spirale avec chemin disponible" << endl;
    TestFindPath();
    cout << "\nTest sur la recherche de chemin dans une spirale avec résultat bloquant" << endl;
    TestFindPathBlocked();

/*--------------Test l'évaluation des positions possibles---*/

    cout << "\nTest évaluant les positions possibles" << endl;
    TestEvalPosition();
#if 0

    /*--------------Tests sur plateau----------------------------*/

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
