//
// Created by Даниил on 09.09.2017.
//

#ifndef REDRIDINGHOOD_BACKTRACKHOOD_HPP
#define REDRIDINGHOOD_BACKTRACKHOOD_HPP


#include <map>
#include <stack>
#include <memory>
#include "Agent.hpp"


class BacktrackHood : public Agent {
public:
    BacktrackHood();

    BacktrackHood(std::pair<int, int> position, int score = 0);

    int find_granny(std::unique_ptr<Map> map) override;

private:
    std::vector<std::pair<int, int>> get_possible_ways(std::unique_ptr<Map> &map);

    void add_if_possible(std::unique_ptr<Map> &map, std::vector<std::pair<int, int>> &ways, std::pair<int, int> position);

    std::pair<int, int> choose_minimal_distance(std::vector<std::pair<int, int>> &ways);

    int distance(std::pair<int, int> source_position, std::pair<int, int> target_position);

    void set_new_aim(std::pair<int, int> aim);

    void reset_search();

    std::map<std::pair<int, int>, bool> checked; // TODO: Refactor to use set instead of map

    std::stack<std::pair<int, int>> path;

    std::pair<int, int> curr_aim;

    bool impossible = false;
};


#endif //REDRIDINGHOOD_BACKTRACKHOOD_HPP
