#ifndef MAZE_H
#define MAZE_H


#include <string>
#include <tile.h>
#include <fstream>
#include <sstream>

#include<QDebug>



template<typename T>
class Interval
{
public:
    Interval(T lo, T hi) : low(lo), high(hi) {}
    bool contains(T value) const { return low <= value && value < high; }
private:
    T low;
    T high;
};
template<typename T>
Interval<T> interval(T lo, T hi) { return Interval<T>(lo, hi); }

const int lowMiddle = 7;
const int hightMiddle = 8;
const Interval<int> inRange = Interval<int>(lowMiddle, hightMiddle);

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
    bool isInCenter(int x, int y);

private:
    std::vector<Tile> tiles;

};

#endif // MAZE_H
