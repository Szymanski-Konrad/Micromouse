#ifndef DIRECTION_H
#define DIRECTION_H

#include <vector>
#include <map>
#include <string>

/**
*  @file direction.h
*  @brief Direction enum
*/

/// @brief Possible directions in maze
enum class DIRECTION {
    /// North direction
    NORTH,
    /// East direction
    EAST,
    /// South direction
    SOUTH,
    /// West direction
    WEST,
};

/// @brief Translate direction when rotate right
const std::map<DIRECTION, DIRECTION> rotateLeftMap = {
    {DIRECTION::NORTH, DIRECTION::WEST},
    {DIRECTION::EAST, DIRECTION::NORTH},
    {DIRECTION::SOUTH, DIRECTION::EAST},
    {DIRECTION::WEST, DIRECTION::SOUTH},
};

/// @brief Translate direction when rotate right
const std::map<DIRECTION, DIRECTION> rotateRightMap = {
    {DIRECTION::NORTH, DIRECTION::EAST},
    {DIRECTION::EAST, DIRECTION::SOUTH},
    {DIRECTION::SOUTH, DIRECTION::WEST},
    {DIRECTION::WEST, DIRECTION::NORTH},
};

/// @brief Translate direction when rotate back
const std::map<DIRECTION, DIRECTION> rotateBackMap = {
    {DIRECTION::NORTH, DIRECTION::SOUTH},
    {DIRECTION::EAST, DIRECTION::WEST},
    {DIRECTION::SOUTH, DIRECTION::NORTH},
    {DIRECTION::WEST, DIRECTION::EAST},
};

#endif // DIRECTION_H
