#include <bits/unique_ptr.h>
#include <iostream>
#include <iomanip>
#include "map/MapGenerator.hpp"
#include "agent/BacktrackHood.hpp"


int main(int argc, char **argv) {
    MapGenerator mg;
    BacktrackHood rrh(std::pair<int, int> (0, 0), 6);

    for (int i = 0; i < 10; i++) {
        std::unique_ptr<Map> map_1 = mg.create_map(10, 10);

        std::cout << "The result of Red Riding Hood solving the map: " << rrh.find_granny(map_1) << "\n";
        std::cout << "The RRH agent made " << rrh.get_steps() << " steps\n\n";

        rrh.reset();
        rrh.set_score(6);
    }

    return 0;
}