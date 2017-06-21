#ifndef DRAWER_H
#define DRAWER_H

#include <string>
//#include <windns.h>
#include <iostream>
#include <vector>
#include <cordinate.h>

#include "map.h"

class Drawer
{
public:
    Drawer();
    static void DrowMap(Map &map);
    void ClearView();
    void DrowText(std::string text);
    void DrowStatistic();
};

#endif // DRAWER_H
