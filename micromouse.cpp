#include "micromouse.h"
#include "ui_micromouse.h"

const int tileSize = 25;
const int mouseHeight = 20;
const int mouseWidth = 15;

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
    ui->comboBox->addItems({"force", "bellman", "propagation"});

    std::shared_ptr<GameController> controller(new GameController());

    QGraphicsLineItem *lineItem;
    for(auto const& tile: controller->getMaze()->getTiles()) {
        for (auto wall: tile.wallsCoords()) {
            lineItem = new QGraphicsLineItem(
                        wall.getX1()*tileSize,
                        wall.getY1()*tileSize,
                        wall.getX2()*tileSize,
                        wall.getY2()*tileSize);
            scene->addItem(lineItem);
        }
    }

    QGraphicsItem* mouseItem = new QGraphicsRectItem(controller->mouseX(), controller->mouseY(), mouseHeight, mouseWidth);
    scene->addItem(mouseItem);
    ui->graphicsView->setScene(scene);
    ui->userGraphicsView->setScene(scene);
    qDebug() << scene->height();
    qDebug() << scene->width();


}

Micromouse::~Micromouse()
{
    delete ui;
}

