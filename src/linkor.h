#ifndef LINKOR_H
#define LINKOR_H

#include "ship.h"


class Linkor : public Ship
{
public:
    Linkor(const std::vector<Cordinate*>& cells);
    virtual ~Linkor();
    void DeactivateCellsAround() override;
protected:
    std::vector<Cordinate*> shipCells;
};

#endif // LINKOR_H
