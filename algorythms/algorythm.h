#ifndef ALGORYTHM_H
#define ALGORYTHM_H

#include "maze.h"
#include "mouse.h"
#include "direction.h"
#include "algorithm"
#include "random_algorythm.h"
#include "flood_fill_algorythm.h"
#include "left_algorythm.h"
#include "right_algorythm.h"

enum class ALGORYTHM {
  RIGHT_FIRST,
  LEFT_FIRST,
  FLOOD_FILL,
  RANDOM,
};

class Algorythm
{
public:
    Algorythm();
    virtual void calculateDistance(Maze& maze, Mouse& mouse);
    virtual void makeMove(Maze& maze, Mouse& mouse);
};

#endif // ALGORYTHM_H
