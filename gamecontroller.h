#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "maze.h"
#include "mouse.h"
#include "algorythms/random_algorythm.h"
#include "algorythms/flood_fill_algorythm.h"
#include "algorythms/left_algorythm.h"
#include "algorythms/right_algorythm.h"


class GameController
{
public:
    GameController();
    void resetGame();
    void setAlgorythm(ALGORYTHM algorythm);
    Algorythm getAlgorythm();
    std::string getMazeFile();
    void setMazeFile(std::string mazeFile);
    Maze* getMaze();
    Mouse* getMouse();
    void moveMouse();
    int mouseX();
    int mouseY();

private:
    std::shared_ptr<Algorythm> selectedAlgorythm;
    Maze* currentMaze;
    Mouse* mouse;
    std::string mazeFile;
};

#endif // GAMECONTROLLER_H
