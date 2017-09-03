//
// Created by Даниил on 03.09.2017.
//

#include "Granny.hpp"


void Granny::reaction(Agent *agent) {
    if (is_in_range(agent->get_position()) && agent->get_score() == 6)
        agent->set_task_completed();
}


bool Granny::is_in_range(std::pair<int, int> position) {
    return (this->position.first == position.first) && (this->position.second == position.second);
}
