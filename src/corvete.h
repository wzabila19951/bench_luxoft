#ifndef CORVETE_H
#define CORVETE_H

#include "ship.h"


class Corvete : public Ship
{
public:
    Corvete(const std::vector<Cordinate*> &cells);
    bool CheckHit(const Cordinate& cell) override;
    void DeactivateCellsAround() override;
};

#endif // CORVETE_H
