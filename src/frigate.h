#ifndef FRIGATE_H
#define FRIGATE_H

#include "ship.h"

class Frigate : public Ship
{
public:
    Frigate(const std::vector<Cordinate&>& cells);
    bool CheckHit(const Cordinate& cell) override;
    void DeactivateCellsAround();
};

#endif // FRIGATE_H
