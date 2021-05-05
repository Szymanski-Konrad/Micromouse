#ifndef LEFTALGORYTHM_H
#define LEFTALGORYTHM_H

#include "algorythm.h"

/**
*  @file left_algorythm.h
*  @brief Left Algorythm implementation
*/

class LeftAlgorythm : public Algorythm {

public:
    LeftAlgorythm();

    /// @brief Deciding mouse moving
    /// @details Function check which directions are possible for mouse and choose best way depends on selected algorythm
    /// @param maze Current loaded maze
    /// @param moving mouse
    void makeMove(Maze& maze, Mouse& mouse);
};

#endif // LEFTALGORYTHM_H
