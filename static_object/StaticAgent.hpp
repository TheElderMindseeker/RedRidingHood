//
// Created by Даниил on 31.08.2017.
//

#ifndef REDRIDINGHOOD_STATICOBJECT_HPP
#define REDRIDINGHOOD_STATICOBJECT_HPP


#include <utility>
#include "../agent/Agent.hpp"


class StaticObject {
public:
    /**
     * Defines the reaction of static object on the agent
     *
     * @param agent The agent to check reaction against
     */
    virtual void reaction(Agent *agent) = 0;

    /**
     * Checks if the provided position lies in range of effect
     *
     * @param position Position to check
     * @return True if the position lies in range, false otherwise
     */
    virtual bool is_in_range(std::pair<int, int> position) = 0;

    /**
     * Set the position of static object
     *
     * @param new_pos New position for the object
     */
    void set_position(std::pair<int, int> new_pos);

    /**
     * Set the x component of static object position
     *
     * @param x x component
     */
    void set_x(int x);

    /**
     * Set the y component of static object position
     *
     * @param y y component
     */
    void set_y(int y);

    /**
     * Get the position of static object
     *
     * @return Position as (x, y)
     */
    std::pair<int, int> get_position();

protected:
    /**
     * Creates static object in the position (0, 0)
     */
    StaticObject();

    /**
     * Creates static object in the specified position
     *
     * @param position Given position
     */
    StaticObject(std::pair<int, int> position);

    std::pair<int, int> position;
};


#endif //REDRIDINGHOOD_STATICOBJECT_HPP
