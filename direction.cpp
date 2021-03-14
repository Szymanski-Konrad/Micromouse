#include "direction.h"

Direction::Direction()
{

}

DIRECTION Direction::charToDirection(char c) {
    return charDirection.at(c);
}

void Direction::rotateRight() {
    currentDirection = rotateRightMap.at(currentDirection);
}

void Direction::rotateLeft() {
    currentDirection = rotateLeftMap.at(currentDirection);
}

DIRECTION Direction::getDirection() const {
    return currentDirection;
}
