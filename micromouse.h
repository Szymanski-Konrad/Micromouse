#ifndef MICROMOUSE_H
#define MICROMOUSE_H

#include <QMainWindow>
#include <QGraphicsRectItem>
#include <QDebug>
#include <maze.h>

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

private:
    Ui::Micromouse *ui;
    QGraphicsScene *scene;
};
#endif // MICROMOUSE_H
