#ifndef PLAYERTURN_H
#define PLAYERTURN_H

#include "gamestate.h"
#include "cordinate.h"


class PlayerTurn : public GameState
{
public:
    virtual ~PlayerTurn(){}
    Cordinate MakeTurn() override;
    void Next(GameState* out_state) override;
    char getId() const override;
private:
    char id;
};

#endif // PLAYERTURN_H
