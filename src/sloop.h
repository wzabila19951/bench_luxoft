#ifndef SLOOP_H
#define SLOOP_H

#include "ship.h"

class Sloop: public Ship
{
public:
    Sloop(const std::vector<Cordinate*> &cells);
    bool CheckHit(const Cordinate& cell) override;
    void DeactivateCellsAround();
};

#endif // SLOOP_H
