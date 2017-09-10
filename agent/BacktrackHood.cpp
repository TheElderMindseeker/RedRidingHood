//
// Created by Даниил on 09.09.2017.
//

#include <memory>
#include "BacktrackHood.hpp"


BacktrackHood::BacktrackHood() : Agent() {}


BacktrackHood::BacktrackHood(std::pair<int, int> position, int score) : Agent(position, score) {}


int BacktrackHood::find_granny(std::unique_ptr<Map> map) {
    task_completed = false;
    impossible = false;
    fearless = false;
    reset_search();
    curr_aim = map->get_granny_position();

    std::vector<std::pair<int, int>> ways;
    while (! task_completed && get_score() > 0 && ! impossible) {
        update_inner_condition(map);
        ways = get_possible_ways(map);

        if (ways.empty()) {
            if (path.empty()) {
                not_found = true;
            }
            else {
                map->go_to(this, path.top());
                ++steps;
                path.pop();
            }
        }
        else {
            std::pair<int, int> best = choose_minimal_distance(map, ways);
            path.push(get_position());
            map->go_to(this, best);
            ++steps;
            checked.insert(best);
        }
    }

    if (task_completed)
        return GRANNY_FOUND;

    if (get_score() <= 0)
        return FAIL;

    return GRANNY_UNREACHABLE;
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
            if ((fearless || ! map->is_in_bear_range(position)) && (! map->is_in_wolf_range(position)))
                if (checked.find(position) == checked.end())
                    ways.push_back(position);
}


std::pair<int, int>
BacktrackHood::choose_minimal_distance(std::unique_ptr<Map> &map, std::vector<std::pair<int, int>> &ways) {
    std::vector<std::pair<int, int>>::iterator iter, best;
    for (iter = ways.begin(), best = iter; iter != ways.end(); iter++) {
        if (distance(*iter, curr_aim) < distance(*best, curr_aim)) {
            if (fearless)
                if (map->is_in_bear_range(*best))
                    best = iter;
            else
                best = iter;
        }
    }
    return *best;
}


int BacktrackHood::distance(std::pair<int, int> source_position, std::pair<int, int> target_position) {
    return std::abs(source_position.first - target_position.first) + std::abs(source_position.second - target_position.second);
}


void BacktrackHood::update_inner_condition(std::unique_ptr<Map> &map) {
    check_for_woodcutter(map);

    if (! fearless && get_score() >= 6) {
        if (not_found) {
            fearless = true;
            reset_search();
            curr_aim = map->get_granny_position();
        } else if (curr_aim != map->get_granny_position()) {
            reset_search();
            curr_aim = map->get_granny_position();
        }
    }
    else if (fearless && get_score() >= 6) {
        if (not_found) {
            impossible = true;
        }
    }
    else {
        if (not_found) {
            impossible = true;
        }
        else if (get_position() == map->get_granny_position() && get_score() < 6) {
            fearless = false;
            reset_search();

            if (woodcutter_known) {
                curr_aim = real_woodcutter;
            } else {
                std::pair<int, int> pos_1, pos_2;
                map->get_possible_woodcutter_positions(pos_1, pos_2);

                if (distance(get_position(), pos_1) < distance(get_position(), pos_2))
                    curr_aim = pos_1;
                else
                    curr_aim = pos_2;
            }
        }
        else if (woodcutter_known && curr_aim != real_woodcutter && get_score() < 6) {
            fearless = false;
            reset_search();
            curr_aim = real_woodcutter;
        }
    }
}


void BacktrackHood::check_for_woodcutter(std::unique_ptr<Map> &map) {
    if (map->is_woodcutter(get_position())) {
        woodcutter_known = true;
        real_woodcutter = get_position();
    }
    else {
        std::pair<int, int> pos_1, pos_2;
        map->get_possible_woodcutter_positions(pos_1, pos_2);

        if (get_position() == pos_1) {
            woodcutter_known = true;
            real_woodcutter = pos_2;
        }
        else if (get_position() == pos_2) {
            woodcutter_known = true;
            real_woodcutter = pos_1;
        }
    }
}


void BacktrackHood::set_new_aim(std::pair<int, int> aim) {
    curr_aim = aim;
}


void BacktrackHood::reset_search() {
    while (! path.empty())
        path.pop();
    checked.clear();
    not_found = false;
    task_completed = false;
}
