//
// Created by Даниил on 03.09.2017.
//

#ifndef REDRIDINGHOOD_GRANNY_HPP
#define REDRIDINGHOOD_GRANNY_HPP


#include "StaticObject.hpp"


class Granny : public StaticObject {
public:
    void reaction(Agent *agent) override;

    bool is_in_range(std::pair<int, int> position) override;
};


#endif //REDRIDINGHOOD_GRANNY_HPP
