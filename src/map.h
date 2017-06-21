#ifndef MAP_H
#define MAP_H

#include <vector>

#include "ship.h"
#include "cordinate.h"
#include "sloop.h"
#include "corvete.h"
#include "frigate.h"
#include "linkor.h"

class Map
{
public:
    Map();
    bool isCellActive(const Cordinate& cordinate) const;
    void DeactivatedCell(const Cordinate& cordinate, const Cordinate::State new_state);
    bool TakeShot(const Cordinate &cordinate);
private:
   std::vector<Cordinate> cells;
   std::vector<Ship*> ships;
   Ship* _ship;
   void AddShip(Ship::ShipType ship_type);

};

#endif // MAP_H
