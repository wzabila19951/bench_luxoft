#ifndef FRIGATE_H
#define FRIGATE_H

#include "ship.h"

class Frigate : public Ship
{
public:
    Frigate(const std::vector<Cordinate *> &cells);
    virtual ~Frigate();
    void DeactivateCellsAround() override;
protected:
    std::vector<Cordinate*> shipCells;
};

#endif // FRIGATE_H
