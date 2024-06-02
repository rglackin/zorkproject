#include <iostream>
//#include <fstream>
#include <QCoreApplication>
#include <QFile>
#include <QJsonArray>
#include <QDebug>
#include "ZorkUL.h"
#include "Room.h"
#include "itemfactory.h"
#include"effectfactory.h"
#include"globals.h"
#include "exit.h"
#include "enemy.h"

using namespace std;
using std::move;
//using json = nlohmann::json;
map<int, MagicEffect*> effectMap;
QJsonDocument ZorkUL::jsonDoc;
QJsonObject ZorkUL::jsonObject;

int main(int argc, char *argv[]) {


    QCoreApplication a(argc, argv);

	ZorkUL temp;
    //temp.play();
	return 0;
}

ZorkUL::ZorkUL() {
    cout<<"start"<<endl;
    parseJson();
    createEffects();
    createItems();
	createRooms();
    createExits();
    //map debugging
    /*for(auto it = itemMap.begin();it!=itemMap.end();++it){
        cout<<"ID: "<<it->first<<" Name:"<<it->second->getName()<<" Desc:"<<it->second->getDesc()<<endl;
    }*/
    /*for(auto it = roomsMap.begin();it!=roomsMap.end();++it){
        //cout<<"ID: "<<it->first<<" Name:"<<it->second->getName()<<" Desc:"<<it->second->getDesc()<<endl;
        cout<<"RoomID: "<<it->first<<endl;
        it->second->printExits();
    }*/

}
void ZorkUL::parseJson(){
    QString filePath = ":/json/zork.json";
    QFile jsonFile(filePath);
    if (!jsonFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open JSON file at: "<<filePath;
        return;
    }
    QByteArray jsonData = jsonFile.readAll();
    QJsonParseError error;
    jsonDoc = QJsonDocument::fromJson(jsonData, &error);
    if (error.error != QJsonParseError::NoError) {
        qWarning() << "Failed to parse JSON:" << error.errorString();
        return;
    }
    if (!jsonDoc.isObject()) {
        qWarning() << "JSON document is not an object";
        return ;
    }
    jsonObject= jsonDoc.object();
}
void ZorkUL::createRooms()  {
    QJsonArray roomsArray = jsonObject["rooms"].toArray();
    //qDebug()<<"Rooms";
    for (const auto& roomValue : roomsArray) {
        QJsonObject roomObj = roomValue.toObject();
        int id = roomObj["id"].toInt();
        QString name = roomObj["name"].toString();
        QString description = roomObj["description"].toString();
        //qDebug() << "Room:" << description;
        Room newRoom= Room(name.toStdString(),description.toStdString());
        roomsMap[id] = &newRoom;
        QJsonArray items = roomObj["items"].toArray();
        QJsonArray enemies = roomObj["enemies"].toArray();
        //create function pointers
        void(Room::*addItemPtr)(Item*)= &Room::addItem;
        //void(Room::*addEnemyPtr)(Enemy*)= &Room::addEnemy;
        //call populate room using function pointers
        populateRoom<Item>(&newRoom,addItemPtr,items);
    }
    currentRoom = roomsMap[1];
}
void ZorkUL::createEffects(){
    QJsonArray effectArray = jsonObject["effects"].toArray();
    //qDebug()<<"Rooms";
    for (const auto& effectValue : effectArray) {
        QJsonObject effectObj= effectValue.toObject();
        int id = effectObj["id"].toInt();
        effectMap[id]= EffectFactory::createEffect(effectObj);
    }
}
void ZorkUL::createItems(){
    QJsonArray itemsArray = jsonObject["items"].toArray();
    //qDebug()<<"Rooms";
    for (const auto& itemValue : itemsArray) {
        QJsonObject itemObj = itemValue.toObject();
        int id = itemObj["id"].toInt();

        //tries to assign pointer to Item object to id key in itemMap
        try {
            itemMap[id] = ItemFactory::createItem(itemObj);
        }
        //catches invalid item type, item not placed in map
        catch(const invalid_argument& e){
            qDebug()<<"Debug: "<<e.what();
        }
    }
}
void ZorkUL::createExits(){
    QJsonArray roomsArray = jsonObject["rooms"].toArray();
    for (const auto& roomValue : roomsArray) {
        QJsonObject roomObj = roomValue.toObject();
        int id = roomObj["id"].toInt();
        Room* entryRoomPtr = roomsMap[id];
        QJsonArray exitsArray = roomObj["exits"].toArray();
        unique_ptr<Exit> north = nullptr;
        unique_ptr<Exit> east = nullptr;
        unique_ptr<Exit> south = nullptr;
        unique_ptr<Exit> west = nullptr;


        for (const QJsonValue& exitValue : exitsArray) {
            QJsonObject exitObject = exitValue.toObject();
            QString directionString = exitObject["direction"].toString();
            int targetRoomId = exitObject["roomId"].toInt();
            if(targetRoomId==0) continue;
            Room* targetRoomPtr = roomsMap[targetRoomId];
            if (directionString == "north") {
                north = make_unique<Exit>(targetRoomPtr, exitObject["isLocked"].toBool(false));
            } else if (directionString == "east") {
                east = make_unique<Exit>(targetRoomPtr, exitObject["isLocked"].toBool(false));
            } else if (directionString == "south") {
                south = make_unique<Exit>(targetRoomPtr, exitObject["isLocked"].toBool(false));
            } else if (directionString == "west") {
                west = make_unique<Exit>(targetRoomPtr, exitObject["isLocked"].toBool(false));
            }
        }
        entryRoomPtr->setExits(std::move(north),std::move(east),std::move(south),std::move(west));
    }
}
template<typename T, typename Func>
//takes in pointer to room, pointer to func, and array
void ZorkUL::populateRoom(Room* room,Func func, QJsonArray &array){
    //set pointer to map to same type as desired class type
    map<int,T*> *mapPtr = nullptr;
    //set mapPtr to correct map
    if constexpr(std::is_same_v<T*,Item*>)
    {
        mapPtr = &itemMap;
    }
    else if constexpr(std::is_same_v<T*,Enemy*>){
        mapPtr = &enemyMap;
    }
    //iterate through array, add objects to room
    for (const auto& value: array){
        int id= value.toInt();
        T *tPtr = (*mapPtr)[id];
        (room->*func)(tPtr);
    }
}
/*void ZorkUL::populateRoomEnemies(Room &room, QJsonArray &enemies){

}*/
/**
 *  Main play routine.  Loops until end of play.
 */
/*------------------------------REMOVE
void ZorkUL::play() {
	printWelcome();

	// Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the ZorkUL game is over.

	bool finished = false;
	while (!finished) {
		// Create pointer to command and give it a command.
        Command* command = parser.getCommand();
		// Pass dereferenced command and check for end of game.
		finished = processCommand(*command);
		// Free the memory allocated by "parser.getCommand()"
		//   with ("return new Command(...)")
		delete command;
	}
	cout << endl;
	cout << "end" << endl;
}

void ZorkUL::printWelcome() {
    cout << "start"<< endl;
	cout << "info for help"<< endl;
	cout << endl;
    cout << currentRoom->getDescription() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
/*----------------REMOVE
bool ZorkUL::processCommand(Command command) {
	if (command.isUnknown()) {
		cout << "invalid input"<< endl;
		return false;
	}

	string commandWord = command.getCommandWord();
	if (commandWord.compare("info") == 0)
		printHelp();

	else if (commandWord.compare("map") == 0)
		{
        cout << "[h] --- [f] --- [g]" << endl;
		cout << "         |         " << endl;
        cout << "         |         " << endl;
		cout << "[c] --- [a] --- [b]" << endl;
		cout << "         |         " << endl;
		cout << "         |         " << endl;
		cout << "[i] --- [d] --- [e]" << endl;
		}

	else if (commandWord.compare("go") == 0)
		goRoom(command);

    else if (commandWord.compare("take") == 0)
    {
       	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "item is not in room" << endl;
        else{
            cout << "item is in room" << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
            }
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }

    {
    if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }

    else if (commandWord.compare("quit") == 0) {
		if (command.hasSecondWord())
			cout << "overdefined input"<< endl;
		else
			return true; /**signal to quit*/
/*-----------------REMOVE
	}
	return false;
}
/** COMMANDS **/
/*------------------------------REMOVE
void ZorkUL::printHelp() {
	cout << "valid inputs are; " << endl;
	parser.showCommands();

}

void ZorkUL::goRoom(Command command) {
    if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
		return;
	}

	string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

	if (nextRoom == NULL)
		cout << "underdefined input"<< endl;
	else {
		currentRoom = nextRoom;
		cout << currentRoom->longDescription() << endl;
    }
}

string ZorkUL::go(string direction) {
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
		return("direction null");
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
    }
}
------------------------------REMOVE*/
