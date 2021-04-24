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
    void setMazeFile(std::string mazeFile);
    Maze* getMaze();
    Mouse* getMouse();
    bool moveMouse();
    int mouseX();
    int mouseY();
    bool isReachEnd();
    Mouse* getUserMouse();
    void enableVsMode();
    void disableVsMode();
    bool isVsModeEnabled();

private:
    std::shared_ptr<Algorythm> selectedAlgorythm;
    Maze* currentMaze;
    Mouse* mouse;
    Mouse* userMouse;
    std::string mazeFile;
    bool isVsMode;
};

#endif // GAMECONTROLLER_H
