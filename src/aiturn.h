#ifndef AITURN_H
#define AITURN_H

#include "gamestate.h"
#include "ai.h"

class AITurn : public GameState
{
public:
    AITurn();
    char name = 'c';
    void Next(GameState* out_state);
    Cordinate MakeTurn();
};

#endif // AITURN_H
