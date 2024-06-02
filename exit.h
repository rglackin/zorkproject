#ifndef EXIT_H
#define EXIT_H
#include <string>
//#include "Room.h"
using std::string;


struct Exit
{

    class Room* targetRoom;
private:
    bool isLocked;

public:
    Exit(Room* targetRoom, bool isLocked);
    bool getIsLocked() const;
    void setIsLocked(bool value);
    void unlock();
};
#endif // EXIT_H
