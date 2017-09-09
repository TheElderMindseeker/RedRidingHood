//
// Created by Даниил on 09.09.2017.
//

#include <memory>
#include "BacktrackHood.hpp"


BacktrackHood::BacktrackHood() : Agent() {}


BacktrackHood::BacktrackHood(std::pair<int, int> position, int score) : Agent(position, score) {}


int BacktrackHood::find_granny(std::unique_ptr<Map> map) {
    curr_aim = map->get_granny_position();
    reset_search();

    std::vector<std::pair<int, int>> ways;
    while (! task_completed && get_score() > 0 && ! impossible) {
        ways = get_possible_ways(map);

        if (ways.empty()) {
            if (path.empty()) {
                impossible = true;
            }
            else {
                map->go_to(this, path.top());
                ++steps;
                path.pop();
            }
        }
        else {
            std::pair<int, int> best = choose_minimal_distance(ways);
            path.push(get_position());
            map->go_to(this, best);
            ++steps;
            checked.emplace(best, true);
        }
    }

    if (task_completed)
        return GRANNY_FOUND;

    if (get_score() <= 0)
        return GRANNY_UNREACHABLE;

    return FAIL;
}


std::vector<std::pair<int, int>> BacktrackHood::get_possible_ways(std::unique_ptr<Map> &map) {
    std::vector<std::pair<int, int>> ways;
    ways.reserve(3);

    add_if_possible(map, ways, map->north(get_position()));
    add_if_possible(map, ways, map->east(get_position()));
    add_if_possible(map, ways, map->south(get_position()));
    add_if_possible(map, ways, map->west(get_position()));

    return ways;
}


void BacktrackHood::add_if_possible(std::unique_ptr<Map> &map, std::vector<std::pair<int, int>> &ways, std::pair<int, int> position) {
    if (map->cell_exists(position))
        if (path.empty() || (position != path.top()))
            if (! map->is_in_bear_range(position) && ! map->is_in_wolf_range(position))
                if (checked.find(position) == checked.end())
                    ways.push_back(position);
}


std::pair<int, int> BacktrackHood::choose_minimal_distance(std::vector<std::pair<int, int>> &ways) {
    std::vector<std::pair<int, int>>::iterator iter, best;
    for (iter = ways.begin(), best = iter; iter != ways.end(); iter++) {
        if (distance(*iter, curr_aim) < distance(*best, curr_aim)) {
            best = iter;
        }
    }
    return *best;
}


int BacktrackHood::distance(std::pair<int, int> source_position, std::pair<int, int> target_position) {
    return ((source_position.first - target_position.first) * (source_position.first - target_position.first)
            + (source_position.second - target_position.second) * (source_position.second - target_position.second));
}


void BacktrackHood::set_new_aim(std::pair<int, int> aim) {
    curr_aim = aim;
}


void BacktrackHood::reset_search() {
    while (! path.empty())
        path.pop();
    checked.clear();
}
