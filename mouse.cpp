#include "mouse.h"


Mouse::Mouse()
{

}

Mouse::Mouse(int x, int y) {
    this->x = x;
    this->y = y;
}

Mouse* Mouse::startPosition() {
    return new Mouse(0, 0);
}

void Mouse::moveDown() {
    this->y -= 1;
}

void Mouse::moveLeft() {
    this->x -= 1;
}

void Mouse::moveRight() {
    this->x += 1;
}

void Mouse::moveUp() {
    this->y += 1;
}

int Mouse::getX() {
    return this->x;
}

int Mouse::getY() {
    return this->y;
}

void Mouse::visitTile(Tile tile) {
    this->visitedTiles.insert(tile);
}

std::vector<Tile> Mouse::getVisitedTiles() {
    std::vector<Tile> tiles;
    tiles.assign(visitedTiles.begin(), visitedTiles.end());
    return tiles;
}
