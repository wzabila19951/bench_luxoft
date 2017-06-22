#ifndef GAMESTATE_H
#define GAMESTATE_H

#include  "cordinate.h"

class GameState
{
public:
    virtual ~GameState() {}
    virtual Cordinate MakeTurn() = 0;
    virtual void Next(GameState* out_state) = 0;
    virtual char getId() const = 0;
};

#endif // GAMESTATE_H
