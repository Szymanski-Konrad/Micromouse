#include "micromouse.h"
#include "ui_micromouse.h"

const int tileSize = 25;

Micromouse::Micromouse(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Micromouse)
    , scene(new QGraphicsScene(this))
{
    QPen _nonVisitedPen;
    QPen _visitedPen;
    _nonVisitedPen.setColor(Qt::red);
    _visitedPen.setColor(Qt::blue);

    ui->setupUi(this);
    ui->comboBox->addItems({"1", "2", "3"});

    Maze* loadedMaze = Maze::fromFile("example5.txt");

    QGraphicsLineItem *lineItem;
    for(auto const& tile: loadedMaze->getTiles()) {
        for (auto wall: tile.wallsCoords()) {
            lineItem = new QGraphicsLineItem(
                        wall.getX1()*tileSize,
                        wall.getY1()*tileSize,
                        wall.getX2()*tileSize,
                        wall.getY2()*tileSize);
            scene->addItem(lineItem);
        }
    }

    ui->graphicsView->setScene(scene);
    qDebug() << scene->height();
    qDebug() << scene->width();
}

Micromouse::~Micromouse()
{
    delete ui;
}

