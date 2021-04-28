#ifndef ALGORYTHM_H
#define ALGORYTHM_H

#include "maze.h"
#include "mouse.h"
#include "direction.h"
#include "algorithm"

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
    virtual void makeMove(Maze& maze, Mouse& mouse) { };
    ~Algorythm() {};
};

#endif // ALGORYTHM_H
