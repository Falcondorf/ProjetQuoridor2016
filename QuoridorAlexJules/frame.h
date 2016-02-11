#ifndef FRAME
#define FRAME
#include "Side.h"
#include "Player.h"

class Frame{
protected:
    Frame()=default;

};

class PlayerFrame : public Frame{
private:
    bool hasPiece_;
    Side side_;
    Player player_;

public:
    PlayerFrame(unsigned row, unsigned column);
};


class WallFrame : public Frame{
private:
    bool isWalled_;

public:
    WallFrame();
};

WallFrame::WallFrame() : Frame()
{
}

#endif // FRAME

