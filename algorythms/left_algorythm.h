#ifndef LEFTALGORYTHM_H
#define LEFTALGORYTHM_H

#include "algorythm.h"

class LeftAlgorythm : public Algorythm {

public:
    LeftAlgorythm();
    void calculateDistance(Maze& maze, Mouse& mouse);
    void makeMove(Maze& maze, Mouse& mouse);
};

#endif // LEFTALGORYTHM_H
