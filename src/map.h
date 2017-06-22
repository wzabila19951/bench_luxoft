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
    friend class Drawer;
    Map(const bool _mapSwitch);
    ~Map();
    bool isCellActive(const Cordinate& cordinate) const ;
    void DeactivatedCell(const Cordinate& cordinate, const Cordinate::State new_state);
    bool TakeShot(const Cordinate &cordinate) const;
    std::vector<Cordinate> cells;
protected:
   const bool mapSwitch;
private: 
   std::vector<Ship*> ships;
   void AddShip(Ship::ShipType ship_type);

   Cordinate *getCell(const char horizontal, const int vertical);

   std::vector<std::pair<char, int>> lincore_coords = {{'G',1}, {'H', 1}, {'I', 1}, {'J', 1}};
   std::vector<std::pair<char, int>> frigate_coords = {{'D',3}, {'E', 3}, {'F', 3}, {'J', 3}, {'J', 4}, {'J', 5}};
   std::vector<std::pair<char, int>> corvete_coords = {{'A',1}, {'B', 1}, {'B', 5}, {'C', 5}, {'G', 6}, {'H', 6}};
   std::vector<std::pair<char, int>> sloop_coords = {{'D',1}, {'D', 7}, {'B', 9}, {'G', 9}};
};

#endif // MAP_H
