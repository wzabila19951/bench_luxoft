#include "ship.h"

Ship::Ship(const std::vector<Cordinate*> &cells) : shipCells(cells)
{

}

bool Ship::CheckHit(const Cordinate &cell) const
{
    for(Cordinate* ship_cell : shipCells){
        if(*ship_cell == cell){
            return true;
        }
    }
    return false;
}
