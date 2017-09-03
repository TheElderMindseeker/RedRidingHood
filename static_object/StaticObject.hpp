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
     * Defines the reation of static object on the agent
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
     * @deprecated Use the other overloaded function-element instead
     *
     * Set the position of static object
     *
     * @param x x component
     * @param y y component
     */
    void set_position(int x, int y);

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

    /**
     * @deprecated Use the other overloaded function-element
     *
     * Get the position of static object
     *
     * @param x variable to store x component
     * @param y variable to store y component
     */
    void get_position(int &x, int &y);

    /**
     * @deprecated Use get_position instead
     *
     * Get the x component of static object position
     *
     * @return x component
     */
    int get_x();

    /**
     * @deprecated Use get_position instead
     *
     * Get the y component of static object position
     *
     * @return y component
     */
    int get_y();

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
