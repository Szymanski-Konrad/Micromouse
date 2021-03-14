#ifndef TILE_H
#define TILE_H

#include <vector>
#include <map>
#include <direction.h>

class Tile
{
public:
    Tile();
    Tile(int x, int y,std:: map<DIRECTION, bool> walls);

    int getX() const;
    int getY() const;
    bool isWall(DIRECTION direction) const;
    std::map<DIRECTION, bool> getWalls() const;

private:
    int x;
    int y;
    std::map<DIRECTION, bool> walls;
};

#endif // TILE_H
