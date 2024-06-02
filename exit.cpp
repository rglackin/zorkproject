#include "exit.h"
using namespace std;

Exit::Exit( Room* targetRoom, bool isLocked)
    :  targetRoom(targetRoom), isLocked(isLocked) {}
bool Exit::getIsLocked() const { return isLocked; }
void Exit::setIsLocked(bool value) { isLocked = value; }
void Exit::unlock(){setIsLocked(false);}
