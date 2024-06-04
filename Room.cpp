#include "Room.h"
//#include "Command.h"
#include <map>

#include <iostream>
using namespace std;


Room::Room(/*int id,*/string name,string description) {
    //this->id = id;
    this-> name = name;
    this->description = description;
}
void Room::setExits(unique_ptr<Exit> north, unique_ptr<Exit>east, unique_ptr<Exit>south, unique_ptr<Exit>west) {
    if (north != nullptr){

        exits[Direction::NORTH] = std::move(north);
    }

    if (east != nullptr) {
        exits[Direction::EAST] = std::move(east);
    }
    if (south != nullptr){
        exits[Direction::SOUTH] = std::move(south);
    }
    if (west != nullptr){
        exits[Direction::WEST] = std::move(west);
    }
}


void Room::addItem(Item *inItem) {
    //cout <<endl;
    //cout << "Just added " + inItem->getName()<<" to "<<this->name<<endl;
    //using clone copies items while ensuring they dont get sliced(lose their subclass data)
    Item *copyItem = inItem->clone();
    //cout<<copyItem->toString()<<endl;
    itemsInRoom.push_back(copyItem);
}
void Room::addEnemy(Enemy *inEnemy){
    Enemy *copyEnemy = new Enemy(*inEnemy);
    enemiesInRoom.push_back(copyEnemy);
}
string Room::displayItem() {
    string tempString = "items in room = ";
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        tempString = "no items in room";
    }
    else if (itemsInRoom.size() > 0) {
        int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            tempString = tempString + itemsInRoom[x]->getName() + "  " ;
            x++;
        }
    }
    return tempString;
}

/*int Room::getId() const
{
    return id;
}*/

string Room::getName()const
{
    return name;
}

string Room::getDescription() const
{
    return description;
}

int Room::numberOfItems() {
    return itemsInRoom.size();
}

int Room::isItemInRoom(string inString)
{
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        return false;
    }
    else if (itemsInRoom.size() > 0) {
        int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( itemsInRoom[x]->getName());
            if (tempFlag == 0) {
                itemsInRoom.erase(itemsInRoom.begin()+x);
                return x;
            }
            x++;
        }
    }
    return -1;
}
void Room::printExits(){
    for (auto it = exits.begin(); it!= exits.end(); ++it) {
        cout<<"Target room:"<<it->second->targetRoom->getName()<<" Locked:"<<it->second->getIsLocked()<<endl;
    }
}

Room* Room::nextRoom(Direction d, string& msg) {
    //check if exit exists
    auto it =exits.find(d);
    if(it != exits.end()){
        if(!it->second->getIsLocked()){
            return it->second->targetRoom;
        }
        else{
            msg = "This exit is locked. Look for a key to open it";
        }
    }
    else{
        msg = "There is no exit in this direction.\nWhy are you walking into a wall?";
    }
    return nullptr;
}
Enemy* Room::getEnemy(){
    return enemiesInRoom[0];
}



