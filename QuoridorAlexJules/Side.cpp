#include "Side.h"
#include "QuoridorExceptions.h"

std::string toString(Side s){
    switch(s){
    case Side::Blank: return "BLANK";break;
    case Side::East: return "EAST";break;
    case Side::North: return "NORTH";break;
    case Side::NorthEast: return "NORTHEAST";break;
    case Side::NorthWest: return "NORTHWEST";break;
    case Side::South: return "SOUTH";break;
    case Side::SouthEast: return "SOUTHEAST";break;
    case Side::SouthWest: return "SOUTHWEST";break;
    case Side::West: return "WEST";
    default: throw QuoridorExceptions(1, "Incorret Side of enum Side", 1);
    }
}
