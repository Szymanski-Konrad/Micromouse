#ifndef RANDOMALGORYTHM_H
#define RANDOMALGORYTHM_H

#include "algorythm.h"

class RandomAlgorythm : public Algorythm
{
public:
    RandomAlgorythm();
    void calculateDistance(Maze& maze, Mouse& mouse);
    void makeMove(Maze& maze, Mouse& mouse);
};

#endif // RANDOMALGORYTHM_H
