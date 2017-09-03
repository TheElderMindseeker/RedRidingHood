//
// Created by Даниил on 03.09.2017.
//

#include "Bear.hpp"


void Bear::reaction(Agent *agent) {
    if ( ! is_in_range(agent->get_position()))
        return;

    if (agent->get_score() >= 2)
        agent->set_score(agent->get_score() - 2);
    else
        agent->set_score(0);
}


bool Bear::is_in_range(std::pair<int, int> position) {
    unsigned distance = static_cast<unsigned int>(
            (this->position.first - position.first) * (this->position.first - position.first) +
                (this->position.second - position.second) * (this->position.second - position.second));
    return distance <= 2;
}
