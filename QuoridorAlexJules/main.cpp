#include <iostream>
#include "Board.h"
#include "Frame.h"

using namespace std;

int main()
{

    Player j1("Alex", 1, 4, 9);

    cout << j1.getName() << ", numero: " << j1.getNum() << " a gagne? ";
    cout << boolalpha;
    cout << j1.hasWon() << endl;
    cout << noboolalpha;
    cout << "Nombre de mur restant: " << j1.getWallstock() << endl;
    j1.pickWall();
    cout << "Nombre de mur restant: " << j1.getWallstock() << endl;
    for (int i=1; i<=4; i++){
        j1.pickWall();
    }
    cout << "Nombre de mur restant: " << j1.getWallstock() << endl;
    try{
      j1.pickWall();
      cout << "Nombre de mur restant: " << j1.getWallstock() << endl;
    }catch(std::exception const& e){
        cerr << "ERROR: "<< e.what() << endl;
    }


    PlayerFrame frm(0, 0, 9);
    cout << frm.toString() << " + Side: "<< toString(frm.getSide()) << endl;

    Frame * frm2;
    frm2 = &frm;
    cout << frm2->toString() << endl;
   // Side * direction = new Side();
    try{
        Board platErr(6);
    }catch (std::exception const& e){
        cerr << "ERROR: " << e.what() << endl;
    }
    Board plat(7);
    cout << plat.toString() << endl;
    plat.place(1,1,0); // par surcharge on place un mur horizontal
    plat.place(2,2);//on place un mur car on indique avec le 3eme param la direction
    cout << plat.toString() << endl;
    return 0;
}

