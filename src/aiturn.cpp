#include "aiturn.h"
#include "playerturn.h"

AITurn::AITurn()
{

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
