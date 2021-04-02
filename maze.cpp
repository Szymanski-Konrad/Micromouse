#include "maze.h"

Maze::Maze() {

}

Maze::Maze(std::vector<std::vector<int>> tiles) {
    for (auto const& tile: tiles) {
        std::unique_ptr<Tile> tmp(new Tile(tile));
        this->tiles.push_back(*tmp);
    }
}

Maze* Maze::fromFile(const std::string path) {
    if (path.empty()) {
        return nullptr;
    }
    //TODO: Fill it up
    std::ifstream infile(path);

    std::string line;
    std::string str;
    std::vector<int> tile;
    std::vector<std::vector<int>> tiles;
    std::stringstream ss;
    while (std::getline(infile, line)) {
        ss.str(line);
        while(ss >> str) {
            tile.push_back(std::stoi(str));
        }
        tiles.push_back(tile);
        tile.clear();
        ss.clear();
    }
    infile.close();

    return new Maze(tiles);
}

int Maze::getHeight() const {
    return std::sqrt(tiles.size());
}

int Maze::getWidth() const {
    return std::sqrt(tiles.size());
}

std::vector<Tile> Maze::getTiles() const {
    return tiles;
}

bool Maze::isInCenter(int x, int y) {
    return inRange.contains(x) && inRange.contains(y);
}


