//
// Created by Даниил on 31.08.2017.
//

#ifndef REDRIDINGHOOD_MAP_HPP
#define REDRIDINGHOOD_MAP_HPP


#include <iostream>
#include <utility>
#include <random>


class Agent;
class StaticObject;
class Bear;
class Granny;
class Wolf;
class Woodcutter;


class Map {
    friend class MapGenerator;

public:
    /**
     * @brief Creates new map with specified width and height
     *
     * @param width Map width
     * @param height Map height
     * @param seed Random seed for inner needs
     */
    Map(unsigned width, unsigned height, unsigned seed = 24623);

    /**
     * @brief Standard destructor
     */
    virtual ~Map();

    /**
     * Checks if the given cell is present on the map
     *
     * @param cell Position of cell
     * @return True, if cell exists, false otherwise
     */
    bool cell_exists(std::pair<int, int> cell);

    /**
     * Calculates cell position which is to the north of the given
     *
     * @param cell Given cell
     * @return Cell which is to the north of the given
     */
    std::pair<int, int> north(std::pair<int, int> cell);

    /**
     * Calculates cell position which is to the east of the given
     *
     * @param cell Given cell
     * @return Cell which is to the east of the given
     */
    std::pair<int, int> east(std::pair<int, int> cell);

    /**
     * Calculates cell position which is to the south of the given
     *
     * @param cell Given cell
     * @return Cell which is to the south of the given
     */
    std::pair<int, int> south(std::pair<int, int> cell);

    /**
     * Calculates cell position which is to the west of the given
     *
     * @param cell Given cell
     * @return Cell which is to the west of the given
     */
    std::pair<int, int> west(std::pair<int, int> cell);

    /**
     * Checks if provided position is in wolf's effect range
     *
     * @param position Provided position
     * @return True if the position is in wolf's range, false otherwise
     */
    bool is_in_wolf_range(std::pair<int, int> position);

    /**
     * Checks whether wolf is in provided position
     *
     * @param position Provided position
     * @return True if wolf is in the position, false otherwise
     */
    bool is_wolf(std::pair<int, int> position);

    /**
     * Checks whether provided position is in bear's range
     *
     * @param position Provided position
     * @return True if the position is in bear's range, false otherwise
     */
    bool is_in_bear_range(std::pair<int, int> position);

    /**
     * Checks if the bear is in provided position
     *
     * @param position Provided position
     * @return True if bear is in the position, false otherwise
     */
    bool is_bear(std::pair<int, int> position);

    /**
     * Checks if woodcutter is in provided position
     *
     * @param position Provided position
     * @return True if woodcutter is in the position, false otherwise
     */
    bool is_woodcutter(std::pair<int, int> position);

    /**
     * Tells two possible woodcutter positions
     *
     * @param pos_1 Variable to save first possible woodcutter position
     * @param pos_2 Variable to save second possible woodcutter position
     */
    void get_possible_woodcutter_positions(std::pair<int, int> &pos_1, std::pair<int, int> &pos_2);

    /**
     * Checks if granny is in provided position
     *
     * @param position Provided position
     * @return True if granny is in the position, false otherwise
     */
    bool is_granny(std::pair<int, int> position);

    /**
     * Tells granny position
     *
     * @return Granny position
     */
    std::pair<int, int> get_granny_position();

    /**
     * Simulate agent moving to specified position
     *
     * @param agent Agent to move
     * @param position Specified position
     */
    void go_to(Agent *agent, std::pair<int, int> position);

    /**
     * @brief Draws a map into the stdout using ASCII
     *
     * @note This function-element is only for debug purposes
     */
    void draw (); // TODO: Make this function-element and others const

private:
    void optimize_objects();

    unsigned width;
    unsigned height;

    Bear *bear;
    Granny *granny;
    Wolf *wolf;
    Woodcutter *woodcutter;

    StaticObject *objects[4];

    std::pair<int, int> alt_woodcutter_position;

    std::default_random_engine random_engine;
    std::uniform_int_distribution<unsigned> distribution;
};


#endif //REDRIDINGHOOD_MAP_HPP
