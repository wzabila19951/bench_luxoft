#ifndef CORVETE_H
#define CORVETE_H

#include "ship.h"

class Corvete : public Ship
{
public:
    Corvete(const std::vector<Cordinate *> &cells);
    virtual ~Corvete();
    void DeactivateCellsAround() override;
protected:
    std::vector<Cordinate*> shipCells;
};

#endif // CORVETE_H
