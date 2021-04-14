#include "left_algorythm.h"

#include <QDebug>

LeftAlgorythm::LeftAlgorythm()
{

}


void LeftAlgorythm::calculateDistance(Maze &maze, Mouse &mouse) {

}

void LeftAlgorythm::makeMove(Maze &maze, Mouse &mouse) {
    qDebug() << "Zastanawiam sie nad ruchem...";
    std::vector<DIRECTION> possibleDirections = maze.getTile(mouse.getX(), mouse.getY()).possibleDirections();
    DIRECTION rotateDirection = rotateLeftMap.at(mouse.getDirection());
    auto it = std::find_if(possibleDirections.begin(), possibleDirections.end(), [&](const DIRECTION object) {return object == rotateDirection;});
    if (it != possibleDirections.end()) {
        qDebug() << "Ruszam sie w lewo";
        mouse.rotateLeft();
        mouse.moveForward();
        mouse.visitTile(maze.getTile(mouse.getX(), mouse.getY()));
    }
    else {
        qDebug() << "Sprawdzam inne sciezki";
        DIRECTION mouseDirection = mouse.getDirection();
        auto isForwardPossible = std::find_if(possibleDirections.begin(), possibleDirections.end(), [mouseDirection](DIRECTION object){ return object == mouseDirection;});
        if (isForwardPossible != possibleDirections.end()) {
            qDebug() << "Czas ruszyć do przodu!";
            mouse.moveForward();
            mouse.visitTile(maze.getTile(mouse.getX(), mouse.getY()));
        }
        else {
            qDebug() << "Jednak w lewo";
            mouse.rotateLeft();
        }
    }
}
