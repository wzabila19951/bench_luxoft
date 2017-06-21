#ifndef GAMESTATE_H
#define GAMESTATE_H

#include  "cordinate.h"

class GameState
{
public:
    GameState();
    char name;
    virtual void Next(GameState* out_state) = 0;
    virtual Cordinate MakeTurn() = 0;
};

#endif // GAMESTATE_H
