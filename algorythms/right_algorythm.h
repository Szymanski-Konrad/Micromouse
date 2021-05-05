#ifndef RIGHTALGORYTHM_H
#define RIGHTALGORYTHM_H

#include "algorythm.h"

/**
*  @file right_algorythm.h
*  @brief Right Algorythm implementation
*/

class RightAlgorythm : public Algorythm
{
public:
    RightAlgorythm();

    /// @brief Deciding mouse moving
    /// @details Function check which directions are possible for mouse and choose best way depends on selected algorythm
    /// @param maze Current loaded maze
    /// @param moving mouse
    void makeMove(Maze& maze, Mouse& mouse);
};

#endif // RIGHTALGORYTHM_H
