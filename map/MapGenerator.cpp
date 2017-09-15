//
// Created by Даниил on 02.09.2017.
//

#include <memory>
#include <algorithm>
#include <iostream>
#include "MapGenerator.hpp"
#include "../static_object/StaticObject.hpp"
#include "../static_object/Bear.hpp"
#include "../static_object/Granny.hpp"
#include "../static_object/Wolf.hpp"
#include "../static_object/Woodcutter.hpp"


MapGenerator::MapGenerator(unsigned int seed) {
    random_engine.seed(seed);
}


MapGenerator::~MapGenerator() {}


std::unique_ptr<Map> MapGenerator::create_map(unsigned width, unsigned height) {
    unsigned w = std::min(width, 7u);
    unsigned h = std::min(height, 7u);

    const std::pair<int, int> rrh_position(0, 0);

    std::unique_ptr<Map> map(new Map(w, h));

    std::uniform_int_distribution<unsigned> x_distr(0, w - 1), y_distr(0, h - 1);

    Bear *bear = new Bear;
    Granny *granny = new Granny;
    Wolf *wolf = new Wolf;
    Woodcutter *woodcutter = new Woodcutter;
    std::pair<int, int> alt_woodcutter_position;

    do {
        bear->set_position(std::make_pair(x_distr(random_engine), y_distr(random_engine)));
    }
    while (bear->is_in_range(rrh_position));

    do {
        wolf->set_position(std::make_pair(x_distr(random_engine), y_distr(random_engine)));
    }
    while (wolf->get_position() == bear->get_position() || wolf->is_in_range(rrh_position));

    do {
        granny->set_position(std::make_pair(x_distr(random_engine), y_distr(random_engine)));
    }
    while (wolf->is_in_range(granny->get_position()) || bear->is_in_range(granny->get_position())
            || granny->get_position() == rrh_position);

    do {
        woodcutter->set_position(std::make_pair(x_distr(random_engine), y_distr(random_engine)));
    }
    while (wolf->is_in_range(woodcutter->get_position()) || bear->is_in_range(woodcutter->get_position())
            || granny->get_position() == woodcutter->get_position() || woodcutter->get_position() == rrh_position);

    do {
        alt_woodcutter_position = std::make_pair(x_distr(random_engine), y_distr(random_engine));
    }
    while (wolf->is_in_range(alt_woodcutter_position) || bear->is_in_range(alt_woodcutter_position)
            || granny->get_position() == alt_woodcutter_position || alt_woodcutter_position == rrh_position
            || woodcutter->get_position() == alt_woodcutter_position);

    map->bear = bear;
    map->granny = granny;
    map->wolf = wolf;
    map->woodcutter = woodcutter;
    map->alt_woodcutter_position = alt_woodcutter_position;

    std::cout << "Bear position: [" << bear->get_position().first << ", " << bear->get_position().second << "]\n";
    std::cout << "Granny position: [" << granny->get_position().first << ", " << granny->get_position().second << "]\n";
    std::cout << "Wolf position: [" << wolf->get_position().first << ", " << wolf->get_position().second << "]\n";
    std::cout << "Woodcutter position: [" << woodcutter->get_position().first << ", " << woodcutter->get_position().second << "]\n";
    std::cout << "False Woodcutter position: [" << alt_woodcutter_position.first << ", " << alt_woodcutter_position.second << "]\n\n";

    map->optimize_objects();

    return map;
}

