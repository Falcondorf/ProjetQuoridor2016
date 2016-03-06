#ifndef SIDE
#define SIDE
#include <string>
/*!
 * \brief The Side enum l'énumération des points cardinaux que peuvent posseder les cases
 */
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
/*!
 * \brief toString l'affichage du point cardinaux donné
 * \param s le point cardinal donné
 * \return la représentation en chaîne de caractère du point cardinal
 */
std::string toString(Side s);
#endif // SIDE

