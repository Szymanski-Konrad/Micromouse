#include "mouse.h"
#include "qdebug.h"

Mouse::Mouse()
{

}

Mouse::Mouse(int x, int y, std::shared_ptr<Tile> tile) {
    this->x = x;
    this->y = y;
    this->moveDirection = DIRECTION::SOUTH;
    this->visitTile(tile);
    this->moves = 0;
}


Mouse* Mouse::startPosition(std::shared_ptr<Tile> tile) {
    return new Mouse(0, 0, tile);
}

void Mouse::turnBack() {
    this->moves += 1;
    this->moveDirection = rotateBackMap.at(this->moveDirection);
}

void Mouse::rotateRight() {
    this->moves += 1;
    this->moveDirection = rotateRightMap.at(this->moveDirection);
}

void Mouse::rotateLeft() {
    this->moves += 1;
    this->moveDirection = rotateLeftMap.at(this->moveDirection);
}

DIRECTION Mouse::getDirection() {
    return this->moveDirection;
}

std::string Mouse::getNumberOfMoves() {
    return "Kroki: " + std::to_string(this->moves);
}

void Mouse::rotateToDirection(DIRECTION direction) {
    this->moves += 1;
    this->moveDirection = direction;
}

int Mouse::getX() {
    return this->x;
}

int Mouse::getY() {
    return this->y;
}

void Mouse::moveForward() {
    this->moves += 1;
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

void Mouse::visitTile(std::shared_ptr<Tile> tile) {
    auto isAlreadyVisited = std::find_if(this->visitedTiles.begin(), this->visitedTiles.end(), [tile](std::shared_ptr<Tile> object){ return object.get()->getX() == tile->getX() && object.get()->getY() == tile->getY();});
    if (isAlreadyVisited == this->visitedTiles.end()) {
        this->visitedTiles.insert(tile);
    }
    this->currentTile = tile;
}

std::vector<std::shared_ptr<Tile>> Mouse::getVisitedTiles() {
    std::vector<std::shared_ptr<Tile>> tiles;
    tiles.assign(visitedTiles.begin(), visitedTiles.end());
    return tiles;
}

bool Mouse::canMove() {
    DIRECTION direction = this->moveDirection;
    std::vector<DIRECTION> directions = this->currentTile.get()->possibleDirections();
    auto canMove = std::find_if(directions.begin(), directions.end(), [direction](DIRECTION object){ return object == direction;});
    return canMove != directions.end();
}
