//
// Created by Даниил on 31.08.2017.
//

#include "StaticObject.hpp"


void StaticObject::set_position(int x, int y) {
    x_pos = x;
    y_pos = y;
}


void StaticObject::set_x(int x) {
    x_pos = x;
}


void StaticObject::set_y(int y) {
    y_pos = y;
}


void StaticObject::get_position(int &x, int &y) {
    x = x_pos;
    y = y_pos;
}


int StaticObject::get_x() {
    return x_pos;
}


int StaticObject::get_y() {
    return y_pos;
}