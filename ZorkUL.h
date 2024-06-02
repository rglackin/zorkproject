#ifndef ZORKUL_H_
#define ZORKUL_H_

#include <iostream>
#include <string>
#include<map>
#include <QCoreApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include"enemy.h"
using namespace std;

class ZorkUL {
private:
	Parser parser;
	Room *currentRoom;
    map<int, Room*> roomsMap;
    map<int, Item*> itemMap;
    map<int, Enemy*> enemyMap;
    static QJsonDocument jsonDoc;
    static QJsonObject jsonObject;
    //JSON parsing funcs
    void parseJson();
	void createRooms();
    void createItems();
    void createEnemies();
    void createEffects();
    void createExits();

    template<typename T, typename Func>
    void populateRoom(Room* room, Func func, QJsonArray &array);

	void printWelcome();
	bool processCommand(Command command);
	void printHelp();
	void goRoom(Command command);
    void displayItems();
public:
	ZorkUL();
	void play();
	string go(string direction);
};

#endif /*ZORKUL_H_*/
