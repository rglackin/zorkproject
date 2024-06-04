#include "directionenum.h"
#include <map>
#include <stdexcept>
Direction DirectionUtils::stringToDirection(const string& str) {
    static const std::map<string, Direction> directionMap = {
        {"north", Direction::NORTH},
        {"south", Direction::SOUTH},
        {"east", Direction::EAST},
        {"west", Direction::WEST}
    };
    auto it = directionMap.find(str);
    if (it != directionMap.end()) {
        return it->second;
    } else {
        throw invalid_argument("Invalid direction input");
    }
}
