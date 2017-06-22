#include "drawer.h"
#include <iostream>
#include <algorithm>

#include "cordinate.h"

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

void DrawHoryzontalLine(const char ch, const int count) {
    for (int i = 0; i < count * 2 - 1; ++i) {
        std::cout << ch;
    }
    std::cout << std::endl;
}

Drawer::Drawer()
{

}

class FindPredicate {
public :
    FindPredicate(char ch, int i) : ch_(ch), i_(i) {
    }
    bool operator ()(Cordinate& cord) {
        return cord.horizontal == ch_ && cord.vertical == i_;
    }
private:
    const char ch_;
    const int i_;
};

void Drawer::DrowMap(Map& map)
{
    for(int i = 0; i < 10 ; i++){
        std::cout << horizontalNav[i] << '|';
    }
    std::cout << std::endl;

    DrawHoryzontalLine('_', 11);

    for (int i = 1; i < 11; ++i) {
        for (char ch = 'A'; ch <= 'J'; ++ch) {
            FindPredicate pred(ch, i);
            Cordinate cord = *(std::find_if(map.cells.begin(), map.cells.end(), pred));
            if(!map.mapSwitch){
                std::cout << '|' << GetStateSymbol(cord.state);
            } else {
               std::cout << '|' << _GetStateSymbol(cord.state);
            }
        }
        std::cout << '|' <<  std::endl;
    }

    DrawHoryzontalLine('_', 11);
}

void Drawer::ClearView() const
{
   // std::system("cls");
}

void Drawer::DrawText(const std::string& text) const
{
    std::cout << std::endl;
    std::cout << text << std::endl;
}

void Drawer::DrawStatistic() const
{
//    int cout = 0;
//    for(Cordinate cell: ){
//        if(cell.state == Cordinate::State::Hited ){
//            cout++;
//        }
//    }
//    std::cout << "Number of dead ships - " << cout << std::endl;
}
