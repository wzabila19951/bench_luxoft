#ifndef SHIP_H
#define SHIP_H

#include <vector>

#include "cordinate.h"

class Ship
{
public:
    enum class ShipType {
      Sloop = 0,
        Corvete,
        Frigate,
        Linkor
    };

    Ship(const std::vector<Cordinate*>& cells);
    virtual void DeactivateCellsAround() = 0;
    virtual bool CheckHit(const Cordinate& cell) = 0;
protected:
    std::vector<Cordinate*> shipCells;
};

#endif // SHIP_H
