#include "aiturn.h"
#include "playerturn.h"

char AITurn::getId() const
{
    return 'c';
}

void AITurn::Next(GameState* out_state)
{
    delete out_state;
    out_state = new PlayerTurn();
}

Cordinate AITurn::MakeTurn()
{
    AI aiCordinate;
    return aiCordinate.GetShotPoint();
}
