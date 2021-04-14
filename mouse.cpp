#include "mouse.h"
#include "qdebug.h"

Mouse::Mouse()
{

}

Mouse::Mouse(int x, int y) {
    this->x = x;
    this->y = y;
    this->moveDirection = DIRECTION::SOUTH;
}

Mouse* Mouse::startPosition() {
    return new Mouse(0, 0);
}

void Mouse::rotateRight() {
    this->moveDirection = rotateRightMap.at(this->moveDirection);
}

void Mouse::rotateLeft() {
    this->moveDirection = rotateLeftMap.at(this->moveDirection);
}

DIRECTION Mouse::getDirection() {
    return this->moveDirection;
}

void Mouse::rotateToDirection(DIRECTION direction) {
    this->moveDirection = direction;
}

int Mouse::getX() {
    return this->x;
}

int Mouse::getY() {
    return this->y;
}

void Mouse::moveForward() {
    if (moveDirection == DIRECTION::NORTH) {
        this->y -= 1;
    } else if (moveDirection == DIRECTION::SOUTH) {
        this->y += 1;
    } else if (moveDirection == DIRECTION::EAST) {
        this->x += 1;
    } else if (moveDirection == DIRECTION::WEST) {
        this->x -= 1;
    }
}

void Mouse::visitTile(Tile tile) {
    this->visitedTiles.insert(tile);
}

std::vector<Tile> Mouse::getVisitedTiles() {
    std::vector<Tile> tiles;
    tiles.assign(visitedTiles.begin(), visitedTiles.end());
    return tiles;
}
