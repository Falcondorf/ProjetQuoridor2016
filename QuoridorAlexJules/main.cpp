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


    PlayerFrame frm(1, 1, 9);
    cout << frm.toString() << " + Side: "/*<< frm.getSide() */<< endl;
    return 0;
}

