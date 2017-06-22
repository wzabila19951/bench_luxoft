#include <iostream>

#include "playerturn.h"
#include "aiturn.h"
#include "ai.h"
#include <unistd.h>


Cordinate PlayerTurn::MakeTurn()
{
   Cordinate cordinate(false);
   std::cout << "Please enter cordinate [A-J] [1-10] : ";
   scanf("%c %d", &cordinate.horizontal, &cordinate.vertical);
   return cordinate;
}

void PlayerTurn::Next(GameState* out_state)
{
    delete out_state;
    out_state = new AITurn();
}

char PlayerTurn::getId() const
{
    return 'p';
}
