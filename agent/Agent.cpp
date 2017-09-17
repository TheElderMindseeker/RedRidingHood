//
// Created by Даниил on 31.08.2017.
//

#include "Agent.hpp"


Agent::Agent() : score(0), position(0, 0), steps(0) {}


Agent::Agent(std::pair<int, int> position, int score) : score(score), position(position), steps(0) {}


std::pair<int, int> Agent::get_position() {
    return position;
}


void Agent::set_position(std::pair<int, int> new_position) {
    position = new_position;
}


int Agent::get_score() {
    return score;
}


void Agent::set_score(int new_score) {
    score = new_score;
}


unsigned Agent::get_steps() {
    return steps;
}


void Agent::reset_steps() {
    steps = 0;
}


void Agent::set_task_completed() {
    task_completed = true;
}
