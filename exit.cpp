#include "exit.h"
using namespace std;
/*Direction stringToDirection(const string& str) {
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
}*/
Exit::Exit( Room* targetRoom, bool isLocked)
    :  targetRoom(targetRoom), isLocked(isLocked) {}
bool Exit::getIsLocked() const { return isLocked; }
void Exit::setIsLocked(bool value) { isLocked = value; }
void Exit::unlock(){setIsLocked(false);}
