#include <bits/unique_ptr.h>
#include <iostream>
#include <iomanip>
#include "map/MapGenerator.hpp"


int main(int argc, char **argv) {
    MapGenerator mg;

    for (int i = 0; i < 10; i++) {
        std::unique_ptr<Map> map_1 = mg.create_map(10, 10);

        if (map_1.get() != nullptr)
            std::cout << "Alright, the map was successfully generated!\n";
        else
            std::cout << "There is some problem with map generation\n";

        std::cout << "Granny position: " << map_1->get_granny_position().first
                  << ' ' << map_1->get_granny_position().second << std::endl;

        std::pair<int, int> woodc_1, woodc_2;
        map_1->get_possible_woodcutter_positions(woodc_1, woodc_2);

        std::cout << "Possible woodcutter positions: " << woodc_1.first << ' ' << woodc_1.second
                  << ", " << woodc_2.first << ' ' << woodc_2.second << std::endl;

        std::cout << "Is granny in bear or wolf range: " << std::setiosflags(std::ios::boolalpha)
                  << (map_1->is_in_bear_range(map_1->get_granny_position()) || map_1->is_in_wolf_range(map_1->get_granny_position()))
                  << std::endl;

        std::cout << "Is woodcutter_1 in bear or wolf range: "
                  << (map_1->is_in_bear_range(woodc_1) || map_1->is_in_wolf_range(woodc_1))
                  << std::endl;

        std::cout << "\n\n";
    }

    return 0;
}