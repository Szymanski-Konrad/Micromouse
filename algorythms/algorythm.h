#ifndef ALGORYTHM_H
#define ALGORYTHM_H

#include "maze.h"
#include "mouse.h"
#include "direction.h"
#include "algorithm"

/**
*  @file algorythm.h
*  @brief Algorythm abstraction
*/

/// @brief Algorythms enum
enum class ALGORYTHM {
    /// Right wall first algorythm
    RIGHT_FIRST,
    /// Left wall first algorythm
    LEFT_FIRST,
    /// Random direction algorythm
    RANDOM,
};

class Algorythm
{
public:
    /// @brief Default constructor
    Algorythm();

    /// @brief Deciding mouse moving
    /// @details Function check which directions are possible for mouse and choose best way depends on selected algorythm
    /// @param maze Current loaded maze
    /// @param moving mouse
    virtual void makeMove(Maze& maze, Mouse& mouse) { };

    /// @brief Class destructor
    ~Algorythm() {};
};

#endif // ALGORYTHM_H
