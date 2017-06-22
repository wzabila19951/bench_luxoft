#ifndef AITURN_H
#define AITURN_H

#include "gamestate.h"
#include "ai.h"

class AITurn : public GameState
{
public:
    virtual ~AITurn() {}
    char getId() const override;
    void Next(GameState* out_state) override;
    Cordinate MakeTurn() override;
};

#endif // AITURN_H
