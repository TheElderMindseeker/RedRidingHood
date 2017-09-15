//
// Created by Даниил on 09.09.2017.
//

#ifndef REDRIDINGHOOD_ASTARHOOD_HPP
#define REDRIDINGHOOD_ASTARHOOD_HPP


#include "Agent.hpp"


class AStarHood : public Agent {
public:
    int find_granny(std::unique_ptr<Map> &map) override;
};


#endif //REDRIDINGHOOD_ASTARHOOD_HPP
