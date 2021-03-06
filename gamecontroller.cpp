#include "gamecontroller.h"

GameController::GameController()
{   
    this->selectedAlgorythm.reset(new LeftAlgorythm());
    this->mazeFile = "example2.txt";
    this->currentMaze = Maze::fromFile(mazeFile);
    std::shared_ptr<Tile> tile = this->currentMaze->getTile(0,0);
    this->mouse = Mouse::startPosition(tile);
    this->userMouse = Mouse::startPosition(tile);
    this->isVsMode = false;
    this->speed = 50;
}

void GameController::resetGame() {
    this->currentMaze = Maze::fromFile(mazeFile);
    std::shared_ptr<Tile> tile = this->currentMaze->getTile(0,0);
    this->mouse = Mouse::startPosition(tile);
    this->userMouse = Mouse::startPosition(tile);
}

void GameController::setAlgorythm(ALGORYTHM algorythm) {
    switch (algorythm) {
    case ALGORYTHM::RIGHT_FIRST:
        this->selectedAlgorythm.reset(new RightAlgorythm());
        break;
    case ALGORYTHM::LEFT_FIRST:
        this->selectedAlgorythm.reset(new LeftAlgorythm());
        break;
    case ALGORYTHM::RANDOM:
        this->selectedAlgorythm.reset(new RandomAlgorythm());
        break;
    }
}

bool GameController::isReachEnd(bool isUser = false) {
    if (isUser)
        return this->currentMaze->isInCenter(userMouse->getX(), userMouse->getY());
    return this->currentMaze->isInCenter(mouse->getX(), mouse->getY());
}

bool GameController::isVsModeEnabled() {
    return this->isVsMode;
}

void GameController::enableVsMode() {
    this->isVsMode = true;
}

void GameController::disableVsMode() {
    this->isVsMode = false;
}

Algorythm GameController::getAlgorythm() {
    return *this->selectedAlgorythm;
}

void GameController::setMazeFile(std::string mazeFile) {
    this->mazeFile = mazeFile;
}

Maze* GameController::getMaze() {
    return this->currentMaze;
}

Mouse* GameController::getMouse() {
    return this->mouse;
}

Mouse* GameController::getUserMouse() {
    return this->userMouse;
}

int GameController::mouseX() {
    return this->mouse->getX();
}

int GameController::mouseY() {
    return this->mouse->getY();
}

bool GameController::moveMouse() {
    this->selectedAlgorythm.get()->makeMove(*this->currentMaze, *this->mouse);
    return isReachEnd();
}

bool GameController::moveUserMouse(DIRECTION direction) {
    if (userMouse->getDirection() != direction)
        userMouse->rotateToDirection(direction);
    if (this->userMouse->canMove()) {
        userMouse->moveForward();
        userMouse->visitTile(this->currentMaze->getTile(userMouse->getX(), userMouse->getY()));
        return isReachEnd(true);
    }
    return false;
}

void GameController::setSpeed(int value) {
    this->speed = value;
}

int GameController::getSpeed() {
    return this->speed;
}
