#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "item.h"
#include "exit.h"
using namespace std;
using std::vector;
enum class Direction {
    NORTH,
    SOUTH,
    EAST,
    WEST
};
class Room {

private:
    //int id;
    string name;
	string description;
    map<Direction,Exit*> exits;
	string exitString();
    vector <Item> itemsInRoom;


public:
    int numberOfItems();
    Room(string name,string description);
    void setExits(Exit *north, Exit *east, Exit *south, Exit *west);
    string getName() const;
    string getDescription() const;
    //int getId() const;
    Room* nextRoom(Direction direction);
    //should add copy of item to room, enables multiple items of same type
    void addItem(Item *inItem);
    string displayItem();
    int isItemInRoom(string inString);
    void removeItemFromRoom(int location);
    //void setName(const string &newName);
};
#endif
