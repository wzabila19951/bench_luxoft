#ifndef LIFECYCLE_H
#define LIFECYCLE_H

#include "gamestate.h"
#include "playerturn.h"
#include "aiturn.h"
#include "map.h"
#include "drawer.h"

class LifeCycle
{
public:
    LifeCycle();
    ~LifeCycle();
    void play();
    int countAI;
    int countPlayer;

private:
    void pause();

private:
    GameState* game_state;
    Drawer drawer;

};

#endif // LIFECYCLE_H
