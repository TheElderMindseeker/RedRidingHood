#include <bits/unique_ptr.h>
#include <iostream>
#include <iomanip>
#include <chrono>
#include "map/MapGenerator.hpp"
#include "agent/BacktrackHood.hpp"
#include "agent/AStarHood.hpp"


long int element_sum (const int *start, const int *end);
float element_sum (const std::chrono::nanoseconds *start, const std::chrono::nanoseconds *end);


int main(int argc, char **argv) {
    const unsigned NUMBER_OF_TESTS = 1000;

    MapGenerator mg;
    AStarHood a_star_hood(std::pair<int, int> (0, 0), 6);
    BacktrackHood backtrack_hood (std::pair<int, int> (0, 0), 6);

    int a_star_results [3] = {0, 0, 0};
    int backtrack_results [3] = {0, 0, 0};

    unsigned a_star_steps [NUMBER_OF_TESTS];
    unsigned backtrack_steps [NUMBER_OF_TESTS];

    std::chrono::high_resolution_clock clock;

    std::chrono::nanoseconds a_star_time [NUMBER_OF_TESTS];
    std::chrono::nanoseconds backtrack_time [NUMBER_OF_TESTS];

    for (int t = 0; t < NUMBER_OF_TESTS; t++) {
        // Generate a map which both agents will solve
        std::unique_ptr<Map> map = mg.create_map(9, 9);

        // Acquire the results and execution duration
        std::chrono::time_point<std::chrono::high_resolution_clock> a_star_start = clock.now ();
        ++a_star_results [a_star_hood.find_granny (map)];
        a_star_time [t] = std::chrono::duration_cast<std::chrono::nanoseconds> (clock.now () - a_star_start);

        std::chrono::time_point<std::chrono::high_resolution_clock> backtrack_start = clock.now ();
        ++backtrack_results [backtrack_hood.find_granny (map)];
        backtrack_time [t] = std::chrono::duration_cast<std::chrono::nanoseconds> (clock.now () - backtrack_start);

        // Acquire number of steps each algorithm has done to solve the map
        a_star_steps [t] = a_star_hood.get_steps ();
        backtrack_steps [t] = backtrack_hood.get_steps ();

        // We need to do a reset after each map adventure
        // See AStarHood::reset() and BacktrackHood::reset() for more information
        a_star_hood.reset ();
        a_star_hood.set_score (6);
        backtrack_hood.reset ();
        backtrack_hood.set_score (6);
    }

    // Calculate mean number of steps needed to solve a map
    float mean_a_star_steps = element_sum ((const int *) a_star_steps, (const int *) a_star_steps + NUMBER_OF_TESTS) / NUMBER_OF_TESTS;
    float mean_backtrack_steps = element_sum ((const int *) backtrack_steps, (const int *) backtrack_steps + NUMBER_OF_TESTS) / NUMBER_OF_TESTS;

    float mean_a_star_time = element_sum (a_star_time, a_star_time + NUMBER_OF_TESTS) / NUMBER_OF_TESTS;
    float mean_backtrack_time = element_sum (backtrack_time, backtrack_time + NUMBER_OF_TESTS) / NUMBER_OF_TESTS;

    std::cout << "\nResults:\n";
    std::cout << "Number of successfully completed maps:\n";
    std::cout << "\tA*\t\t" << a_star_results [Agent::GRANNY_FOUND] << '\n';
    std::cout << "\tBacktrack\t" << backtrack_results [Agent::GRANNY_FOUND] << '\n';
    std::cout << "Number of unsolvable maps:\n";
    std::cout << "\tA*\t\t" << a_star_results [Agent::GRANNY_UNREACHABLE] << '\n';
    std::cout << "\tBacktrack\t" << backtrack_results [Agent::GRANNY_UNREACHABLE] << '\n';
    std::cout << "Number of failed maps:\n";
    std::cout << "\tA*\t\t" << a_star_results [Agent::FAIL] << '\n';
    std::cout << "\tBacktrack\t" << backtrack_results [Agent::FAIL] << '\n';
    std::cout << "Mean number of steps for solving a map:\n";
    std::cout << "\tA*\t\t" << mean_a_star_steps << '\n';
    std::cout << "\tBacktrack\t" << mean_backtrack_steps << '\n';
    std::cout << "Mean time each algorithm has worked solving one map:\n";
    std::cout.setf(std::ios_base::fixed | std::ios_base::right);
    std::cout.precision (3);
    std::cout << "\tA*\t\t" << mean_a_star_time << "\tnanoseconds" << '\n';
    std::cout << "\tBacktrack\t" << mean_backtrack_time << "\tnanoseconds" << std::endl;

    return 0;
}


long int element_sum (const int *start, const int *end) {
    long int sum = 0;
    for (const int *iter = start; iter != end; iter++) {
        sum += *iter;
    }
    return sum;
}


float element_sum (const std::chrono::nanoseconds *start, const std::chrono::nanoseconds *end) {
    float sum = 0.0f;
    for (const std::chrono::nanoseconds *iter = start; iter != end; iter++) {
        sum += iter->count ();
    }
    return sum;
}