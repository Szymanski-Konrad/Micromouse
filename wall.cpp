#include "wall.h"

Wall::Wall()
{

}

Wall::Wall(int x1, int y1, int x2, int y2) : x1(x1), x2(x2), y1(y1), y2(y2) {

}

Wall::Wall(int x, int y, DIRECTION direction) {
    switch (direction) {
    case DIRECTION::NORTH:
        this->x1 = x;
        this->y1 = y;
        this->x2 = x+1;
        this->y2 = y;
        break;
    case DIRECTION::EAST:
        this->x1 = x+1;
        this->y1 = y;
        this->x2 = x+1;
        this->y2 = y+1;
        break;
    case DIRECTION::WEST:
        this->x1 = x;
        this->y1 = y;
        this->x2 = x;
        this->y2 = y+1;
        break;
    case DIRECTION::SOUTH:
        this->x1 = x;
        this->y1 = y+1;
        this->x2 = x+1;
        this->y2 = y+1;
        break;
    }
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
