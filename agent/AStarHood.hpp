//
// Created by Даниил on 09.09.2017.
//

#ifndef REDRIDINGHOOD_ASTARHOOD_HPP
#define REDRIDINGHOOD_ASTARHOOD_HPP


#include <set>
#include <map>
#include "Agent.hpp"


class AStarHood : public Agent {
public:
    /**
     * @brief Standard AStarHood constructor that initializes agent with (0, 0) position and zero score
     */
    AStarHood();

    /**
     * @brief Constructs AStarHood agent with given coordinates and score
     *
     * @param position Agent initial position
     * @param score Agent initial score
     */
    AStarHood(std::pair<int, int> position, int score = 0);

    int find_granny(std::unique_ptr<Map> &map) override;

    bool operator () (std::pair<int, int> pos_1, std::pair<int, int> pos_2);

    /**
     * @brief Resets the inner state of agent as if it never solved any map
     */
    void reset();

private:
    /**
     * @brief Checks the neighbouring cells for the possibility of movement to them
     *
     * @param map Map on which agent is acting
     *
     * @return Vector of possible positions
     */
    void get_possible_ways (std::unique_ptr<Map> &map, std::vector<std::pair<int, int>> &ways);

    void add_if_possible (std::unique_ptr<Map> &map, std::vector<std::pair<int, int>> &ways, std::pair<int, int> position);

    /**
     * @brief This function-element calculates the estimated distance from position to aim
     *
     * @param position Initial position
     * @param aim Destination position
     *
     * @return Estimated distance from initial position to destination
     */
    int heuristic (std::pair<int, int> position, std::pair<int, int> aim);

    std::set<std::pair<int, int>> closed_list;

    std::set<std::pair<int, int>> open_list;

    std::map<std::pair<int, int>, int> g_score;

    std::map<std::pair<int, int>, int> h_score;

    std::pair<int, int> curr_aim;

    static const int BEAR_COST = 1000;
};


#endif //REDRIDINGHOOD_ASTARHOOD_HPP
