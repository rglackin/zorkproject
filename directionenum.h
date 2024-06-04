#ifndef DIRECTIONENUM_H
#define DIRECTIONENUM_H
#include <string>
using namespace std;
enum class Direction {
    NORTH,
    SOUTH,
    EAST,
    WEST
};
namespace DirectionUtils{
    Direction stringToDirection(const string& str);
}

#endif // DIRECTIONENUM_H
