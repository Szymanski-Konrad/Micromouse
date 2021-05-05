#ifndef MICROMOUSE_H
#define MICROMOUSE_H

#include <QMainWindow>
#include <QGraphicsRectItem>
#include <QDebug>
#include <gamecontroller.h>

#include <QTimer>
#include <QDateTime>
#include <QMessageBox>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Micromouse; }
class QGraphicsScene;
QT_END_NAMESPACE

/*! @mainpage Micromouse
 *  This project is an implementation of worldwide micromouse competition. \n
 *  Main idea is to compete in time challenge. Every participant should build roboty, that
 *  will pass unknown maze in shortest time. Every robot rely only on theirs sensors to localize walls and find \n
 *  road to middle of maze.
 *
 *  @file micromouse.h
 *  @brief Responsible for graphical part of application
 *
 *  @details This class is bridge between User and backend. Enable user interaction and showing backend data in window.

 */



class Micromouse : public QMainWindow
{
    Q_OBJECT

public:
    /// Constructor
    Micromouse(QWidget *parent = nullptr);

    /// Class destructor
    ~Micromouse();

    /// UI variable
    Ui::Micromouse *ui;

    /// Representing user maze view
    QGraphicsScene *scene;

    /// Representing mouse maze view
    QGraphicsScene *mouseScene;

    /// Controller for whole game actions, communicate with user
    std::shared_ptr<GameController> controller;

    /// @brief React on key pressed
    /// @param event Pressed key event
    void keyPressEvent(QKeyEvent *event);

    /// @brief Print wall on direction
    /// @param direction Direction where wall should be placed
    /// @param tile Current printing tile
    void printWall(DIRECTION direction, Tile tile);

    /// @brief Print scene of loaded maze
    /// @details Shows current state of mouse in maze, when app is in algorythm mode
    void printScene();

    /// @brief Print loaded maze with user mouse
    /// @details Show current state of user actions
    void printUserScene();

    /// @brief Print loaded maze with algorythm mouse
    /// @details Show current state of data comes from mouse sensors
    void printCompScene();

    /// @brief Move mouse in possible direction
    /// @details Controller send move action to mouse
    void moveMouse();

    /// @brief Starting loop of algorythm mouse moving
    void startTimer();

    /// @brief Change play mode to compVsPlayer
    void compVsPlayer();

    /// @brief Change play mode to normal mode
    /// @details Normal mode is when algorythm is trying to reach center of maze. On screen is showing mouse view and whole maze view.
    void normalMode();

    /// @brief Stop timer and move mouse to start point
    void restart();

    /// @brief Show info that mouse reach middle of maze
    /// @param isUser user or algorythm mouse
    /// @details Show appropriate message depending on the winner mouse
    void showWinner(bool isUser);

    /// @brief load random maze
    void randomMaze();

    /// @brief show current position of mouse
    /// @param isUser user or algorythm mouse
    /// @return mouse polygon
    QPolygonF generateMousePolygon(bool isUser);

    /// @brief current timestamp
    /// @details helper for loop function
    /// @return timestamp
    double getTimeStamp();

    /// @brief control game loop
    std::unique_ptr<QTimer> mapTimer;

    /// @brief flag to set game mode
    bool isVsMode;

public slots:
    /// Function for Combobox
    void algorythmChanged(int index);
};
#endif // MICROMOUSE_H
