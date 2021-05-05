#ifndef MAZE_H
#define MAZE_H


#include <string>
#include <tile.h>
#include <fstream>
#include <sstream>

#include<QDebug>

/**
*  @file maze.h
*  @brief Field with walls, where mouse can move around
*/

template<typename T>
class Interval
{
public:
    Interval(T lo, T hi) : low(lo), high(hi) {}

    /// @brief Check if value is in range
    bool contains(T value) const { return low <= value && value < high; }
private:
    T low;
    T high;
};

/// @brief Interval template to get maze middle tiles
/// @tparam T interval start or end numeric type as int, float, double
/// @param lo lowest value in interval
/// @param hi highest value in interval
/// @return values in range <lo, hi>
template<typename T>
Interval<T> interval(T lo, T hi) { return Interval<T>(lo, hi); }

const int lowMiddle = 7;
const int hightMiddle = 8;
const Interval<int> inRange = Interval<int>(lowMiddle, hightMiddle);

class Maze
{
public:
    /// @brief Default constructor
    Maze();

    /// @brief Maze class constructor
    /// @param tiles maze tiles
    Maze(std::vector<std::vector<int>> tiles);

    /// @brief Create maze from file
    /// @param path Path to file
    /// @return New maze object
    static Maze* fromFile(const std::string path);

    /// @brief get maze width
    /// @return maze width
    int getWidth() const;

    /// @brief get maze height
    /// @return maze height
    int getHeight() const;

    /// @brief get maze tile on specific coords
    /// @param x X coordination
    /// @param y Y coordination
    /// @return tile on given coords
    std::shared_ptr<Tile> getTile(int x, int y) const;

    /// @brief get all maze tiles
    /// @return all maze tiles
    std::vector<std::shared_ptr<Tile>> getTiles() const;

    /// @brief check if position is in center
    /// @param x X position
    /// @param y Y position
    /// @return boolean value whether is in center or not
    bool isInCenter(int x, int y);

private:
    std::vector<std::shared_ptr<Tile>> tiles;

};

#endif // MAZE_H
