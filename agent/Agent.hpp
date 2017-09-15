//
// Created by Даниил on 31.08.2017.
//

#ifndef REDRIDINGHOOD_AGENT_HPP
#define REDRIDINGHOOD_AGENT_HPP


#include <utility>
#include <bits/unique_ptr.h>
#include "../map/Map.hpp"


class Agent {
public:
    /**
     * Solve the task of fetching 6 berries to granny on provided map
     *
     * @param map Map of the task
     * @return Success code if the granny was found, failure code otherwise
     */
    virtual int find_granny(std::unique_ptr<Map> &map) = 0;

    /**
     * Tells current position of agent
     *
     * @return Current position of agent as (x, y)
     */
    std::pair<int, int> get_position();

    /**
     * Moves agent to a new position
     *
     * @param new_position New position of agent
     */
    void set_position(std::pair<int, int> new_position);

    /**
     * Tells current score of agent
     *
     * @return Current score of agent
     */
    int get_score();

    /**
     * Sets the score of agent
     *
     * @param new_score New score number
     */
    void set_score(int new_score);

    /**
     * Returns number of steps taken to solve the task
     *
     * @return Number of algorithm steps
     */
    unsigned get_steps();

    /**
     * Tells the agent that his task is completed leading to GRANNY_FOUND result
     */
    void set_task_completed();

    /**
     * The return result of function-element find_granny if the granny was successfully found
     */
    static const int GRANNY_FOUND = 0;

    /**
     * The return result of function-element find_granny if the granny is unreachable (impossible to avoid wolf and bear)
     */
    static const int GRANNY_UNREACHABLE = 1;

    /**
     * The return result of function-element find_granny if the agent was murdered by the wolf or
     * the berries were stolen by the bear
     */
    static const int FAIL = 2;

protected:
    /**
     * Creates agent in position (0, 0) with 0 score
     */
    Agent();

    /**
     * Creates agent in specified position and with specified score
     *
     * @param position Initial position of agent
     * @param score Initial score of agent
     */
    Agent(std::pair<int, int> position, int score = 0);

    /**
     * Has Red Riding Hood arrived at Granny's house with 6 berries
     */
    bool task_completed = false;

    /**
     * Number of steps taken by the algorithm to solve the task
     */
    unsigned steps;

private:
    int score;

    std::pair<int, int> position;
};


#endif //REDRIDINGHOOD_AGENT_HPP
