#include "lifecycle.h"

#include <iostream>
#include "pause.h"

LifeCycle::LifeCycle()
{
    game_state = new PlayerTurn();

}

LifeCycle::~LifeCycle()
{
    delete game_state;
    game_state = nullptr;
}




void LifeCycle::play()
{
    Map mapAI(true);
    Map mapPlayer(false);
    const char id = 'p';
    Cordinate pause_coordiante(false);
    pause_coordiante.horizontal = 'P';
    pause_coordiante.vertical = 0;

    do{
        drawer.ClearView();
        drawer.DrawText("Player map");
        drawer.DrawMap(mapPlayer);
        drawer.DrawText("AI map");
        drawer.DrawMap(mapAI);
        Cordinate entered_cordinate = game_state->MakeTurn();
        if (entered_cordinate == pause_coordiante) {
            pause();
            game_state->MakeTurn();
            game_state->Next(game_state);
            continue;
        }


        Map& curr_map = (game_state->getId() == id) ? mapAI : mapPlayer;

        bool is_hited = false;
        if(curr_map.isCellActive(entered_cordinate)){
            is_hited= curr_map.TakeShot(entered_cordinate);
            const Cordinate::State new_state =
                    (is_hited)
                    ? Cordinate::State::Hited
                    : Cordinate::State::Shooted;
            curr_map.DeactivatedCell(entered_cordinate, new_state);
            if (!is_hited) {
                game_state->Next(game_state);
            }
        }

        /*
          add exit function (while all ships alive)
          */
    }while(true);
}

void LifeCycle::pause()
{
    delete game_state;
    game_state = new Pause(drawer);
}
