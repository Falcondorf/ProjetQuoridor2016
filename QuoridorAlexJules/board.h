#ifndef BOARD
#define BOARD
#include "Frame.h"
#include <vector>


/*!
 * \brief The Board class la classe chargée des opération sur le plateau
 */
class Board{

private:
    /*!
     * \brief len_ la longueur du coté plateau
     */
    unsigned len_;
    /*!
     * \brief plateau_ le plateau de jeu corridor
     */
    std::vector< std::vector<Frame *> > plateau_;
    /*!
     * \brief tourner
     * \param cpt
     * \param dir
     * \param gauche
     */
    void tourner (int *cpt, Side *dir, bool gauche);
    void displace(Side dir, std::pair<unsigned, unsigned> *pos);
    bool verifWall(unsigned row, unsigned column, Side dir);
    bool verifLeftArm(unsigned row, unsigned column, Side dir);
    bool reachEnd(Side currFrame, Side obj);
public:
    Board(unsigned len);
    inline unsigned getLen();
    Side getside(unsigned row, unsigned column);
    bool isFree(unsigned row, unsigned column);
    void place(unsigned row, unsigned column, bool vertical);
    void place(unsigned row, unsigned column);
    void empty(unsigned row, unsigned column);
    void empty(unsigned row, unsigned column, bool vertical);
    bool findPath( std::pair<unsigned, unsigned> pos, Side obj);
    std::string toString();
};


 unsigned Board::getLen(){
    return len_;
}

#endif // BOARD

