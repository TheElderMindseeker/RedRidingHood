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

    int astar_results [3] = {0, 0, 0};
    int backtrack_results [3] = {0, 0, 0};

    for (int i = 0; i < 1000; i++) {
        std::unique_ptr<Map> map = mg.create_map(9, 9);

        int astar_res, backtrack_res;

        ++astar_results [astar_res = a_rrh.find_granny (map)];
        ++backtrack_results [backtrack_res = b_rrh.find_granny (map)];

        if (astar_res == Agent::FAIL) {
            map->draw ();
            std::cout << '\n';
        }

        /*if (backtrack_res == Agent::GRANNY_UNREACHABLE) {
            map->draw ();
            std::cout << '\n';
        }*/

        a_rrh.reset ();
        a_rrh.set_score (6);
        b_rrh.reset ();
        b_rrh.set_score (6);
    }

    std::cout << "\nResults:\n";
    for (int i = 0; i < 3; i++) {
        std::cout << astar_results [i] << '\n';
        std::cout << backtrack_results [i] << '\n';
    }

    return 0;
}