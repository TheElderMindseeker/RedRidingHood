//
// Created by Даниил on 31.08.2017.
//

#include "Map.hpp"


Map::Map(unsigned width, unsigned height) {
    this->width = width;
    this->height = height;
}


bool Map::cell_exists(std::pair<int, int> cell) {
    return (0 <= cell.first && cell.first < width && 0 <= cell.second && cell.second < height);
}


std::pair<int, int> Map::north(std::pair<int, int> cell) {
    cell.second -= 1;
    return cell;
}


std::pair<int, int> Map::east(std::pair<int, int> cell) {
    cell.first += 1;
    return cell;
}


std::pair<int, int> Map::south(std::pair<int, int> cell) {
    cell.second += 1;
    return cell;
}


std::pair<int, int> Map::west(std::pair<int, int> cell) {
    cell.first -= 1;
    return cell;
}
