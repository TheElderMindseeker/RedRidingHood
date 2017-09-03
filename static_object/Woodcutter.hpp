//
// Created by Даниил on 03.09.2017.
//

#ifndef REDRIDINGHOOD_WOODCUTTER_HPP
#define REDRIDINGHOOD_WOODCUTTER_HPP


#include "StaticObject.hpp"


class Woodcutter : public StaticObject {
public:
    void reaction(Agent *agent) override;

    bool is_in_range(std::pair<int, int> position) override;
};


#endif //REDRIDINGHOOD_WOODCUTTER_HPP
