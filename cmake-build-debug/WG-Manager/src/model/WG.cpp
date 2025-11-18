#include "WG.h"

WG::WG(const std::string& name)
    : name(name)
{
    // Managers verknüpfen
    shoppingList.connectFinanceManager(&financeManager);
}

const std::string& WG::getName() const {
    return name;
}

void WG::addPerson(const Person& person) {
    residents.push_back(person);

    Person* p = &residents.back();  // pointer bleibt stabil!

    taskManager.registerPerson(p);
    shoppingList.registerPerson(p);
    financeManager.registerPerson(p);
}


void WG::addRoom(const Room& room) {
    rooms.push_back(room);
}

TaskManager& WG::getTaskManager() {
    return taskManager;
}

ShoppingList& WG::getShoppingList() {
    return shoppingList;
}

FinanceManager& WG::getFinanceManager() {
    return financeManager;
}
