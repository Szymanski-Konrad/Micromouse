#include "left_algorythm.h"

LeftAlgorythm::LeftAlgorythm()
{

}

void LeftAlgorythm::makeMove(Maze &maze, Mouse &mouse) {
    std::vector<DIRECTION> possibleDirections = maze.getTile(mouse.getX(), mouse.getY()).get()->possibleDirections();
    DIRECTION rotateDirection = rotateLeftMap.at(mouse.getDirection());
    auto isLeftPossible = std::find_if(possibleDirections.begin(), possibleDirections.end(), [&](const DIRECTION object) {return object == rotateDirection;});
    if (isLeftPossible != possibleDirections.end()) {
        mouse.rotateLeft();
    }
    else {
        DIRECTION mouseDirection = mouse.getDirection();
        auto isForwardPossible = std::find_if(possibleDirections.begin(), possibleDirections.end(), [mouseDirection](DIRECTION object){ return object == mouseDirection;});
        if (isForwardPossible != possibleDirections.end()) {

        }
        else {
            rotateDirection = rotateRightMap.at(mouse.getDirection());
            auto isRightPossible = std::find_if(possibleDirections.begin(), possibleDirections.end(), [rotateDirection](DIRECTION object){ return object == rotateDirection;});
            if (isRightPossible != possibleDirections.end()) {
                mouse.rotateRight();
            }
            else {
                mouse.turnBack();
            }
        }
    }

    mouse.moveForward();
    mouse.visitTile(maze.getTile(mouse.getX(), mouse.getY()));
}
