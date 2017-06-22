#include "aiturn.h"
#include "playerturn.h"

char AITurn::getId() const
{
    return 'c';
}

void AITurn::Next(GameState* out_state)
{
    out_state = 0;
    delete out_state;
    out_state = new PlayerTurn();
}

Cordinate AITurn::MakeTurn()
{
    AI aiCordinate;
    return aiCordinate.GetShotPoint();
}
