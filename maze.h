#ifndef MAZE_H
#define MAZE_H


#include <string>
#include <tile.h>
#include <fstream>
#include <sstream>

#include<QDebug>

class Maze
{
public:
    Maze();
    Maze(std::vector<std::vector<int>> tiles);

    static Maze* fromFile(const std::string path);
    int getWidth() const;
    int getHeight() const;
    const Tile* getTile(int x, int y) const;
    std::vector<Tile> getTiles() const;
    bool isCenter(std::pair<int, int> location) const;

private:
    std::vector<Tile> tiles;
    static std::vector<std::pair<int,int>> getCenterPosition(int width, int height);
};

#endif // MAZE_H
