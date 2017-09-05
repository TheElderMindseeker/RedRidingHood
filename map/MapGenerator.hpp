//
// Created by Даниил on 02.09.2017.
//

#ifndef REDRIDINGHOOD_MAPGENERATOR_HPP
#define REDRIDINGHOOD_MAPGENERATOR_HPP


#include "Map.hpp"


class MapGenerator {
public:
    /**
     * @brief Default ctor
     *
     * @param seed Random seed for inner purposes
     */
    MapGenerator(unsigned seed = 6659);

    /**
     * @brief Default destructor
     */
    virtual ~MapGenerator();

    /**
     * @brief Creates new map for the Red Riding Hood and places all the static objects on it
     *
     * @param width Width of the map
     * @param height Height of the map
     *
     * @return Smart pointer to the newly created map
     */
    virtual std::unique_ptr<Map> create_map(unsigned width, unsigned height);

private:
    std::default_random_engine random_engine;
};


#endif //REDRIDINGHOOD_MAPGENERATOR_HPP
