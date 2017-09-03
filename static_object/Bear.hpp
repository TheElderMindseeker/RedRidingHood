//
// Created by Даниил on 03.09.2017.
//

#ifndef REDRIDINGHOOD_BEAR_HPP
#define REDRIDINGHOOD_BEAR_HPP


#include "StaticObject.hpp"


class Bear : public StaticObject {
public:
    void reaction(Agent *agent) override;

    bool is_in_range(std::pair<int, int> position) override;
};


#endif //REDRIDINGHOOD_BEAR_HPP
