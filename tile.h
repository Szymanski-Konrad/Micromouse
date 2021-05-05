#ifndef TILE_H
#define TILE_H

#include <vector>
#include <map>
#include <direction.h>
#include <assert.h>
#include <wall.h>

#include <algorithm>

/**
*  @file tile.h
*  @brief Square part of maze with max 4 walls
*/

class Tile
{
public:
    /// @brief Default constructor
    Tile();

    /// @brief Class constructor
    /// @param x tile X position
    /// @param y tile Y positon
    /// @param walls map of direction with walls
    Tile(int x, int y,std:: map<DIRECTION, bool> walls);

    /// @brief Custom class constructor
    /// @param values values from file \n (x,y, N, W, S, E)
    Tile(std::vector<int> values);

    /// @brief get tile X position
    /// @return X position
    int getX() const;

    /// @brief get tile Y position
    /// @return Y position
    int getY() const;

    /// @brief check if is wall on direction
    /// @param direction direction to check
    /// @return boolean value if wall exists or not
    bool isWall(DIRECTION direction) const;

    /// @brief get wall coordinations
    /// @return vector of tile walls
    std::vector<Wall> wallsCoords() const;

    /// @brief get possible directions
    /// @details Possible directions are this, where is no wall
    /// @return vector of possible directions
    std::vector<DIRECTION> possibleDirections() const;

    /// @brief compare operator override
    bool operator<(Tile other) const;
private:
    int x;
    int y;
    std::map<DIRECTION, bool> checkWalls;
    std::vector<Wall> walls;
};

#endif // TILE_H
