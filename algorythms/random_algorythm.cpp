#include "random_algorythm.h"

#include <stdlib.h>

RandomAlgorythm::RandomAlgorythm()
{

}

void RandomAlgorythm::makeMove(Maze &maze, Mouse &mouse) {
    std::vector<DIRECTION> possibleDirections = maze.getTile(mouse.getX(), mouse.getY()).get()->possibleDirections();
    int secretNumber = rand() % possibleDirections.size();
    DIRECTION randomDirection = possibleDirections.at(secretNumber);
    if (randomDirection == rotateLeftMap.at(mouse.getDirection())) {
        mouse.rotateLeft();
    } else if (randomDirection == rotateRightMap.at(mouse.getDirection())) {
        mouse.rotateRight();
    } else {
        DIRECTION mouseDirection = mouse.getDirection();
        auto isForwardPossible = std::find_if(possibleDirections.begin(), possibleDirections.end(), [mouseDirection](DIRECTION object){ return object == mouseDirection;});
        if (isForwardPossible != possibleDirections.end()) {
            mouse.moveForward();
            mouse.visitTile(maze.getTile(mouse.getX(), mouse.getY()));
        }
        else {
            mouse.rotateLeft();
        }
    }

}
