#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "maze.h"
#include "mouse.h"
#include "algorythms/random_algorythm.h"
#include "algorythms/left_algorythm.h"
#include "algorythms/right_algorythm.h"


/**
*  @file gamecontroller.h
*  @brief Controlling everything inside application
*/

class GameController
{
public:
    /// @brief Default constructor
    GameController();

    /// @brief Reset state of game
    /// @details move mouses back and print starting state
    void resetGame();

    /// @brief Set selected algorythm
    /// @param algorythm selected algorythm
    void setAlgorythm(ALGORYTHM algorythm);

    /// @brief get current algorythm
    /// @return current algorythm
    Algorythm getAlgorythm();

    /// @brief set maze source file
    /// @param mazeFile file name
    void setMazeFile(std::string mazeFile);

    /// @brief get current maze
    /// @return curret maze
    Maze* getMaze();

    /// @brief get algorythm mouse
    /// @return algorythm mouse
    Mouse* getMouse();

    /// @brief move algorythm mouse
    bool moveMouse();

    /// @brief get algorythm mouse X position
    /// @return algorythm mouse X position
    int mouseX();

    /// @brief get algorythm mouse Y position
    /// @return algorythm mouse Y position
    int mouseY();

    /// @brief check if mouse reach center of maze
    /// @param isUser boolean value determine user or algorythm mouse
    /// @return boolean value whether reach center or not
    bool isReachEnd(bool isUser);

    /// @brief get user mouse
    /// @return user mouse
    Mouse* getUserMouse();

    /// @brief move user mouse
    /// @param direction move direction
    /// @return boolean value if can move to direction
    bool moveUserMouse(DIRECTION direction);

    /// @brief switch to player vs algoryth mode
    void enableVsMode();

    /// @brief switch to algorytm mode
    void disableVsMode();

    /// @brief check if player vs algorythm mode is enabled
    /// @return boolean value wheter vs mode is enabled or not
    bool isVsModeEnabled();

    /// @brief Set new speed of algorythm
    void setSpeed(int value);

    /// @brief Get speed of algorythm
    /// @return Algorythm speed
    int getSpeed();

private:
    std::shared_ptr<Algorythm> selectedAlgorythm;
    Maze* currentMaze;
    Mouse* mouse;
    Mouse* userMouse;
    std::string mazeFile;
    bool isVsMode;
    int speed;
};

#endif // GAMECONTROLLER_H
