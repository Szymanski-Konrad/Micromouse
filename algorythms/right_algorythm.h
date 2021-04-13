#ifndef RIGHTALGORYTHM_H
#define RIGHTALGORYTHM_H

#include "algorythm.h"

class RightAlgorythm : public Algorythm
{
public:
    RightAlgorythm();
    void calculateDistance(Maze& maze, Mouse& mouse);
    void makeMove(Maze& maze, Mouse& mouse);
};

#endif // RIGHTALGORYTHM_H
