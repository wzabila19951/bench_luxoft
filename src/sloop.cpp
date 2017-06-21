#include "sloop.h"

Sloop::Sloop(const std::vector<Cordinate*>& cells) : Ship(cells)
{

}

bool Sloop::CheckHit(const Cordinate& cell)
{
    return true;
}

void Sloop::DeactivateCellsAround()
{

}
