#include <iostream>
#include "Board.h"

using namespace std;

int main()
{
    Player j1("Alex", 1, 4, 9);

    cout << j1.getName() << ", numero: " << j1.getNum() << " a gagne? ";
    cout << boolalpha;
    cout << j1.hasWon() << endl;
    cout << noboolalpha;
    cout << "Nombre de mur restant: " << j1.getWallstock() << endl;

    return 0;
}

