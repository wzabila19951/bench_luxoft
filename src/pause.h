#ifndef PAUSE_H
#define PAUSE_H

#include "gamestate.h"
#include "drawer.h"


class Pause : public GameState
{
public:
    Pause(const Drawer& in_drawer);
    void MakeTurn() override;
    void Next(GameState* out_state) override;

private:
    const Drawer& drawer;
};

#endif // PAUSE_H
