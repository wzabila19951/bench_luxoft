#include <iostream>

#include "playerturn.h"
#include "aiturn.h"

PlayerTurn::PlayerTurn()
{

}

Cordinate PlayerTurn::MakeTurn()
{
   Cordinate cordinate(false);
   std::cin >> cordinate.vertical >> cordinate.horizontal;
   return cordinate;
}

void PlayerTurn::Next(GameState* out_state)
{
    delete out_state;
    out_state = new AITurn();
}
