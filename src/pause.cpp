#include "pause.h"
#include "playerturn.h"

Pause::Pause(const Drawer& in_drawer) : drawer(in_drawer)
{

}

void Pause::MakeTurn()
{
    drawer.ClearView();
    drawer.DrowStatistic();

    /*
    read press of whitespace
    */

}

void Pause::Next(GameState* out_state)
{
    delete out_state;
    out_state = new PlayerTurn();
}
