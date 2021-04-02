#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "maze.h"
#include "mouse.h"
#include "algorythms/algorythm.h"


class GameController
{
public:
    GameController();
    void resetGame();
    void setAlgorythm(ALGORYTHM algorythm);
    ALGORYTHM getAlgorythm();
    std::string getMazeFile();
    void setMazeFile(std::string mazeFile);
    Maze* getMaze();
    Mouse* getMouse();
    int mouseX();
    int mouseY();

private:
    ALGORYTHM selectedAlgorythm;
    Maze* currentMaze;
    Mouse* mouse;
    std::string mazeFile;

};

#endif // GAMECONTROLLER_H
