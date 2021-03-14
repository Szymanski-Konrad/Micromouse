#include "micromouse.h"
#include "ui_micromouse.h"

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

    Maze* loadedMaze = Maze::fromFile("example_maze.txt");

    QGraphicsItem *item = new QGraphicsRectItem(QRectF(300, 300, 100, 100));
    scene->addItem(item);
    QGraphicsLineItem *lineItem = new QGraphicsLineItem(0,0,0,50);
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            lineItem = new QGraphicsLineItem(i*25, j*25, (i+1)*25, j*25);
            scene->addItem(lineItem);
            lineItem = new QGraphicsLineItem(i*25, j*25, i*25, (j+1)*25);
            scene->addItem(lineItem);
        }
    }

    //lineItem->setPen(_visitedPen);
    //scene->addItem(lineItem);
    //lineItem = new QGraphicsLineItem(50,50, 50, 100);
    //lineItem->setPen(_nonVisitedPen);
    //scene->addItem(lineItem);
    //lineItem = new QGraphicsLineItem(50, 100, 100, 100);
    //scene->addItem(lineItem);
    //lineItem = new QGraphicsLineItem(100, 100, 150, 100);
    //scene->addItem(lineItem);
    //lineItem = new QGraphicsLineItem(150, 100, 150, 150);
    //scene->addItem(lineItem);
    //lineItem = new QGraphicsLineItem(150, 150, 200, 150);
    //scene->addItem(lineItem);
    //lineItem = new QGraphicsLineItem(200, 150, 200, 250);
    //scene->addItem(lineItem);
    //lineItem = new QGraphicsLineItem(50, 100, 100, 100);
    //scene->addItem(lineItem);
    //lineItem = new QGraphicsLineItem(50, 100, 100, 100);
    //scene->addItem(lineItem);
    ui->graphicsView->setScene(scene);
    qDebug() << scene->height();
    qDebug() << scene->width();
}

Micromouse::~Micromouse()
{
    delete ui;
}

