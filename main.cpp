#include <bits/unique_ptr.h>
#include <iostream>
#include <iomanip>
#include <map>
#include "map/MapGenerator.hpp"
#include "agent/BacktrackHood.hpp"


int main(int argc, char **argv) {
    MapGenerator mg;
    BacktrackHood agent;
    std::map<int, int> results;

    for (int i = 0; i < 100; i++) {
        agent.set_score(6);
        agent.set_position(std::pair<int, int>(0, 0));
        int answer = agent.find_granny(mg.create_map(9, 9));

        if (results.find(answer) != results.end())
            results.at(answer) = results.at(answer) + 1;
        else
            results.emplace(answer, 1);
    }

    for (auto iter = results.begin(); iter != results.end(); iter++)
        std::cout << iter->first << ' ' << iter->second << '\n';

    return 0;
}