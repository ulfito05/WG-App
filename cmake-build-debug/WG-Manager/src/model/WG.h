#pragma once
#include <vector>
#include <string>
#include <list>
#include "Person.h"
#include "Room.h"
#include "../managers/TaskManager.h"
#include "../managers/ShoppingList.h"
#include "../managers/FinanceManager.h"

class WG {
private:
    std::string name;
    std::list<Person> residents;
    std::list<Room> rooms;

    TaskManager taskManager;
    ShoppingList shoppingList;
    FinanceManager financeManager;

    int nextPersonId = 1;
    int nextRoomId = 1;
    int nextTaskId = 1;        // wird später im TaskManager genutzt
    int nextItemId = 1;        // ShoppingList


public:
    WG(const std::string& name);

    const std::string& getName() const;

    Person* createPerson(const std::string& name, bool isAdmin = false);
    Person* getPersonById(int id);

    Room* createRoom(const std::string& name);
    Room* getRoomByName(const std::string& name);

    void printResidents() const;
    void printRooms() const;


    TaskManager& getTaskManager();
    ShoppingList& getShoppingList();
    FinanceManager& getFinanceManager();


};
