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
    static QPen _nonVisitedPen;
    static QPen _visitedPen;
    _nonVisitedPen.setColor(Qt::red);
    _visitedPen.setColor(Qt::blue);

    ui->setupUi(this);
    ui->comboBox->addItems({"force", "bellman", "propagation"});
    controller = std::shared_ptr<GameController> (new GameController);
    controller.get()->
    // Start the graphics loop
    double secondsPerFrame = 1.0 / 60;
    QTimer* mapTimer = new QTimer();
    connect(
                mapTimer, &QTimer::timeout,
                this, [=](){
        // Hack to prevent file dialog from locking up...
        static double then = SimUtilities::getHighResTimestamp();
        double now = SimUtilities::getHighResTimestamp();
        if (now - then < secondsPerFrame) {
            return;
        }
        m_map->update();
        then = now;
    }
    );
    mapTimer->start(secondsPerFrame * 1000);




    QTimer* mapTimer = new QTimer();
    connect(
        mapTimer, &QTimer::timeout,
        this, [=](){
        static double then = getTimeStamp();
        double now = getTimeStamp();
        if (now - then < secondsPerFrame) {
            return;
        }
        printScene();
        then = now;
    }
    );
}

double Micromouse::getTimeStamp() {
    return QDateTime::currentDateTime().toMSecsSinceEpoch() / 1000.0;
}

void Micromouse::printScene() {
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

    controller->getAlgorythm();

}

Micromouse::~Micromouse()
{
    delete ui;
}

