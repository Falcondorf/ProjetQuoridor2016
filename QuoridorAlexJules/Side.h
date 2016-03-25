/*!
 * \file Side.h
 * \brief l'ensemble des points cardinaux.
 */

#ifndef SIDE
#define SIDE
#include <string>
/*!
 * \brief Enumération des points cardinaux que peuvent posseder les cases
 *
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
 * \brief Méthode d'affichage d'un point cardinal donné
 * \param s le point cardinal donné
 * \return la représentation en chaîne de caractère du point cardinal
 */
std::string toString(Side s);
#endif // SIDE

