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

    /**
     * Solve the task of fetching 6 berries to granny on provided map using A* search algorithm
     *
     * @param map Map of the task
     *
     * @return Success code if the granny was found, failure code otherwise
     */
    int find_granny(std::unique_ptr<Map> &map) override;

    /**
     * @brief Comparison of two position using f() = g() + h() heuristics
     *
     * @note This operator is used to compare positions while searching for current minimal in open list
     *
     * @param pos_1 First position
     * @param pos_2 Second position
     *
     * @return True if first position is less than the second, false otherwise
     */
    bool operator () (std::pair<int, int> pos_1, std::pair<int, int> pos_2);

    /**
     * @brief Resets the inner state of agent as if it never solved any map
     */
    void reset();

private:
    /**
     * @brief Update current search target if needed
     *
     * @param map Map currently being solved
     */
    void update_state (std::unique_ptr<Map> &map);

    /**
     * @brief Try to identify real position of woodcutter
     *
     * @param map Map currently being solved
     */
    void check_woodcutter (std::unique_ptr<Map> &map);

    /**
     * @brief Checks the neighbouring cells for the possibility of movement to them
     *
     * @param map Map on which agent is acting
     *
     * @return Vector of possible positions
     */
    void get_possible_ways (std::unique_ptr<Map> &map, std::vector<std::pair<int, int>> &ways);

    /**
     * Adds position to the possible ways if the position exists and not affected by the wolf
     *
     * @param map Map currently being solved
     * @param ways Vector of possible positions
     * @param position Position to add
     */
    void add_if_possible (std::unique_ptr<Map> &map, std::vector<std::pair<int, int>> &ways, std::pair<int, int> position);

    /**
     * @brief This function-element calculates the estimated distance from position to aim
     *
     * @param position Initial position
     * @param aim Destination position
     *
     * @return Estimated distance from initial position to destination
     */
    int heuristic (std::pair<int, int> position, std::pair<int, int> aim) const;

    /**
     * @brief Resets some parameters of agent
     *
     * @note This function-element is used to change search target
     */
    void partial_reset ();

    std::set<std::pair<int, int>> closed_list;

    std::set<std::pair<int, int>> open_list;

    std::map<std::pair<int, int>, int> g_score;

    std::map<std::pair<int, int>, int> h_score;

    std::pair<int, int> curr_aim;

    bool searching_woodcutter = false;

    std::pair<int, int> real_woodcutter;

    bool woodcutter_known = false;

    static const int BEAR_COST = 10000;
};


#endif //REDRIDINGHOOD_ASTARHOOD_HPP
