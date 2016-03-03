#ifndef FRAME
#define FRAME
#include "Side.h"
#include "Player.h"

class Frame{
protected:
    Frame()=default;
public:
    virtual std::string toString()=0;
    virtual Side getSide()=0;
    virtual void place()=0;
    virtual bool isFree()=0;
    virtual void empty()=0;
};

class PlayerFrame : public Frame{
private:
    bool hasPiece_;
    Side side_;

public:
    PlayerFrame(unsigned row, unsigned column, unsigned size);
    inline Side getSide();
    inline void place();
    inline void empty();
    bool isFree();
    std::string toString();

};

void PlayerFrame::place(){
    hasPiece_=true;
}

Side PlayerFrame::getSide(){
    return side_;
}

void PlayerFrame::empty(){
    hasPiece_=false;
}

class WallFrame : public Frame{
private:
    bool isWalled_;

public:
    inline WallFrame();
    inline Side getSide();
    inline void place();
    inline void empty();
    bool isFree();
    std::string toString();
};

WallFrame::WallFrame() : Frame(){
    isWalled_=false;
}

void WallFrame::place(){
    isWalled_=true;
}
void WallFrame::empty(){
    isWalled_=false;
}
Side WallFrame::getSide(){return Side::Blank;}
#endif // FRAME

