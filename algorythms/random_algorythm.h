#ifndef RANDOMALGORYTHM_H
#define RANDOMALGORYTHM_H

#include "algorythm.h"

/**
*  @file random_algorythm.h
*  @brief Random Algorythm implementation
*/

class RandomAlgorythm : public Algorythm
{
public:
    RandomAlgorythm();

    /// @brief Deciding mouse moving
    /// @details Function check which directions are possible for mouse and choose best way depends on selected algorythm
    /// @param maze Current loaded maze
    /// @param moving mouse
    void makeMove(Maze& maze, Mouse& mouse);
};

#endif // RANDOMALGORYTHM_H
