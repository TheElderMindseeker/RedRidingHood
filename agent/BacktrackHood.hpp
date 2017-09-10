//
// Created by Даниил on 09.09.2017.
//

#ifndef REDRIDINGHOOD_BACKTRACKHOOD_HPP
#define REDRIDINGHOOD_BACKTRACKHOOD_HPP


#include <stack>
#include <memory>
#include <set>
#include "Agent.hpp"


class BacktrackHood : public Agent {
public:
    BacktrackHood();

    BacktrackHood(std::pair<int, int> position, int score = 0);

    int find_granny(std::unique_ptr<Map> map) override;

private:
    /**
     * @brief Get possible ways that are available from current position of agent
     *
     * @param map Map to get ways from
     * @return list of positions which are available
     */
    std::vector<std::pair<int, int>> get_possible_ways(std::unique_ptr<Map> &map);

    void add_if_possible(std::unique_ptr<Map> &map, std::vector<std::pair<int, int>> &ways, std::pair<int, int> position);

    std::pair<int, int> choose_minimal_distance(std::unique_ptr<Map> &map, std::vector<std::pair<int, int>> &ways);

    int distance(std::pair<int, int> source_position, std::pair<int, int> target_position);

    /**
     * @brief Check current score, aim and update them if necessary
     *
     * @param map Map currently being solved
     */
    void update_inner_condition(std::unique_ptr<Map> &map);

    /**
     * Checks for woodcutter in current position
     *
     * @param map Map currently being explored
     */
    void check_for_woodcutter(std::unique_ptr<Map> &map);

    void set_new_aim(std::pair<int, int> aim);

    /**
     * @brief Set path, checked, task_completed and not_found variables to their default values (empty and false)
     */
    void reset_search(); // TODO: Make reset_search update the aim of agent

    std::set<std::pair<int, int>> checked;

    std::stack<std::pair<int, int>> path;

    std::pair<int, int> curr_aim;

    std::pair<int, int> real_woodcutter;

    bool woodcutter_known = false;

    bool not_found = false;

    bool fearless = false;

    bool impossible = false;
};


#endif //REDRIDINGHOOD_BACKTRACKHOOD_HPP
