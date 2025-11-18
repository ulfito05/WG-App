#pragma once
#include <vector>
#include <string>
#include "Person.h"
#include "Room.h"
#include "../managers/TaskManager.h"
#include "../managers/ShoppingList.h"
#include "../managers/FinanceManager.h"

class WG {
private:
    std::string name;
    std::vector<Person> residents;
    std::vector<Room> rooms;

    TaskManager taskManager;
    ShoppingList shoppingList;
    FinanceManager financeManager;

public:
    WG(const std::string& name);

    const std::string& getName() const;

    void addPerson(const Person& person);
    void addRoom(const Room& room);

    TaskManager& getTaskManager();
    ShoppingList& getShoppingList();
    FinanceManager& getFinanceManager();
};
