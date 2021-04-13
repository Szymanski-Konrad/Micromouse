#include "left_algorythm.h"

LeftAlgorythm::LeftAlgorythm()
{

}


void LeftAlgorythm::calculateDistance(Maze &maze, Mouse &mouse) {

}

void LeftAlgorythm::makeMove(Maze &maze, Mouse &mouse) {
    std::vector<DIRECTION> possibleDirections = maze.getTile(mouse.getX(), mouse.getY()).possibleDirections();
    auto isLeftPossible = std::find_if(possibleDirections.begin(), possibleDirections.end(), rotateLeftMap.at(mouse.getDirection()));
    if (isLeftPossible != possibleDirections.end()) {
        mouse.rotateLeft();
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
            mouse.rotateLeft();
        }
    }
}
