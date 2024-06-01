#ifndef EXIT_H
#define EXIT_H
#include <string>
using std::string;
struct Exit
{
    string direction;
    int targetRoomID;
private:
    bool isLocked;

public:
    Exit(const string& direction, int targetRoomID, bool isLocked)
        : direction(direction), targetRoomID(targetRoomID), isLocked(isLocked) {}

    bool getIsLocked() const { return isLocked; }
    void setIsLocked(bool value) { isLocked = value; }
};
#endif // EXIT_H
