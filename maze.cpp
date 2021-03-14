#include "maze.h"

Maze::Maze() {

}

Maze* Maze::fromFile(const std::string path) {
    if (path.empty()) {
        return nullptr;
    }
    //TODO: Fill it up
    std::ifstream infile(path);

    std::string line;
    std::vector<std::string> lines;
    qDebug()<<infile.is_open();
    for (line; std::getline(infile, line);) {
        qDebug()<<line.c_str();
    }
    infile.close();

    return nullptr;
}

int Maze::getHeight() const {
    return tiles.size();
}

int Maze::getWidth() const {
    return tiles.at(0).size();
}


