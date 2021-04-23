#ifndef MICROMOUSE_H
#define MICROMOUSE_H

#include <QMainWindow>
#include <QGraphicsRectItem>
#include <QDebug>
#include <gamecontroller.h>

#include <QTimer>
#include <QDateTime>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Micromouse; }
class QGraphicsScene;
QT_END_NAMESPACE

class Micromouse : public QMainWindow
{
    Q_OBJECT

public:
    Micromouse(QWidget *parent = nullptr);
    ~Micromouse();

private slots:
    void algorythmChanged(int index);

private:
    Ui::Micromouse *ui;
    QGraphicsScene *scene;
    QGraphicsScene *mouseScene;
    std::shared_ptr<GameController> controller;
    void printWall(DIRECTION direction, Tile tile);
    void printScene();
    void moveMouse();
    void startTimer();
    void compVsPlayer();
    void restart();
    void randomMaze();
    QPolygonF generateMousePolygon();
    double getTimeStamp();
    std::unique_ptr<QTimer> mapTimer;
};
#endif // MICROMOUSE_H
