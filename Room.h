#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include <memory>
#include "item.h"
#include "exit.h"
#include "enemy.h"
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
    map<Direction,unique_ptr<Exit>> exits;
	string exitString();
    vector <Item*> itemsInRoom;
    vector <Enemy*> enemiesInRoom;


public:
    int numberOfItems();
    Room(string name,string description);
    void setExits(unique_ptr<Exit> north, unique_ptr<Exit>east,unique_ptr<Exit>south, unique_ptr<Exit>west);
    string getName() const;
    string getDescription() const;
    //int getId() const;
    Room* nextRoom(Direction direction);
    //should add copy of item to room, enables multiple items of same type
    void addItem(Item *inItem);
    void addEnemy(Enemy *inEnemy);
    string displayItem();
    int isItemInRoom(string inString);
    void removeItemFromRoom(int location);
    void printExits();
    //void setName(const string &newName);
};
#endif
