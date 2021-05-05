#ifndef MOUSE_H
#define MOUSE_H

#include <tile.h>
#include <set>
#include <unordered_set>
#include <memory>

/**
*  @file mouse.h
*  @brief Represents functionality of robot
*/
class Mouse
{
public:
    /// @brief Default constructor
    Mouse();

    /// @brief Class constructor
    /// @param x starting x position
    /// @param y starting y position
    /// @param tile startin tile
    Mouse(int x, int y, std::shared_ptr<Tile> tile);

    /// @brief Create new mouse object in start position
    /// @param tile starting tile
    static Mouse* startPosition(std::shared_ptr<Tile> tile);

    /// @brief get mouse X position
    /// @return mouse X position
    int getX();

    /// @brief get mouse Y position
    /// @return mouse Y position
    int getY();

    /// @brief turn mouse left
    void rotateLeft();

    /// @brief turn mouse right
    void rotateRight();

    /// @brief turn mouse to specific direction
    /// @details When algorythm mouse can rotate only left or right, user mouse can rotate in every direction
    /// @param direction rotate direction
    void rotateToDirection(DIRECTION direction);

    /// @brief turn mouse back
    void turnBack();

    /// @brief get current mouse direction
    /// @return Current mouse direction
    DIRECTION getDirection();

    /// @brief move mouse forward
    void moveForward();

    /// @brief mouse visit new tile
    /// @param tile tile to which mouse moved
    void visitTile(std::shared_ptr<Tile> tile);

    /// @brief get all visited tiles
    /// @return all visited tiles
    std::vector<std::shared_ptr<Tile>> getVisitedTiles();

    /// @brief check if mouse can move forward
    /// @return boolean value of move possibility
    bool canMove();

    /// @brief get number of mouse moves
    /// @return number of moves converted to string
    std::string getNumberOfMoves();
private:
    int x;
    int y;
    int moves;
    DIRECTION moveDirection;
    std::set<std::shared_ptr<Tile>> visitedTiles;
    std::shared_ptr<Tile> currentTile;
};

#endif // MOUSE_H
