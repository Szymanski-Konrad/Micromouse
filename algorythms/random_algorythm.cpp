#include "random_algorythm.h"

#include <stdlib.h>

RandomAlgorythm::RandomAlgorythm()
{

}

void RandomAlgorythm::calculateDistance(Maze &maze, Mouse &mouse) {

}

void RandomAlgorythm::makeMove(Maze &maze, Mouse &mouse) {
    std::vector<DIRECTION> possibleDirections = maze.getTile(mouse.getX(), mouse.getY()).possibleDirections();
    int secretNumber = rand() % possibleDirections.size() + 1;
    DIRECTION randomDirection = possibleDirections.at(secretNumber);
    if (randomDirection == rotateLeftMap.at(mouse.getDirection())) {
        mouse.rotateLeft();
    } else if (randomDirection == rotateRightMap.at(mouse.getDirection())) {
        mouse.rotateRight();
    }

    mouse.moveForward();
    mouse.visitTile(maze.getTile(mouse.getX(), mouse.getY()));
}
