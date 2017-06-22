#ifndef PAUSE_H
#define PAUSE_H

#include "gamestate.h"
#include "drawer.h"


class Pause : public GameState
{
public:
    Pause(const Drawer& in_drawer);
    virtual ~Pause();
    Cordinate MakeTurn() override;
    char getId() const;
    void Next(GameState* out_state) override;
    char a;
private:
    const Drawer& drawer;
};

#endif // PAUSE_H
