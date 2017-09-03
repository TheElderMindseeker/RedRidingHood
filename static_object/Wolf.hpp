//
// Created by Даниил on 03.09.2017.
//

#ifndef REDRIDINGHOOD_WOLF_HPP
#define REDRIDINGHOOD_WOLF_HPP


#include "StaticObject.hpp"


class Wolf : public StaticObject {
public:
    void reaction(Agent *agent) override;

    bool is_in_range(std::pair<int, int> position) override;
};


#endif //REDRIDINGHOOD_WOLF_HPP
