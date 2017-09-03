//
// Created by Даниил on 03.09.2017.
//

#include "Woodcutter.hpp"


void Woodcutter::reaction(Agent *agent) {
    if (is_in_range(agent->get_position()))
        agent->set_score(6);
}


bool Woodcutter::is_in_range(std::pair<int, int> position) {
    return (this->position.first == position.first) && (this->position.second == position.second);
}
