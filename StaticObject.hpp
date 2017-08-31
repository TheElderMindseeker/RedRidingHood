//
// Created by Даниил on 31.08.2017.
//

#ifndef REDRIDINGHOOD_STATICOBJECT_HPP
#define REDRIDINGHOOD_STATICOBJECT_HPP


#include "Agent.hpp"


class StaticObject {
public:
    /**
     * Defines the reation of static object on the agent
     * @param agent The agent to check reaction against
     */
    virtual void reaction(Agent *agent) = 0;

    /**
     * Set the position of static object
     * @param x x component
     * @param y y component
     */
    void set_position(int x, int y);

    /**
     * Set the x component of static object position
     * @param x x component
     */
    void set_x(int x);

    /**
     * Set the y component of static object position
     * @param y y component
     */
    void set_y(int y);

    /**
     * Get the position of static object
     * @param x variable to store x component
     * @param y variable to store y component
     */
    void get_position(int &x, int &y);

    /**
     * Get the x component of static object position
     * @return x component
     */
    int get_x();

    /**
     * Get the y component of static object position
     * @return y component
     */
    int get_y();

private:
    int x_pos;
    int y_pos;
};


#endif //REDRIDINGHOOD_STATICOBJECT_HPP
