#include "Room.h"
//#include "Command.h"
#include <map>
#include <stdexcept>
#include <iostream>
using namespace std;
Direction stringToDirection(const string& str) {
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

Room::Room(/*int id,*/string name,string description) {
    //this->id = id;
    this-> name = name;
    this->description = description;
}
void Room::setExits(unique_ptr<Exit> north, unique_ptr<Exit>east, unique_ptr<Exit>south, unique_ptr<Exit>west) {
    if (north != NULL) exits[Direction::NORTH] = std::move(north);
    if (east != NULL) exits[Direction::EAST] = std::move(east);
    if (south != NULL) exits[Direction::SOUTH] = std::move(south);
    if (west != NULL) exits[Direction::WEST] = std::move(west);
}


void Room::addItem(Item *inItem) {
    //cout <<endl;
    cout << "Just added " + inItem->getName()<<" to "<<this->name<<endl;
    //itemsInRoom.push_back(*inItem);
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
            tempString = tempString + itemsInRoom[x].getName() + "  " ;
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
            int tempFlag = inString.compare( itemsInRoom[x].getName());
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
        cout<<"Target room:"<<it->second->targetRoom->getName()<<endl;
    }
}
/*string Room::shortDescription() {
	return description;
}

string Room::longDescription() {
	return "room = " + description + ".\n" + displayItem() + exitString();
}*/

/*string Room::exitString() {
	string returnString = "\nexits =";
	for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
		// Loop through map
		returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
	return returnString;
}*/
/*
Room* Room::nextRoom(string direction) {
	map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
	if (next == exits.end())
		return NULL; // if exits.end() was returned, there's no room in that direction.
	return next->second; // If there is a room, remove the "second" (Room*)
				// part of the "pair" (<string, Room*>) and return it.
}*/


