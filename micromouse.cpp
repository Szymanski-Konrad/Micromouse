#include "micromouse.h"
#include "ui_micromouse.h"

const int tileSize = 25;
const int mouseHeight = 20;
const int mouseWidth = 15;

Micromouse::Micromouse(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Micromouse)
    , scene(new QGraphicsScene(this))
    , mouseScene(new QGraphicsScene(this))
{
    static QPen _nonVisitedPen;
    static QPen _visitedPen;
    _nonVisitedPen.setColor(Qt::red);
    _visitedPen.setColor(Qt::blue);

    ui->setupUi(this);
    ui->comboBox->addItems({"force", "bellman", "propagation"});
    controller.reset(new GameController());

    // set scenes
    ui->userGraphicsView->setScene(mouseScene);
    ui->graphicsView->setScene(scene);
    printScene();

    // Start the graphics loop
    double secondsPerFrame = 1.0 / 60;
    QTimer* mapTimer = new QTimer();
    connect(
        mapTimer, &QTimer::timeout,
        this, [=](){
        static double then = getTimeStamp();
        double now = getTimeStamp();
        if (now - then < secondsPerFrame) {
            return;
        }
        moveMouse();
        printScene();
        then = now;
    }
    );
    mapTimer->start(100);
}

double Micromouse::getTimeStamp() {
    return QDateTime::currentDateTime().toMSecsSinceEpoch() / 1000.0;
}

void Micromouse::printScene() {
    scene->clear();
    mouseScene->clear();
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
    scene->addPolygon(generateMousePolygon());

    for(auto const& tile: controller->getMouse()->getVisitedTiles()) {
        for (auto wall: tile.wallsCoords()) {
            lineItem = new QGraphicsLineItem(
                        wall.getX1()*tileSize,
                        wall.getY1()*tileSize,
                        wall.getX2()*tileSize,
                        wall.getY2()*tileSize);
            mouseScene->addItem(lineItem);
        }
    }

    mouseScene->addPolygon(generateMousePolygon());
}

void Micromouse::moveMouse() {
    if (controller->moveMouse()) {
        QMessageBox *winBox = new QMessageBox;
        winBox->setWindowTitle("Congratulation!!");
        winBox->setIcon(QMessageBox::Information);
        winBox->setText("Mouse reach center of maze");
        winBox->exec();
        controller->resetGame();
    };
}

QPolygonF Micromouse::generateMousePolygon() {
    QPolygonF triangle;
    Mouse* mouse = controller->getMouse();
    int x = mouse->getX();
    int y = mouse->getY();

    switch (mouse->getDirection()) {
    case DIRECTION::NORTH:
        triangle.append(QPointF(x * tileSize,(y+1) * tileSize));
        triangle.append(QPointF((x+1) * tileSize, (y+1) * tileSize));
        triangle.append(QPointF(x * tileSize + tileSize / 2, y * tileSize));
        triangle.append(QPointF(x * tileSize,(y+1) * tileSize));
        break;
    case DIRECTION::WEST:
        triangle.append(QPointF((x+1) * tileSize, y * tileSize));
        triangle.append(QPointF((x+1) * tileSize, (y+1) * tileSize));
        triangle.append(QPointF(x * tileSize, y * tileSize + tileSize / 2));
        triangle.append(QPointF((x+1) * tileSize, y * tileSize));
        break;
    case DIRECTION::EAST:
        triangle.append(QPointF(x * tileSize,y * tileSize));
        triangle.append(QPointF(x * tileSize, (y+1) * tileSize));
        triangle.append(QPointF((x+1) * tileSize, y * tileSize + tileSize / 2));
        triangle.append(QPointF(x * tileSize,y * tileSize));
        break;
    case DIRECTION::SOUTH:
        triangle.append(QPointF(x * tileSize, y * tileSize));
        triangle.append(QPointF((x+1) * tileSize, y * tileSize));
        triangle.append(QPointF(x * tileSize + tileSize / 2, (y+1) * tileSize));
        triangle.append(QPointF(x * tileSize, y * tileSize));
        break;
    }

    return triangle;
}

Micromouse::~Micromouse()
{
    delete ui;
}

