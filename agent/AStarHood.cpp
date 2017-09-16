//
// Created by Даниил on 09.09.2017.
//

#include <bits/unique_ptr.h>
#include <algorithm>
#include <iostream>
#include "AStarHood.hpp"


AStarHood::AStarHood () : Agent () {}


AStarHood::AStarHood (std::pair<int, int> position, int score) : Agent (position, score) {}


int AStarHood::find_granny (std::unique_ptr<Map> &map) {
    curr_aim = map->get_granny_position ();
    open_list.insert (get_position ());
    g_score.insert (std::pair<std::pair<int, int>, int>(get_position (), 0));
    h_score.insert (std::pair<std::pair<int, int>, int>(get_position (), heuristic (get_position (), curr_aim)));

    std::vector<std::pair<int, int>> ways;
    while (! task_completed && get_score() > 0 && ! open_list.empty()) {
        auto step_iter = std::min_element (open_list.begin (), open_list.end (), *this);
        std::pair<int, int> next_step = *step_iter;
        open_list.erase (next_step);
        closed_list.insert (next_step);
        map->go_to (this, next_step);
        ++steps;

        ways.clear ();
        get_possible_ways (map, ways);

        for (std::vector<std::pair<int, int>>::iterator iter = ways.begin(); iter != ways.end(); iter++) {
            if (closed_list.find (*iter) != closed_list.end ())
                continue;

            if (open_list.find (*iter) == open_list.end ())
                open_list.insert (*iter);

            int updated_g_score = g_score.at (get_position ()) + 1;

            if (g_score.find (*iter) == g_score.end ())
                g_score.insert (std::pair<std::pair<int, int>, int>(*iter, updated_g_score + (map->is_in_bear_range (*iter) ? BEAR_COST : 0)));
            else {
                if (g_score.at (*iter) > updated_g_score) {
                    g_score.erase (g_score.find (*iter)) != g_score.end ();
                    g_score.insert (std::pair<std::pair<int, int>, int>(*iter, updated_g_score + (map->is_in_bear_range (*iter) ? BEAR_COST : 0)));
                }
            }

            if (h_score.find (*iter) == h_score.end())
                h_score.insert (std::pair<std::pair<int, int>, int>(*iter, heuristic (*iter, curr_aim)));
        }
    }

    if (task_completed)
        return GRANNY_FOUND;

    if (get_score () <= 0)
        return FAIL;

    return GRANNY_UNREACHABLE;
}


bool AStarHood::operator() (std::pair<int, int> pos_1, std::pair<int, int> pos_2) {
    if (g_score.find(pos_1) == g_score.end() || g_score.find(pos_2) == g_score.end())
        throw std::runtime_error("g_score does not contain compared position");
    if (h_score.find(pos_1) == h_score.end() || h_score.find(pos_2) == h_score.end())
        throw std::runtime_error("h_score does not contain compared position");

    return (g_score.at (pos_1) + h_score.at (pos_1)) < (g_score.at (pos_2) + h_score.at (pos_2));
}


void AStarHood::reset () {
    set_position (std::pair<int, int> (0, 0));
    set_score (0);
    closed_list.clear();
    open_list.clear();
    g_score.clear ();
    h_score.clear ();
    task_completed = false;
    steps = 0;
}


void AStarHood::get_possible_ways (std::unique_ptr<Map> &map, std::vector<std::pair<int, int>> &ways) {
    ways.reserve(3);

    add_if_possible(map, ways, map->north(get_position ()));
    add_if_possible(map, ways, map->east(get_position ()));
    add_if_possible(map, ways, map->south(get_position ()));
    add_if_possible(map, ways, map->west(get_position ()));
}


void AStarHood::add_if_possible (std::unique_ptr<Map> &map, std::vector<std::pair<int, int>> &ways,
                                 std::pair<int, int> position) {
    if (map->cell_exists(position))
        if (closed_list.find(position) == closed_list.end())
            if (! map->is_in_wolf_range(position))
                ways.insert (ways.begin(), position);
}


int AStarHood::heuristic (std::pair<int, int> position, std::pair<int, int> aim) {
    return std::abs (position.first - aim.first) + std::abs (position.second - aim.second);
}
