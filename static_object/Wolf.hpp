//
// Created by Даниил on 03.09.2017.
//

#ifndef REDRIDINGHOOD_WOLF_HPP
#define REDRIDINGHOOD_WOLF_HPP


#include "StaticAgent.hpp"


class Wolf : public StaticObject {
public:
    /**
     * Defines the reaction of static object on the agent
     *
     * @param agent The agent to check reaction against
     */
    void reaction(Agent *agent) override;

    /**
     * Checks if the provided position lies in range of effect
     *
     * @param position Position to check
     * @return True if the position lies in range, false otherwise
     */
    bool is_in_range(std::pair<int, int> position) override;
};


#endif //REDRIDINGHOOD_WOLF_HPP
