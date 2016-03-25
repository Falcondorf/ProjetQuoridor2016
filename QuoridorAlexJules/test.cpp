#include <iostream>
#include <algorithm>
#include "QuoridorConsole.h"
#include "keyboard.hpp"
#include "Test.h"
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
void Test::TestPlaceBoard(){
    Board plate(5);
    cout << plate.toString() << endl;
    plate.place(1,1,1); // par surcharge on place un mur vertical
    plate.place(1,5,0);
    plate.place(0,0); //on place un pion
    cout << plate.toString() << endl;
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
    testG.move(Side::North);
    testG.getPlayer(2).setPos(2,4);
    cout << "\nPetit test marrant: le J2 délace son fantome via setPos() et evalPos regarde les"
            " direction possible en prenant en compte la case physique remplie par le pion lol" << endl;
    pp = testG.possiblePositions();
    cout << "Joueur " << testG.getCurrentPlayer() << " possibilites:\n" << endl;

    for (auto s: pp){
        cout <<  "*" << toString(s) << endl;
    }
    cout << testG.stringBoard() << endl;
}

void Test::TestIsOverWinGame(){
    Game testG3("Alex", "Jules", 5);
    while(!testG3.isOver()){
        testG3.move(Side::North);
        testG3.move(Side::South);
    }

     cout << "resultat attendu : Jules a gagne en SOUTH" << endl;
}

void Test::TestFindPathFig4(){
    Board plat(9);

    //Placement des murs selon la figure 4 de l'énoncé du projet
    plat.place(1,1,0);
    plat.place(1,11,1);
    plat.place(1,13,0);
    plat.place(1,15,1);

    plat.place(3,3,1);
    plat.place(3,7,0);
    plat.place(3,9,1);

    plat.place(5,3,0);
    plat.place(5,5,1);
    plat.place(5,13,1);
    plat.place(5,15,1);
    plat.place(5,11,0);

    plat.place(7,1,1);
    plat.place(7,5,0);
    plat.place(7,7,1);

    plat.place(9,15,1);
    plat.place(9,9,0);
    plat.place(9,11,1);
    plat.place(9,5,0);

    plat.place(11,1,1);
    plat.place(11,9,1);
    plat.place(11,11,0);

    plat.place(13,3,1);
    plat.place(13,5,0);
    plat.place(13,13,0);

    plat.place(15,5,1);
    plat.place(15,7,0);
    plat.place(15,11,1);

    /*
    plat.place(1,7,1);  Décommenter pour bloquer le way4
    plat.place(15,1,1);
    */
    cout << plat.toString() << endl;

    //Eval des chemins pour les 4 positionset leur objectif.
    bool way1 = plat.findPath(make_pair(4, 12), Side::North);
    bool way2 = plat.findPath(make_pair(6, 6), Side::South);
    bool way3 = plat.findPath(make_pair(8, 6), Side::East);
    bool way4 = plat.findPath(make_pair(10, 12), Side::West);
    if(way1 && way2 && way3 && way4){
        cout << "resultat obtenu  : Tout chemin ouvert" << endl;
    }   else {
        cout << "resulatat obtenu  : Au moins un des chemins est bloqué." << endl;
    }
    cout << "resultat attendu : Tout chemin ouvert" << endl;
}

void Test::TestBoardIsFree(){
    Board plat(5);

    cout << "Après création du plateau, toutes les positions doivent être libres: Nous testons 4 quatres aléatoire de deux cases"
            " pions et mur.\nresultat attendu : 1111" << endl;
    cout << "resultat obtenu  : " << noboolalpha << plat.isFree(0,0);
    cout << plat.isFree(3,7);
    cout << plat.isFree(4,8);
    cout << plat.isFree(7,2) << endl;

}

void Test::TestBoardIsFree2(){
    Board plat(7);

    plat.place(0,2);
    plat.place(3,5,0);

    cout << "resultat attendu : 010001" << endl;
    cout << "resultat obtenu  : " << plat.isFree(0,2) << plat.isFree(3,3) << plat.isFree(3,4) << plat.isFree(3,5) << plat.isFree(3,6) << plat.isFree(3,7) << endl;
}
void Test::TestBoardEmptyWallFail(){
     Board plate(5);
     cout << "resultat attendu : there is no wall here" << endl;
     cout << "resultat obtenu  : " ;
     try{
     plate.empty(1,1,0);
     }catch(QuoridorExceptions const& e){
         cout << e.what() << endl;
     }

}
void Test::TestBoardEmptyWall(){
    Board plate(5);
    plate.place(1,1,0);
    plate.empty(1,1,0);
    cout << "resultat attendu : true true true" << endl;
    cout <<"resultat obtenu  : "<<boolalpha<< plate.isFree(1,1) <<" "<<plate.isFree(1,0)<<" "<< plate.isFree(1,2) << endl ;

}

void Test::TestGetlen(){
    Board plateau(7);
    cout << "resultat attendu : 7" << endl;
    cout << "resultat obtenu  : " <<plateau.getLen() << endl;
}

void Test::TestSideToString(){
    Side cote;
    cote = Side::NorthWest;
    cout << "resultat attendu : NORTHWEST" << endl;
    cout << "resultat obtenu  : " <<toString(cote) << endl;

}
void Test::TestPlayerConstrFail(){
    try{
    Player joueur1("mark",1,3,7);
    }catch(QuoridorExceptions const& e){
        cout << "resultat attendu : Incorrect number of player" << endl;
        cout << "resultat obtenu  : " << e.what() << endl;
    }

}

void Test::TestPlayerConstrFail2(){
    try{
    Player joueur1("mark",12,4,7);
    }catch(QuoridorExceptions const& e){
        cout << "resultat attendu : Incorrect number for the player" << endl;
        cout << "resultat obtenu  : " << e.what() << endl;
    }
}
void Test::TestPlayerConstrOk(){
    Player joueur1("mark",2,4,7);
    cout << "resultat attendu : mark 2" << endl;
    cout << "resultat obtenu  : " << joueur1.getName() <<
            " " << joueur1.getNum() << endl;

}
void Test::TestPickWall(){
    Player j5("Ed", 3, 4, 5);
    cout << "resultat attendu : Nombre de mur restant: 3" << endl;
    cout << "resultat obtenu  : Nombre de mur restant: " << j5.getWallstock() << endl;
    j5.pickWall();
    cout << "resultat attendu : Nombre de mur restant: 2" << endl;
    cout << "resultat obtenu  : Nombre de mur restant: " << j5.getWallstock() << endl;

}
void Test::TestGetName(){
    Player joueur1("mark",2,4,7);
    cout << "resultat attendu : mark" << endl;
    cout << "resultat obtenu  : " << joueur1.getName() << endl;
}
void Test::TestGetNum(){
    Player joueur1("mark",2,4,7);
    cout << "resultat attendu : 2" << endl;
    cout << "resultat obtenu  : " << joueur1.getNum() << endl;
}
void Test::TestHasWonSetwin(){
    Player joueur1("mark",2,4,7);
    cout << "resultat attendu : false" << endl;
    cout << "resultat obtenu  : " << boolalpha<< joueur1.hasWon() << endl;
    joueur1.setWin();
    cout << "resultat obtenu  : " << boolalpha<< joueur1.hasWon() << endl;
    cout << "resultat attendu : true" << endl;
}

void Test::TestPlaceBoardFail(){
    Board plateau(5);
    plateau.place(1,1,1); // par surcharge on place un mur vertical
    try{
    plateau.place(1,1,0); //collision
    }catch(QuoridorExceptions const& e){
        cout << "resultat attendu : Collision of walls" << endl;
        cout << "resultat obtenu  : " << e.what() << endl;
    }
}
void Test::TestGameConstr(){
    Game jeu("Alex", "Jules", 9);
    cout << "resultat attendu : Jules" << endl;
    cout << "resultat obtenu  : " << jeu.getPlayer(2).getName() << endl;
}
void Test::TestGameConstrFail(){
    try{
     Game jeu("Alex", "Jules", 8);
    }catch(QuoridorExceptions const& e){
        cout << "resultat attendu : Incorrect input of size(Only 5 to 19 and not pair)" << endl;
        cout << "resultat obtenu  : " << e.what() << endl;
    }
}
void Test::TestGameNbPlayer(){

     Game jeu("Alex", "Jules","marc","elliot", 9);
        cout << "resultat attendu : 4" << endl;
        cout << "resultat obtenu  : " << jeu.getNbP() << endl;

}
void Test::TestGetCurrentPlayerAndName(){
    Game jeu("Alex", "Jules","marc","elliot", 9);
    cout << "resultat attendu : Alex"  << endl;
    cout << "resultat obtenu  : " << jeu.getPlayer(jeu.getCurrentPlayer()).getName() << endl;
    jeu.move(Side::North);
    cout << "resultat attendu : Jules"  << endl;
    cout << "resultat obtenu  : " << jeu.getPlayer(jeu.getCurrentPlayer()).getName() << endl;
}
void Test::TestGameMove(){
     Game jeu("Alex", "Jules","marc","elliot", 9);
     cout << "resultat attendu : A Jules de jouer"  << endl;
     cout << "resultat obtenu  : " ;
     jeu.move(Side::North);

}
void Test::TestVictoryCond(){
    Game jeu2("Alex", "Jules","marc","elliot", 9);
    cout << "resultat attendu : false"  << endl;
    cout << "resultat obtenu  : "<< boolalpha << jeu2.victoryCond(jeu2.getPlayer(3)) << endl;;
    jeu2.getPlayer(3).setPos(4,16);
    cout << "resultat attendu : true"  << endl;
    cout <<  "resultat obtenu  : " << boolalpha << jeu2.victoryCond(jeu2.getPlayer(3)) << noboolalpha <<endl;
}
void Test::TestPlayWall(){
    Game jeu("Alex","Jules",5);
    cout << "resultat attendu : 110"  <<endl;
    cout << "resultat obtenu  : " <<jeu.playWall(1,1,0);
    cout << jeu.playWall(1,5,0);
    cout << jeu.playWall(1,7,1) << endl;
}
void Test::FrameFailConstrP(){
    try{
        PlayerFrame frmp(7,80,9);
    }catch(QuoridorExceptions const& e){
        cout << "resultat attendu : incorrect position" << endl;
        cout << "resultat obtenu  : " << e.what() << endl;
    }
}

void Test::TestFramePPlace(){
    PlayerFrame frmP(1,1,5);
    cout << "Avant placement:\nresultat attendu : _" << endl;
    cout << "resultat obtenu  : " << frmP.toString() << endl;
    frmP.place();
    cout << "Après placement:\nresultat attendu : X" << endl;
    cout << "resultat obtenu  : " << frmP.toString() << endl;
}

void Test::TestFrameWPlace(){
    WallFrame frmW;
    cout << "Avant placement:\nresultat attendu : ( )" << endl;
    cout << "resultat obtenu  : (" << frmW.toString() << ")" <<endl;
    frmW.place();
    cout << "Après placement:\nresultat attendu : #" << endl;
    cout << "resultat obtenu  : " << frmW.toString() <<endl;
}
void Test::TestFrameWEmpty(){
    WallFrame frmW;
    frmW.place();
    cout << "Après placement:\nresultat attendu : #" << endl;
    cout << "resultat obtenu  : " << frmW.toString() <<endl;
    frmW.empty();
    cout << "Après placement:\nresultat attendu : ( )" << endl;
    cout << "resultat obtenu  : (" << frmW.toString() <<")" <<endl;

}


/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/



void  Test::runTest(){
/*-------------Tests sur joueurs----------------------------*/
    cout << "----------DEBUT DES TESTS------------------------" << endl;
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
    cout << "\nTest erreur construction de joueur" << endl;
    TestPlayerConstrFail();
    cout << "\nAutre test d'erreur à la construction de joueur" << endl;
    TestPlayerConstrFail2();
    cout << "\nTest de construction de joueur fonctionnel" << endl;
    TestPlayerConstrOk();
    cout << "\nTest d'enlèvement de mur du stock" << endl;
    TestPickWall();
    cout << "\nTest de récupération du nom d'un joueur" << endl;
    TestGetName();
    cout << "\nTest de récupération du numero d'un joueur" << endl;
    TestGetNum();
     cout << "\nTest de la victoire d'un joueur avant et apres la mise en victoire de ce joueur" << endl;
    TestHasWonSetwin();
/*-------------Tests sur cases-----------------------------*/

    cout << "\nTest création d'une case pion et récupération de son orientation sur les contours" << endl;
    TestFrameSide();
    cout << "\nTest création d'une case pion dans l'intérieur du plateau et récupération de son orientation" << endl;
    TestFrameSide2();
    cout << "\nTest d'erreur de construction de case joueur avec position incorrecte " << endl;
    FrameFailConstrP();
    cout << "\nTest initialisant une case avec un placement et retourant le string du contenu" << endl;
    TestFramePrintContent();
    cout << "\nAffichage avant/apres placement d'un joueur pour vérification" << endl;
    TestFramePPlace();
    cout << "\nAffichage avant/apres placement d'un mur pour vérification " << endl;
    TestFrameWPlace();
    cout << "\nAffichage avant/apres suppression d'un mur pour vérification" << endl;
    TestFrameWEmpty();
/*-------------Tests dur Plateau---------------------------*/

    cout << "\nTest Création d'un plateau OK" << endl;
    TestBoardCreateOK();
    cout << "\nTest Création d'un plateau KO" << endl;
    TestBoardCreateKO();
    cout << "\nTests de position libres" << endl;
    TestBoardIsFree();
    cout << "\nTest de position après placement de pion et mur" << endl;
    TestBoardIsFree2();
    cout << "\nTest affichant un board vierge et ensuite le réaffiche avec des murs et un pion " << endl;
    cout << "place un pion en (0, 0); un mur en (1, 5) horizontale et un autre en (1, 1) vertical " << endl;
    TestPlaceBoard();
    cout << "\nTest d'erreur après placement dans un plateau" << endl;
    TestPlaceBoardFail();
    cout << "\nTest de vidage de case mur" << endl;
    TestBoardEmptyWall();
    cout << "\nTest avec erreur de vidage mur" << endl;
    TestBoardEmptyWallFail();
    cout << "\nTest de récupération de la taille du plateau" << endl;
    TestGetlen();

/*--------------Test findPath sur Spirale-------------------*/

    cout << "\nTest sur la recherche de chemin dans une spirale avec chemin disponible" << endl;
    TestFindPath();
    cout << "\nTest sur la recherche de chemin dans une spirale avec résultat bloquant" << endl;
    TestFindPathBlocked();
    cout << "\nTest recherche chemin ouvert selon la figure 4 de l'énoncé du projet" << endl;
    TestFindPathFig4();

/*--------------Test l'évaluation des positions possibles---*/

    cout << "\nTest évaluant les positions possibles" << endl;
    TestEvalPosition();
    cout << "\nTest affichant le joueur gagnant quand il atteint son objectif de victoire" << endl;
    TestIsOverWinGame();
/*--------------Test sur la classe d'énumération Side-------*/

    cout << "\nTest d'affichage de chaîne sur un side avec toString()" << endl;
    TestSideToString();
/*--------------Test sur game--------------------------------------*/
    cout << "\nTest de création d'un jeu sans probleme avec affichage du nom pour vérifier" << endl;
    TestGameConstr();
    cout << "\nTest de création d'un jeu avec une dimension erronée" << endl;
    TestGameConstrFail();
    cout << "\nTest donnant le nombre de joueur d'un jeu créé avec 4 joueurs" << endl;
    TestGameNbPlayer();
    cout << "\nTest donnant le joueur courant d'un jeu pour vérifier qu'il change de joueur apres le move en donnant le nom" << endl;
    TestGetCurrentPlayerAndName();
    cout << "\nTest vérifiant que le move lance bien le joueur suivant" << endl;
    TestGameMove();
    cout << "\nTest vérifiant que la condition de victoire est mise à vrai si un joueur est sur sa destination de victoire " << endl;
    TestVictoryCond();
    cout << "\nTest vérifiant que les murs sont placés sauf si il bloque completement un joueur" << endl;
    TestPlayWall();

}

