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
    ui->algorythmComboBox->addItems({"lewa-strona", "prawa-strona", "random"});
    ui->algorythmComboBox->setCurrentIndex(0);
    ui->mazeComboBox->addItems({"maze1", "maze2", "maze3", "maze4"});
    ui->mazeComboBox->setCurrentIndex(0);

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
    connect(ui->normalModeButton, &QPushButton::released, this, &Micromouse::normalMode);
    connect(ui->algorythmComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(algorythmChanged(int)));
    connect(ui->mazeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(mazeChanged(int)));
    connect(ui->speedSlider, SIGNAL(valueChanged(int)), this, SLOT(speedChanged(int)));

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
        if (!controller.get()->isVsModeEnabled()) {
            printScene();
        }
        else {
            printCompScene();
        }

        then = now;
    }
    );
}

void Micromouse::startTimer() {
    mapTimer.get()->start(controller->getSpeed());
}

void Micromouse::speedChanged(int value) {
    controller->setSpeed(value);
    mapTimer->stop();
    ui->speedLabel->setText(std::to_string(value).c_str());
    startTimer();
}

void Micromouse::compVsPlayer() {
    ui->playerLabel->show();
    ui->compLabel->show();
    ui->userMovesLabel->show();
    ui->userMovesLabel->setText(controller.get()->getUserMouse()->getNumberOfMoves().c_str());
    controller.get()->enableVsMode();
    restart();
}

void Micromouse::normalMode() {
    ui->playerLabel->hide();
    ui->compLabel->hide();
    ui->userMovesLabel->hide();
    controller.get()->disableVsMode();
    restart();
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

void Micromouse::mazeChanged(int index) {
    switch(index) {
    case 0:
        controller.get()->setMazeFile("example2.txt");
        break;
    case 1:
        controller.get()->setMazeFile("example3.txt");
        break;
    case 2:
        controller.get()->setMazeFile("example4.txt");
        break;
    case 3:
        controller.get()->setMazeFile("example5.txt");
        break;
    }

    restart();
}

void Micromouse::restart() {
    controller.get()->resetGame();
    mapTimer.get()->stop();
    printScene();
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
    ui->compMovesLabel->setText(controller->getMouse()->getNumberOfMoves().c_str());
    mouseScene->addPolygon(generateMousePolygon(false));
}

void Micromouse::printUserScene() {
    scene->clear();
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
    ui->userMovesLabel->setText(controller->getUserMouse()->getNumberOfMoves().c_str());
    scene->addPolygon(generateMousePolygon(true));
}

void Micromouse::printCompScene() {
    mouseScene->clear();
    QGraphicsLineItem *lineItem;
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
    ui->compMovesLabel->setText(controller->getMouse()->getNumberOfMoves().c_str());
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
        printUserScene();
    }

}

void Micromouse::moveMouse() {
    if (controller->moveMouse()) {
        showWinner(false);
    };
}

void Micromouse::showWinner(bool isUser) {
    mapTimer->stop();
    QMessageBox *winBox = new QMessageBox;
    winBox->setWindowTitle("Gratulacje!!");
    winBox->setIcon(QMessageBox::Information);
    if (isUser) {
        winBox->setText("Jesteś szybszy niż algorytm :)");
    }else {
        winBox->setText("Mysz dotarła do środka labiryntu.");
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

