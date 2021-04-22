#include "gamecontroller.h"

GameController::GameController()
{   
    this->selectedAlgorythm.reset(new LeftAlgorythm());
    this->mazeFile = "example4.txt";
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
        this->selectedAlgorythm.reset(new RightAlgorythm());
        break;
    case ALGORYTHM::LEFT_FIRST:
        this->selectedAlgorythm.reset(new LeftAlgorythm());
        break;
    case ALGORYTHM::RANDOM:
        this->selectedAlgorythm.reset(new RandomAlgorythm());
        break;
    case ALGORYTHM::FLOOD_FILL:
        this->selectedAlgorythm.reset(new FloodFillAlgorythm());
        break;
    }
}

bool GameController::isReachEnd() {
    //TODO: Napisać sprawdzanie czy mysz znajduje się w środku
    return this->currentMaze->isInCenter(mouse->getX(), mouse->getY());
}

Algorythm GameController::getAlgorythm() {
    return *this->selectedAlgorythm;
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

bool GameController::moveMouse() {
    this->selectedAlgorythm.get()->makeMove(*this->currentMaze, *this->mouse);
    return isReachEnd();
}



