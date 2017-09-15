//
// Created by Даниил on 09.09.2017.
//

#ifndef REDRIDINGHOOD_BACKTRACKHOOD_HPP
#define REDRIDINGHOOD_BACKTRACKHOOD_HPP


#include <set>
#include <stack>
#include <memory>
#include "Agent.hpp"


class BacktrackHood : public Agent {
public:
    /**
     * @brief Standard BacktrackHood constructor that initializes agent with (0, 0) position and zero score
     */
    BacktrackHood();

    /**
     * @brief Constructs BacktrackHood agent with given coordinates and score
     *
     * @param position Agent initial position
     * @param score Agent initial score
     */
    BacktrackHood(std::pair<int, int> position, int score = 0);

    /**
     * @brief Function that tries to solve the given map leading agent to granny
     *
     * @param map Given map
     * @return One of the search results (granny found, granny unreachable, or fail if the agent dies)
     */
    int find_granny(std::unique_ptr<Map> &map) override;

    /**
     * @brief Resets the inner state of agent as if it never solved any map
     */
    void reset();

private:
    /**
     * @brief Checks the neighbouring cells for the possibility of movement to them
     *
     * @param map Map on which agent is acting
     * @return Vector of possible positions
     */
    std::vector<std::pair<int, int>> get_possible_ways(std::unique_ptr<Map> &map);

    void add_if_possible(std::unique_ptr<Map> &map, std::vector<std::pair<int, int>> &ways, std::pair<int, int> position);

    /*std::pair<int, int> choose_minimal_distance(std::vector<std::pair<int, int>> &ways);

    int distance(std::pair<int, int> source_position, std::pair<int, int> target_position);

    void set_new_aim(std::pair<int, int> aim);

    void reset_search();*/

    std::set<std::pair<int, int>> checked;

    std::stack<std::pair<int, int>> path;

//    std::pair<int, int> curr_aim;

    bool impossible = false;
};


#endif //REDRIDINGHOOD_BACKTRACKHOOD_HPP
