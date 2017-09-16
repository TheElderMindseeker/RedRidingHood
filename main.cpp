#include <bits/unique_ptr.h>
#include <iostream>
#include <iomanip>
#include "map/MapGenerator.hpp"
#include "agent/BacktrackHood.hpp"
#include "agent/AStarHood.hpp"


int main(int argc, char **argv) {
    MapGenerator mg;
    AStarHood a_rrh(std::pair<int, int> (0, 0), 6);
    BacktrackHood b_rrh (std::pair<int, int> (0, 0), 6);

    for (int i = 0; i < 3; i++) {
        std::unique_ptr<Map> map = mg.create_map(9, 9);

        std::cout << "The result of Red Riding Hood solving the map: " << a_rrh.find_granny(map) << "\n";
        std::cout << "The RRH agent made " << a_rrh.get_steps() << " steps\n\n";

        std::cout << "The result of Red Riding Hood solving the map: " << b_rrh.find_granny(map) << "\n";
        std::cout << "The RRH agent made " << b_rrh.get_steps() << " steps\n\n";

        a_rrh.reset();
        a_rrh.set_score(6);
        b_rrh.reset();
        b_rrh.set_score(6);
    }

    return 0;
}