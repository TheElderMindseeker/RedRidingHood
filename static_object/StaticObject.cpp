//
// Created by Даниил on 31.08.2017.
//

#include "StaticObject.hpp"


StaticObject::StaticObject() {
    position = std::pair<int, int>(0, 0);
}


StaticObject::StaticObject(std::pair<int, int> position) {
    this->position = position;
}


void StaticObject::set_position(std::pair<int, int> new_pos) {
    position = new_pos;
}


void StaticObject::set_position(int x, int y) {
    position = std::pair<int, int>(x, y);
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


void StaticObject::get_position(int &x, int &y) {
    x = position.first;
    y = position.second;
}


int StaticObject::get_x() {
    return position.first;
}


int StaticObject::get_y() {
    return position.second;
}
