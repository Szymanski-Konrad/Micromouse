#ifndef WALL_H
#define WALL_H

#include <direction.h>

class Wall
{
public:
    Wall();
    Wall(int x1, int y1, int x2, int y2);
    Wall(int x, int y, DIRECTION direction);
    int getX1();
    int getX2();
    int getY1();
    int getY2();

private:
    int x1;
    int x2;
    int y1;
    int y2;
};

#endif // WALL_H
