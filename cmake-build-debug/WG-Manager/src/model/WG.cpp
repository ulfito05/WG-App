#include "WG.h"

WG::WG(const std::string& name)
    : name(name) {}

const std::string& WG::getName() const {
    return name;
}

void WG::addPerson(const Person& person) {
    residents.push_back(person);

    // Manager müssen Personen kennen
    taskManager.registerPerson(&residents.back());
    shoppingList.registerPerson(&residents.back());
}

void WG::addRoom(const Room& room) {
    rooms.push_back(room);
}

TaskManager& WG::getTaskManager() { return taskManager; }
ShoppingList& WG::getShoppingList() { return shoppingList; }
FinanceManager& WG::getFinanceManager() { return financeManager; }
