#include "wall.h"

Wall::Wall()
{

}

Wall::Wall(int x1, int y1, int x2, int y2) : x1(x1), x2(x2), y1(y1), y2(y2) {

}

Wall::Wall(int x, int y, DIRECTION direction) {
    this->x1 = direction == DIRECTION::EAST ? x+1 : x;
    this->y1 = direction == DIRECTION::SOUTH ? y+1 : y;
    this->x2 = direction == DIRECTION::EAST || direction == DIRECTION::SOUTH ? x+1 : x;
    this->y2 = direction == DIRECTION::NORTH ? y : y+1;
}

int Wall::getX1() {
    return x1;
}

int Wall::getX2() {
    return x2;
}

int Wall::getY1() {
    return y1;
}

int Wall::getY2() {
    return y2;
}
