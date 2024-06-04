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
#include "Room.h"
#include "item.h"
#include"enemy.h"
using namespace std;

class ZorkUL {
private:

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
	void printHelp();
    void displayItems();
    ZorkUL();
public:
    static ZorkUL& getInstance();
    string go(Direction direction);
    friend class MainWindow;

};

#endif /*ZORKUL_H_*/
