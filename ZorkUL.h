#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
#include<map>
#include <QCoreApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
using namespace std;

class ZorkUL {
private:
	Parser parser;
	Room *currentRoom;
    map<int, Room*> roomsMap;
    map<int, Item*> itemMap;
    static QJsonDocument jsonDoc;
    static QJsonObject jsonObject;
	void createRooms();
	void printWelcome();
	bool processCommand(Command command);
	void printHelp();
	void goRoom(Command command);
    void createItems();
    void createEnemies();
    void createEffects();
    void createExits();
    void displayItems();
    void parseJson();
public:
	ZorkUL();
	void play();
	string go(string direction);
};

#endif /*ZORKUL_H_*/
