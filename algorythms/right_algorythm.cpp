#include "right_algorythm.h"

RightAlgorythm::RightAlgorythm()
{

}

void RightAlgorythm::calculateDistance(Maze &maze, Mouse &mouse) {

}

void RightAlgorythm::makeMove(Maze &maze, Mouse &mouse) {
    std::vector<DIRECTION> possibleDirections = maze.getTile(mouse.getX(), mouse.getY()).possibleDirections();
    auto isRightPossible = std::find_if(possibleDirections.begin(), possibleDirections.end(), rotateRightMap.at(mouse.getDirection()));
    if (isRightPossible != possibleDirections.end()) {
        mouse.rotateRight();
        mouse.moveForward();
        mouse.visitTile(maze.getTile(mouse.getX(), mouse.getY()));
    }
    else {
        auto isForwardPossible = std::find_if(possibleDirections.begin(), possibleDirections.end(), mouse.getDirection());
        if (isForwardPossible != possibleDirections.end()) {
            mouse.moveForward();
            mouse.visitTile(maze.getTile(mouse.getX(), mouse.getY()));
        }
        else {
            mouse.rotateRight();
        }
    }
}
