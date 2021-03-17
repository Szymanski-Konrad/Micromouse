#include "tile.h"

Tile::Tile(int x, int y, std::map<DIRECTION, bool> checkWalls) :
    x(x), y(y), checkWalls(checkWalls)
{

}

Tile::Tile(std::vector<int> values) {
    assert(values.size() == 6);
    this->x = values.at(0);
    this->y = values.at(1);
    this->checkWalls = {
        {DIRECTION::NORTH, values.at(2)},
        {DIRECTION::EAST, values.at(3)},
        {DIRECTION::SOUTH, values.at(4)},
        {DIRECTION::WEST, values.at(5)},
    };
    if (values.at(2) > 0)
        walls.push_back(Wall(this->x, this->y, DIRECTION::NORTH));
    if (values.at(3) > 0)
        walls.push_back(Wall(this->x, this->y, DIRECTION::EAST));
    if (values.at(4) > 0)
        walls.push_back(Wall(this->x, this->y, DIRECTION::SOUTH));
    if (values.at(5) > 0)
        walls.push_back(Wall(this->x, this->y, DIRECTION::WEST));
}

int Tile::getX() const {
    return x;
}

int Tile::getY() const {
    return y;
}

bool Tile::isWall(DIRECTION direction) const {
    return checkWalls.at(direction);
}

std::vector<Wall> Tile::wallsCoords() const {
    return walls;
}


