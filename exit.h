#ifndef EXIT_H
#define EXIT_H
#include <string>
//#include "Room.h"
using std::string;

/*enum class Direction {
    NORTH,
    SOUTH,
    EAST,
    WEST
};*/
struct Exit
{
    //Direction direction;
    class Room* targetRoom;
private:
    bool isLocked ;

public:
    Exit(/*const string& direction,*/ Room* targetRoom, bool isLocked);
    bool getIsLocked() const;
    void setIsLocked(bool value);
    void unlock();
};
#endif // EXIT_H
