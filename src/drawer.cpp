#include "drawer.h"
#include <iostream>
#include <algorithm>

#include "cordinate.h"

const int map_size = 10;

char GetStateSymbol(Cordinate::State state) {
    switch (state) {
    case Cordinate::State::Active: return ' ';
    case Cordinate::State::Hited: return 'x';
    case Cordinate::State::Ship: return '#';
    case Cordinate::State::Shooted: return 'o';
    default: return ' ';
    }
}

char _GetStateSymbol(Cordinate::State state) {
    switch (state) {
    case Cordinate::State::Active: return ' ';
    case Cordinate::State::Hited: return 'x';
    case Cordinate::State::Ship: return ' ';
    case Cordinate::State::Shooted: return 'o';
    default: return ' ';
    }
}

void DrawHoryzontalLine(const char symbol, const int count) {
    for (int i = 0; i < count * 2 - 1; ++i) {
        std::cout << symbol;
    }
    std::cout << std::endl;
}

Drawer::Drawer()
{

}

class FindPredicate {
public :
    FindPredicate(const char horyzontal, const int vertical) : horyzontal_(horyzontal), vetical_(vertical) {
    }
    bool operator ()(const Cordinate& cord) {
        return cord.horizontal == horyzontal_ && cord.vertical == vetical_;
    }
private:
    const char horyzontal_;
    const int vetical_;
};

void Drawer::DrawMap(const Map &map)
{
    for(int i = 0; i < map_size ; i++){
        std::cout << horizontalNav[i] << '|';
    }
    std::cout << std::endl;

    DrawHoryzontalLine('_', map_size + 1);

    for (int vertical = 1; vertical < map_size + 1; ++vertical) {
        for (char horyzontal = 'A'; horyzontal <= 'J'; ++horyzontal) {
            FindPredicate pred(horyzontal, vertical);
            Cordinate cord = *(std::find_if(map.cells.begin(), map.cells.end(), pred));
            if(!map.mapSwitch){
                std::cout << '|' << GetStateSymbol(cord.state);
            } else {
               std::cout << '|' << _GetStateSymbol(cord.state);
            }
        }
        std::cout << '|' <<  std::endl;
    }

    DrawHoryzontalLine('_', map_size + 1);
}

void Drawer::ClearView() const
{
}

void Drawer::DrawText(const std::string& text) const
{
    std::cout << std::endl;
    std::cout << text << std::endl;
}

void Drawer::DrawStatistic() const
{
}
