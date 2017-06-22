#ifndef SLOOP_H
#define SLOOP_H

#include "ship.h"

class Sloop: public Ship
{
public:
    Sloop(const std::vector<Cordinate*>& cells);
    void DeactivateCellsAround() override;
protected:
    std::vector<Cordinate*> shipCells;
};

#endif // SLOOP_H
