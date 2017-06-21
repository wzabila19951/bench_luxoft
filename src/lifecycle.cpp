#include "lifecycle.h"

#include <iostream>
#include "pause.h"

LifeCycle::LifeCycle()
{
    game_state = new PlayerTurn();

}

LifeCycle::~LifeCycle()
{
}




void LifeCycle::play()
{
    Map mapAI;
    Map mapPlayer;
    Cordinate pause_coordiante;
    pause_coordiante.horizontal = 'p';
    pause_coordiante.vertical = '0';

    do{
        drawer.ClearView();
        drawer.DrowMap(mapAI);
        drawer.DrowMap(mapPlayer);
        const Cordinate entered_cordinate = game_state->MakeTurn();
        if (entered_cordinate == pause_coordiante) {
            pause();
            game_state->MakeTurn();
            game_state->Next(game_state);
            continue;
        }

        Map curr_map = (game_state->name == 'p') ? mapAI : mapPlayer;

        bool is_hited = false;
        if(curr_map.isCellActive(entered_cordinate)){
            is_hited= curr_map.TakeShot(entered_cordinate);
            const Cordinate::State new_state =
                    (is_hited)
                    ? Cordinate::State::Hited
                    : Cordinate::State::Shooted;
            curr_map.DeactivatedCell(entered_cordinate, new_state);
        }
        if (!is_hited) {
            game_state->Next(game_state);
        }

        /**
          add exit function (while all ships alive)
          *//
    }while(true);
}

void LifeCycle::pause()
{
    delete game_state;
    game_state = new Pause(drawer);
}
