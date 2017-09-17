//
// Created by Даниил on 31.08.2017.
//

#include <iostream>
#include "Map.hpp"
#include "../agent/Agent.hpp"
#include "../static_object/StaticAgent.hpp"
#include "../static_object/Bear.hpp"
#include "../static_object/Granny.hpp"
#include "../static_object/Wolf.hpp"
#include "../static_object/Woodcutter.hpp"


Map::Map(unsigned width, unsigned height, unsigned seed) : width(width), height(height), distribution(0, 1) {
    random_engine.seed(seed);
}


Map::~Map() {
    for (int i = 0; i < 4; i++)
        if (objects[i] != nullptr)
            delete (objects[i]);
}


bool Map::cell_exists(std::pair<int, int> cell) const {
    return (0 <= cell.first && cell.first < width && 0 <= cell.second && cell.second < height);
}


std::pair<int, int> Map::north(std::pair<int, int> cell) const {
    cell.second -= 1;
    return cell;
}


std::pair<int, int> Map::east(std::pair<int, int> cell) const {
    cell.first += 1;
    return cell;
}


std::pair<int, int> Map::south(std::pair<int, int> cell) const {
    cell.second += 1;
    return cell;
}


std::pair<int, int> Map::west(std::pair<int, int> cell) const {
    cell.first -= 1;
    return cell;
}


bool Map::is_in_wolf_range(std::pair<int, int> position) const {
    return wolf->is_in_range(position);
}


bool Map::is_wolf(std::pair<int, int> position) const {
    return (position == wolf->get_position());
}


bool Map::is_in_bear_range(std::pair<int, int> position) const {
    return bear->is_in_range(position);
}


bool Map::is_bear(std::pair<int, int> position) const {
    return (position == bear->get_position());
}


bool Map::is_woodcutter(std::pair<int, int> position) const {
    return (position == woodcutter->get_position());
}


void Map::get_possible_woodcutter_positions(std::pair<int, int> &pos_1, std::pair<int, int> &pos_2) {
    if (distribution(random_engine) % 2 == 0) {
        pos_1 = woodcutter->get_position();
        pos_2 = alt_woodcutter_position;
    }
    else {
        pos_1 = alt_woodcutter_position;
        pos_2 = woodcutter->get_position();
    }
}


bool Map::is_granny(std::pair<int, int> position) const {
    return (position == granny->get_position());
}


std::pair<int, int> Map::get_granny_position() const {
    return granny->get_position();
}


void Map::go_to(Agent *agent, std::pair<int, int> position) const {
    if (cell_exists(position)) {
        agent->set_position(position);

//        std::cout << "Agent RRH goes to " << position.first << ' ' << position.second << '\n';

        for (int i = 0; i < 4; i++)
            objects[i]->reaction(agent);
    }
}


void Map::draw () const {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            std::pair<int, int> curr_pos (x, y);

            if (is_granny (curr_pos))
                std::cout << 'G';
            else if (is_bear (curr_pos))
                std::cout << 'B';
            else if (is_wolf (curr_pos))
                std::cout << 'W';
            else if (is_woodcutter (curr_pos))
                std::cout << 'C';
            else if (curr_pos == alt_woodcutter_position)
                std::cout << 'F';
            else if (is_in_wolf_range (curr_pos))
                std::cout << 'X';
            else if (is_in_bear_range (curr_pos))
                std::cout << '^';
            else
                std::cout << '_';
        }
        std::cout << '\n';
    }
}


void Map::optimize_objects() {
    objects[0] = bear;
    objects[1] = granny;
    objects[2] = wolf;
    objects[3] = woodcutter;
}
