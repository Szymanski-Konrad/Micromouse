#ifndef MOUSE_H
#define MOUSE_H

#include <tile.h>
#include <set>
#include <unordered_set>
#include <memory>

class Mouse
{
public:
    Mouse();
    Mouse(int x, int y, std::shared_ptr<Tile> tile);

    static Mouse* startPosition(std::shared_ptr<Tile> tile);
    int getX();
    int getY();
    void rotateLeft();
    void rotateRight();
    void rotateToDirection(DIRECTION direction);
    void turnBack();
    DIRECTION getDirection();
    void moveForward();
    void visitTile(std::shared_ptr<Tile> tile);
    std::vector<std::shared_ptr<Tile>> getVisitedTiles();
    bool canMove();
private:
    int x;
    int y;
    DIRECTION moveDirection;
    std::set<std::shared_ptr<Tile>> visitedTiles;
    std::shared_ptr<Tile> currentTile;
};

#endif // MOUSE_H
