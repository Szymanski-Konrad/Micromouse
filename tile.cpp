#include "tile.h"

Tile::Tile(int x, int y, std::map<DIRECTION, bool> walls) :
    x(x), y(y), walls(walls)
{

}

int Tile::getX() const {
    return x;
}

int Tile::getY() const {
    return y;
}

std::map<DIRECTION, bool> Tile::getWalls() const {
    return walls;
}

bool Tile::isWall(DIRECTION direction) const {
    return walls.at(direction);
}
