#include "map.h"

#include <iostream>


Map::Map(const bool& _mapSwitch): mapSwitch(_mapSwitch)
{
    Cordinate cordinate(false);
    char horizontalNav[10] = {'A','B','C','D','E','F','G','H','I','J'};
    for(int i = 1 ; i < 11; i++){
        for(int j = 0; j < 10; j++){
            cordinate.horizontal = horizontalNav[j];
            cordinate.vertical = i;
            cells.push_back(cordinate);
        }
    }

    AddShip(Ship::ShipType::Sloop);
    AddShip(Ship::ShipType::Sloop);
    AddShip(Ship::ShipType::Sloop);
    AddShip(Ship::ShipType::Sloop);
    AddShip(Ship::ShipType::Corvete);
    AddShip(Ship::ShipType::Corvete);
    AddShip(Ship::ShipType::Corvete);
    AddShip(Ship::ShipType::Frigate);
    AddShip(Ship::ShipType::Frigate);
    AddShip(Ship::ShipType::Linkor);
}

Map::~Map () {
    for(auto ship : ships) {
        delete ship;
    }
}

bool Map::isCellActive(const Cordinate& cordinate)
{
    for(Cordinate& cell : cells){
        if(cell == cordinate){
            if(cell.IsActive()){
              //  std::cout << "Cell active" << std::endl;
                return true;
            } else {
              //  std::cout << "This point has already been shot." << std::endl;
                return false;
            }
        }
    }
    return false;
}

void Map::DeactivatedCell(const Cordinate& cordinate, const Cordinate::State new_state)
{
    for(Cordinate& cell : cells) {
        if (cell == cordinate) {
            cell.state = new_state;
            return;
        }
    }
}

bool Map::TakeShot(const Cordinate& cordinate)
{
    for(Ship* ship : ships) {
        if (ship->CheckHit(cordinate)) {
           return true;
        }
    }
    return false;
}

Cordinate* Map::getCell (const char ch, const int i) {
    for(Cordinate& cell : cells) {
        if (cell == Cordinate(ch, i, false)) {
           // std::cout << "found" << std::endl;
            return &cell;
        }
    }
}

void Map::AddShip(Ship::ShipType ship_type)
{

    std::vector<Cordinate*> cords;

    switch (ship_type) {
    case Ship::ShipType::Sloop: {
        Cordinate* cord = getCell(sloop_coords.back().first, sloop_coords.back().second);
        cord->state = Cordinate::State::Ship;
        sloop_coords.pop_back();
        cords.push_back(cord);
        ships.push_back(new Sloop(cords));
        break;
    }
    case Ship::ShipType::Corvete: {
        for (int i = 0; i < 2; ++i) {
            Cordinate* cord = getCell(corvete_coords.back().first, corvete_coords.back().second);
            cord->state = Cordinate::State::Ship;
            corvete_coords.pop_back();
            cords.push_back(cord);
        }
        ships.push_back(new Corvete(cords));
        break;
    }
    case Ship::ShipType::Frigate: {
        for (int i = 0; i < 3; ++i) {
            Cordinate* cord = getCell(frigate_coords.back().first, frigate_coords.back().second);
            cord->state = Cordinate::State::Ship;
            frigate_coords.pop_back();
            cords.push_back(cord);
        }
        ships.push_back(new Frigate(cords));
        break;
    }
    case Ship::ShipType::Linkor: {
        for (int i = 0; i < 4; ++i) {
            Cordinate* cord = getCell(lincore_coords.back().first, lincore_coords.back().second);
            cord->state = Cordinate::State::Ship;
            lincore_coords.pop_back();
            cords.push_back(cord);
        }
        ships.push_back(new Linkor(cords));
        break;
    }
    default:
        break;
    }
}

