#ifndef SIDE
#define SIDE
#include <string>

enum class Side{
    North,
    NorthWest,
    NorthEast,
    South,
    SouthWest,
    SouthEast,
    West,
    East,
    Blank

};

std::string toString(Side s);
#endif // SIDE

