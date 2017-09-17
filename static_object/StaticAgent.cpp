//
// Created by Даниил on 31.08.2017.
//

#include "StaticAgent.hpp"


StaticObject::StaticObject() {
    position = std::pair<int, int>(0, 0);
}


StaticObject::StaticObject(std::pair<int, int> position) {
    this->position = position;
}


void StaticObject::set_position(std::pair<int, int> new_pos) {
    position = new_pos;
}


void StaticObject::set_x(int x) {
    position.first = x;
}


void StaticObject::set_y(int y) {
    position.second = y;
}


std::pair<int, int> StaticObject::get_position() {
    return position;
}
