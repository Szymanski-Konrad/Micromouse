#ifndef MOUSE_H
#define MOUSE_H

#include <tile.h>
#include <set>
#include <unordered_set>

class Mouse
{
public:
    Mouse();
    Mouse(int x, int y);

    static Mouse* startPosition();
    int getX();
    int getY();
    void rotateLeft();
    void rotateRight();
    void rotateToDirection(DIRECTION direction);
    DIRECTION getDirection();
    void moveForward();
    void visitTile(Tile tile);
    std::vector<Tile> getVisitedTiles();
private:
    int x;
    int y;
    DIRECTION moveDirection;
    std::set<Tile> visitedTiles;
};

#endif // MOUSE_H
