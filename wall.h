#ifndef WALL_H
#define WALL_H

#include <direction.h>

/**
*  @file wall.h
*  @brief Representation of inpassable object in maze
*/

class Wall
{
public:
    /// @brief Default class constructor
    Wall();

    /// @brief Class constructor
    /// @details Construct wall from coordinates and direction
    /// @param x X position of tile
    /// @param y Y position of tile
    /// @param direction wall direction
    Wall(int x, int y, DIRECTION direction);

    /// @brief get start X position
    /// @return start X position
    int getX1();

    /// @brief get end X position
    /// @return end X position
    int getX2();

    /// @brief get start Y position
    /// @return start Y position
    int getY1();

    /// @brief get end Y position
    /// @return end Y position
    int getY2();

private:
    int x1;
    int x2;
    int y1;
    int y2;
};

#endif // WALL_H
