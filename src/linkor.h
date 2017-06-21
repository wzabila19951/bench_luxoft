#ifndef LINKOR_H
#define LINKOR_H

#include "ship.h"


class Linkor : public Ship
{
public:
    Linkor(const std::vector<Cordinate*> &cells);
    bool CheckHit(const Cordinate& cell) override;
    void DeactivateCellsAround();
};

#endif // LINKOR_H
