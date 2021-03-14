#ifndef DIRECTION_H
#define DIRECTION_H

#include <vector>
#include <map>
#include <string>

enum class DIRECTION {
    NORTH,
    EAST,
    SOUTH,
    WEST,
};

const std::map<char, DIRECTION> charDirection = {
    {'n', DIRECTION::NORTH},
    {'e', DIRECTION::EAST},
    {'s', DIRECTION::SOUTH},
    {'w', DIRECTION::WEST},
};

const std::map<DIRECTION, DIRECTION> rotateLeftMap = {
    {DIRECTION::NORTH, DIRECTION::WEST},
    {DIRECTION::EAST, DIRECTION::NORTH},
    {DIRECTION::SOUTH, DIRECTION::EAST},
    {DIRECTION::WEST, DIRECTION::SOUTH},
};

const std::map<DIRECTION, DIRECTION> rotateRightMap = {
    {DIRECTION::NORTH, DIRECTION::EAST},
    {DIRECTION::EAST, DIRECTION::SOUTH},
    {DIRECTION::SOUTH, DIRECTION::WEST},
    {DIRECTION::WEST, DIRECTION::NORTH},
};

class Direction
{
public:

    Direction();
    Direction(DIRECTION direction);

    void rotateLeft();
    void rotateRight();
    DIRECTION getDirection() const;

    DIRECTION charToDirection(char c);
private:

    DIRECTION currentDirection;
};

#endif // DIRECTION_H
