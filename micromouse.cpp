#include "micromouse.h"
#include "ui_micromouse.h"

const int tileSize = 25;

Micromouse::Micromouse(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Micromouse)
    , scene(new QGraphicsScene(this))
    , mouseScene(new QGraphicsScene(this))
{
    // Delcaration of inital values
    ui->setupUi(this);
    ui->algorythmComboBox->addItems({"left-side", "right-side", "random"});
    controller.reset(new GameController());
    isVsMode = false;
    ui->compLabel->hide();
    ui->playerLabel->hide();

    // Set scenes
    ui->userGraphicsView->setScene(mouseScene);
    ui->graphicsView->setScene(scene);
    printScene();

    // Set buttons actions
    connect(ui->startButton, &QPushButton::released, this, &Micromouse::startTimer);
    connect(ui->restartButton, &QPushButton::released, this, &Micromouse::restart);
    connect(ui->versusButton, &QPushButton::released, this, &Micromouse::compVsPlayer);
    connect(ui->randomMazeButton, &QPushButton::released, this, &Micromouse::randomMaze);
    connect(ui->algorythmComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(algorythmChanged(int)));

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
    ui->playerLabel->show();
    ui->compLabel->show();
    controller.get()->enableVsMode();
    controller.get()->resetGame();
}

void Micromouse::normalMode() {
    ui->playerLabel->hide();
    ui->compLabel->hide();
    controller.get()->disableVsMode();
}

void Micromouse::algorythmChanged(int index) {
    switch (index) {
    case 0:
        controller.get()->setAlgorythm(ALGORYTHM::LEFT_FIRST);
        break;
    case 1:
        controller.get()->setAlgorythm(ALGORYTHM::RIGHT_FIRST);
        break;
    case 2:
        controller.get()->setAlgorythm(ALGORYTHM::RANDOM);
        break;
    }

    restart();
}

void Micromouse::restart() {
    controller.get()->resetGame();
    mapTimer.get()->stop();
    printScene();
}

void Micromouse::randomMaze() {
    int number = rand() % 5;
    std::string fileName = "example" + std::to_string(number + 1) + ".txt";
    controller.get()->setMazeFile(fileName);
    restart();
}

double Micromouse::getTimeStamp() {
    return QDateTime::currentDateTime().toMSecsSinceEpoch() / 1000.0;
}

void Micromouse::printScene() {
    scene->clear();
    mouseScene->clear();
    QGraphicsLineItem *lineItem;
    for(auto const& tile: controller->getMaze()->getTiles()) {
        for (auto wall: tile.get()->wallsCoords()) {
            lineItem = new QGraphicsLineItem(
                        wall.getX1()*tileSize,
                        wall.getY1()*tileSize,
                        wall.getX2()*tileSize,
                        wall.getY2()*tileSize);
            scene->addItem(lineItem);
        }
    }

    scene->addPolygon(generateMousePolygon(controller.get()->isVsModeEnabled()));

    for(auto const& tile: controller->getMouse()->getVisitedTiles()) {
        for (auto wall: tile.get()->wallsCoords()) {
            lineItem = new QGraphicsLineItem(
                        wall.getX1()*tileSize,
                        wall.getY1()*tileSize,
                        wall.getX2()*tileSize,
                        wall.getY2()*tileSize);
            mouseScene->addItem(lineItem);
        }
    }

    mouseScene->addPolygon(generateMousePolygon(false));
}

void Micromouse::keyPressEvent(QKeyEvent *event) {
    if (controller->isVsModeEnabled() && mapTimer.get()->isActive()) {
        switch (event->key()) {
        case Qt::Key_A:
            if (controller.get()->moveUserMouse(DIRECTION::WEST))
                showWinner(true);
            break;
        case Qt::Key_D:
            if (controller.get()->moveUserMouse(DIRECTION::EAST))
                showWinner(true);
            break;
        case Qt::Key_W:
            if (controller.get()->moveUserMouse(DIRECTION::NORTH))
                showWinner(true);
            break;
        case Qt::Key_S:
            if (controller.get()->moveUserMouse(DIRECTION::SOUTH))
                showWinner(true);
            break;
        }
    }

}

void Micromouse::moveMouse() {
    if (controller->moveMouse()) {
        showWinner(false);
    };
}

void Micromouse::showWinner(bool isUser) {
    QMessageBox *winBox = new QMessageBox;
    winBox->setWindowTitle("Congratulation!!");
    winBox->setIcon(QMessageBox::Information);
    if (isUser) {
        winBox->setText("You are faster than algorythm :)");
    }else {
        winBox->setText("Mouse reach center of maze");
    }
    winBox->exec();
    restart();
    delete winBox;
}

QPolygonF Micromouse::generateMousePolygon(bool isUser) {
    QPolygonF triangle;
    Mouse* mouse = isUser ? controller->getUserMouse() : controller->getMouse();
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

