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

public:
    WG(const std::string& name);

    const std::string& getName() const;

    void addPerson(const Person& person);
    void addRoom(const Room& room);

    // 🔥 DIESE 3 METHODEN FEHLTEN!!!
    TaskManager& getTaskManager();
    ShoppingList& getShoppingList();
    FinanceManager& getFinanceManager();
};
