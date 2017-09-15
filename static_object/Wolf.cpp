//
// Created by Даниил on 03.09.2017.
//


#include "Wolf.hpp"


void Wolf::reaction(Agent *agent) {
    if ( ! is_in_range(agent->get_position()))
        return;

    agent->set_score(0);
}


bool Wolf::is_in_range(std::pair<int, int> position) {
    unsigned distance = static_cast<unsigned int>(
            (this->position.first - position.first) * (this->position.first - position.first) +
            (this->position.second - position.second) * (this->position.second - position.second));
    return distance <= 1;
}
