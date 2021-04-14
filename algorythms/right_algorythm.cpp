#include "right_algorythm.h"

RightAlgorythm::RightAlgorythm()
{

}

void RightAlgorythm::calculateDistance(Maze &maze, Mouse &mouse) {

}

void RightAlgorythm::makeMove(Maze &maze, Mouse &mouse) {
    std::vector<DIRECTION> possibleDirections = maze.getTile(mouse.getX(), mouse.getY()).possibleDirections();
    DIRECTION rotateDirection = rotateRightMap.at(mouse.getDirection());
    auto isRightPossible = std::find_if(possibleDirections.begin(), possibleDirections.end(), [rotateDirection](DIRECTION object){ return object == rotateDirection;});
    if (isRightPossible != possibleDirections.end()) {
        mouse.rotateRight();
        mouse.moveForward();
        mouse.visitTile(maze.getTile(mouse.getX(), mouse.getY()));
    }
    else {
        DIRECTION mouseDirection = mouse.getDirection();
        auto isForwardPossible = std::find_if(possibleDirections.begin(), possibleDirections.end(), [mouseDirection](DIRECTION object){ return object == mouseDirection;});
        if (isForwardPossible != possibleDirections.end()) {
            mouse.moveForward();
            mouse.visitTile(maze.getTile(mouse.getX(), mouse.getY()));
        }
        else {
            mouse.rotateRight();
        }
    }
}
