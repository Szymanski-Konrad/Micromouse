#ifndef FLOODFILLALGORYTHM_H
#define FLOODFILLALGORYTHM_H

#include "algorythm.h"


class FloodFillAlgorythm : public Algorythm
{
public:
    FloodFillAlgorythm();
    void makeMove(Maze& maze, Mouse& mouse);
};

#endif // FLOODFILLALGORYTHM_H
