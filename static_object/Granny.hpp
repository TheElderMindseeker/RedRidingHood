//
// Created by Даниил on 03.09.2017.
//

#ifndef REDRIDINGHOOD_GRANNY_HPP
#define REDRIDINGHOOD_GRANNY_HPP


#include "StaticAgent.hpp"


class Granny : public StaticObject {
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


#endif //REDRIDINGHOOD_GRANNY_HPP
