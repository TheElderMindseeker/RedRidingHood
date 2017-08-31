//
// Created by Даниил on 31.08.2017.
//

#ifndef REDRIDINGHOOD_MAP_HPP
#define REDRIDINGHOOD_MAP_HPP


#include <utility>


class Map {
public:
    /**
     * Checks if the given cell is present on the map
     * @param cell Position of cell
     * @return True, if cell exists, false otherwise
     */
    bool cell_exists(std::pair<int, int> cell);

    /**
     * Calculates cell position which is to the north of the given
     * @param cell Given cell
     * @return Cell which is to the north of the given
     */
    std::pair<int, int> north(std::pair<int, int> cell);

    /**
     * Calculates cell position which is to the east of the given
     * @param cell Given cell
     * @return Cell which is to the east of the given
     */
    std::pair<int, int> east(std::pair<int, int> cell);

    /**
     * Calculates cell position which is to the south of the given
     * @param cell Given cell
     * @return Cell which is to the south of the given
     */
    std::pair<int, int> south(std::pair<int, int> cell);

    /**
     * Calculates cell position which is to the west of the given
     * @param cell Given cell
     * @return Cell which is to the west of the given
     */
    std::pair<int, int> west(std::pair<int, int> cell);
};


#endif //REDRIDINGHOOD_MAP_HPP
