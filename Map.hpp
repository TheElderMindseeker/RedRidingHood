//
// Created by Даниил on 31.08.2017.
//

#ifndef REDRIDINGHOOD_MAP_HPP
#define REDRIDINGHOOD_MAP_HPP


#include <utility>


class Map {
    friend class MapGenerator;

public:
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
     * Checks if granny is in provided position
     *
     * @param position Provided position
     * @return True if granny is in the position, false otherwise
     */
    bool is_granny(std::pair<int, int> position);
};


#endif //REDRIDINGHOOD_MAP_HPP
