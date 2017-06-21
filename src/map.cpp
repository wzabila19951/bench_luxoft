#include "map.h"

#include <iostream>

Map::Map()
{
    Cordinate cordinate(false);
    char horizontalNav[10] = {'A','B','C','D','E','F','G','H','I','J'};
    for(int i = 1 ; i < 11; i++){
        for(int j = 0; j < 9; j++){
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

bool Map::isCellActive(const Cordinate& cordinate) const
{
    for (std::vector<Cordinate>::iterator it = cells.begin(); it != cells.end(); it++){
        if(cordinate == *it){
            if(it->IsActive()){
                std::cout << "Cell active" << std::endl;
                return true;
            } else {
                std::cout << "This point has already been shot." << std::endl;
                return false;
            }
        }
    }
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

void Map::AddShip(Ship::ShipType ship_type)
{
    /**
      Add generating positions

      *//
    std::vector<Cordinate&> cords;

    switch (ship_type) {
    case Ship::ShipType::Sloop:
        ships.push_back(new Sloop(cords));
        break;
    case Ship::ShipType::Corvete:
        ships.push_back(new Corvete(cords));
        break;
    case Ship::ShipType::Frigate:
        ships.push_back(new Frigate(cords));
        break;
    case Ship::ShipType::Linkor:
        ships.push_back(new Linkor(cords));
        break;
    default:
        break;
    }
}

