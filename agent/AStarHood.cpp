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
    // Preset current aim to granny, insert starting position to open list and calculate its g() and h()
    curr_aim = map->get_granny_position ();
    open_list.insert (get_position ());
    g_score.insert (std::pair<std::pair<int, int>, int>(get_position (), 0));
    h_score.insert (std::pair<std::pair<int, int>, int>(get_position (), heuristic (get_position (), curr_aim)));

    std::vector<std::pair<int, int>> ways;
    while (! task_completed && get_score() > 0 && ! open_list.empty()) {
        check_woodcutter (map);
        update_state (map);

        // Find next possible position with minimal weight and go to it
        auto step_iter = std::min_element (open_list.begin (), open_list.end (), *this);
        std::pair<int, int> next_step = *step_iter;
        open_list.erase (step_iter);

        // Legal hack: we do not go into bear range if we are low on berries
        if (map->is_in_bear_range (next_step) && get_score () <= 2)
            continue;

        closed_list.insert (next_step);
        map->go_to (this, next_step);
        ++steps;

        // Observe neighbouring cells and add them to open list if possible
        ways.clear ();
        get_possible_ways (map, ways);

        for (std::vector<std::pair<int, int>>::iterator iter = ways.begin(); iter != ways.end(); iter++) {
            // We are not dealing with positions in closed list
            if (closed_list.find (*iter) != closed_list.end ())
                continue;

            if (open_list.find (*iter) == open_list.end ())
                open_list.insert (*iter);

            // Try to update g() for the position currently being examined
            int updated_g_score = g_score.at (get_position ()) + 100;

            if (g_score.find (*iter) == g_score.end ())
                g_score.insert (std::pair<std::pair<int, int>, int>(*iter, updated_g_score + (map->is_in_bear_range (*iter) ? BEAR_COST : 0)));
            else {
                if (g_score.at (*iter) > updated_g_score) {
                    g_score.erase (g_score.find (*iter)) != g_score.end ();
                    g_score.insert (std::pair<std::pair<int, int>, int>(*iter, updated_g_score + (map->is_in_bear_range (*iter) ? BEAR_COST : 0)));
                }
            }

            // Set up h() for newly discovered positions
            if (h_score.find (*iter) == h_score.end())
                h_score.insert (std::pair<std::pair<int, int>, int>(*iter, heuristic (*iter, curr_aim)));
        }
    }

    if (task_completed)
        return GRANNY_FOUND;

    if (get_score () <= 0)
        return FAIL;

    // If agent is not failed but has not found granny -- granny is unreachable
    return GRANNY_UNREACHABLE;
}


void AStarHood::update_state (std::unique_ptr<Map> &map) {
    if (get_position () == curr_aim && ! task_completed) {
        partial_reset ();

        if (get_score () < 6) {
            if (woodcutter_known) {
                curr_aim = real_woodcutter;
            }
            else {
                std::pair<int, int> woodc_1, woodc_2;
                map->get_possible_woodcutter_positions (woodc_1, woodc_2);
                if (heuristic (get_position (), woodc_1) < heuristic (get_position (), woodc_2)) {
                    curr_aim = woodc_1;
                }
                else {
                    curr_aim = woodc_2;
                }
            }
            searching_woodcutter = true;
        }
        else {
            curr_aim = map->get_granny_position ();
        }

        open_list.insert (get_position ());
        g_score.insert (std::pair<std::pair<int, int>, int>(get_position (), 0));
        h_score.insert (std::pair<std::pair<int, int>, int>(get_position (), heuristic (get_position (), curr_aim)));
    }
}


void AStarHood::check_woodcutter (std::unique_ptr<Map> &map) {
    if (map->is_woodcutter (get_position ())) {
        woodcutter_known = true;
        real_woodcutter = get_position ();
    }
    else {
        std::pair<int, int> woodc_1, woodc_2;
        map->get_possible_woodcutter_positions (woodc_1, woodc_2);
        if (get_position () == woodc_1) {
            woodcutter_known = true;
            real_woodcutter = woodc_2;
        }
        else if (get_position () == woodc_2) {
            woodcutter_known = true;
            real_woodcutter = woodc_1;
        }
    }
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
    woodcutter_known = false;
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
            if (((! searching_woodcutter && get_score () > 2) || ! map->is_in_bear_range (position))
                    && ! map->is_in_wolf_range(position))
                ways.insert (ways.begin(), position);
}


int AStarHood::heuristic (std::pair<int, int> position, std::pair<int, int> aim) const {
    return std::abs (position.first - aim.first) + std::abs (position.second - aim.second);
}


void AStarHood::partial_reset () {
    closed_list.clear();
    open_list.clear();
    g_score.clear ();
    h_score.clear ();
    searching_woodcutter = false;
}
