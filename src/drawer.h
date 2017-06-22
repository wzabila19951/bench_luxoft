#ifndef DRAWER_H
#define DRAWER_H

#include <string>
#include <iostream>
#include <vector>

#include "map.h"

class Drawer
{
public:
    Drawer();
    void DrowMap(Map &map);
    void ClearView() const ;
    void DrawText(const std::string& text) const ;
    void DrawStatistic() const;
    const char horizontalNav[10] = {'A','B','C','D','E','F','G','H','I','J'};
};

#endif // DRAWER_H
