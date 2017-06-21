#ifndef PLAYERTURN_H
#define PLAYERTURN_H

#include "gamestate.h"
#include "cordinate.h"


class PlayerTurn : public GameState
{
public:
    char name = 'p';
    PlayerTurn();
    Cordinate MakeTurn() override;
    void Next(GameState* out_state) override;
};

#endif // PLAYERTURN_H
