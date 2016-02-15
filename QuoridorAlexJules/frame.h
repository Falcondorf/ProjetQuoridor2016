#ifndef FRAME
#define FRAME
#include "Side.h"
#include "Player.h"

class Frame{
protected:
    Frame()=default;
public:
    virtual std::string toString()=0;

};

class PlayerFrame : public Frame{
private:
    bool hasPiece_;
    Side side_;

public:
    PlayerFrame(unsigned row, unsigned column, unsigned size);
    inline Side getSide();
    std::string toString();

};

Side PlayerFrame::getSide(){
    return side_;
}

class WallFrame : public Frame{
private:
    bool isWalled_;

public:
    inline WallFrame();
    inline bool isWalled();
    std::string toString();
};

WallFrame::WallFrame() : Frame(){}
bool WallFrame::isWalled(){
    return isWalled_;
}

#endif // FRAME

