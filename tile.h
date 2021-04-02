#ifndef TILE_H
#define TILE_H

#include <vector>
#include <map>
#include <direction.h>
#include <assert.h>
#include <wall.h>

class Tile
{
public:
    Tile();
    Tile(int x, int y,std:: map<DIRECTION, bool> walls);
    Tile(std::vector<int> values);

    int getX() const;
    int getY() const;
    bool isWall(DIRECTION direction) const;
    std::vector<Wall> wallsCoords() const;
    bool operator<(Tile other) const;
private:
    int x;
    int y;
    std::map<DIRECTION, bool> checkWalls;
    std::vector<Wall> walls;
};

#endif // TILE_H
