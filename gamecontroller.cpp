#include "gamecontroller.h"

GameController::GameController()
{   
    this->selectedAlgorythm = ALGORYTHM::BRUTE_FORCE;
    this->mazeFile = "example5.txt";
    this->currentMaze = Maze::fromFile(mazeFile);
    this->mouse = Mouse::startPosition();
}

void GameController::resetGame() {
    this->mouse = Mouse::startPosition();
    this->currentMaze = Maze::fromFile(mazeFile);
}

void GameController::setAlgorythm(ALGORYTHM algorythm) {
    switch (algorythm) {
    case ALGORYTHM::RIGHT_FIRST:
        this->selectedAlgorythm = new RightAlgorythm();
        break;
    case ALGORYTHM::LEFT_FIRST:
        this->selectedAlgorythm = new LeftAlgorythm();
        break;
    case ALGORYTHM::RANDOM:
        this->selectedAlgorythm = new RandomAlgorythm();
        break;
    case ALGORYTHM::FLOOD_FILL:
        this->selectedAlgorythm = new FloodFillAlgorythm();
        break;
    }
}

Algorythm GameController::getAlgorythm() {
    return this->selectedAlgorythm;
}

std::string GameController::getMazeFile() {
    return this->mazeFile;
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

int GameController::mouseX() {
    return this->mouse->getX();
}

int GameController::mouseY() {
    return this->mouse->getY();
}


