#include "Room.h"
//#include "Command.h"
#include <map>
#include <stdexcept>
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
void Room::setExits(Exit *north, Exit *east, Exit *south, Exit*west) {
	if (north != NULL)
        exits[Direction::NORTH] = north;
	if (east != NULL)
        exits[Direction::EAST] = east;
	if (south != NULL)
        exits[Direction::SOUTH] = south;
	if (west != NULL)
        exits[Direction::WEST] = west;
}


void Room::addItem(Item *inItem) {
    //cout <<endl;
    //cout << "Just added" + inItem->getLongDescription();
    itemsInRoom.push_back(*inItem);
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


