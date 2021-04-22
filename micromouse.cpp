#include "micromouse.h"
#include "ui_micromouse.h"

const int tileSize = 25;

Micromouse::Micromouse(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Micromouse)
    , scene(new QGraphicsScene(this))
    , mouseScene(new QGraphicsScene(this))
{
    ui->setupUi(this);
    ui->algorythmComboBox->addItems({"left-side", "right-side", "random"});
    controller.reset(new GameController());

    // set scenes
    ui->userGraphicsView->setScene(mouseScene);
    ui->graphicsView->setScene(scene);
    printScene();

    // Set buttons actions
    connect(ui->startButton, &QPushButton::released, this, &Micromouse::startTimer);
    connect(ui->restartButton, &QPushButton::released, this, &Micromouse::restart);
    connect(ui->versusButton, &QPushButton::released, this, &Micromouse::compVsPlayer);
    connect(ui->randomMazeButton, &QPushButton::released, this, &Micromouse::randomMaze);


    // Set the graphics loop
    double secondsPerFrame = 1.0 / 60;
    mapTimer.reset(new QTimer());
    connect(
        mapTimer.get(), &QTimer::timeout,
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
}

void Micromouse::startTimer() {
    mapTimer.get()->start(300);
}

void Micromouse::compVsPlayer() {

}

void Micromouse::restart() {
    controller.get()->resetGame();
    mapTimer.get()->stop();
    printScene();
}

void Micromouse::randomMaze() {

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

