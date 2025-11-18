#include "WG.h"
#include <iostream>

WG::WG(const std::string& name)
    : name(name)
{
    // Managers verknüpfen
    shoppingList.connectFinanceManager(&financeManager);
}

const std::string& WG::getName() const {
    return name;
}

Person* WG::createPerson(const std::string& name, bool isAdmin) {
    residents.emplace_back(nextPersonId++, name, isAdmin);
    Person* p = &residents.back();

    taskManager.registerPerson(p);
    shoppingList.registerPerson(p);
    financeManager.registerPerson(p);

    return p;
}

Person* WG::getPersonById(int id) {
    for (auto& p : residents) {
        if (p.getId() == id) return &p;
    }
    return nullptr;
}

Room* WG::createRoom(const std::string& name) {
    rooms.emplace_back(name);
    return &rooms.back();
}

Room* WG::getRoomByName(const std::string& name) {
    for (auto& r : rooms) {
        if (r.getName() == name) return &r;
    }
    return nullptr;
}


void WG::printResidents() const {
    std::cout << "Residents in " << name << ":" << std::endl;
    for (const auto& p : residents) {
        std::cout << " - ID: " << p.getId()
                  << ", Name: " << p.getName()
                  << ", Admin: " << (p.getIsAdmin() ? "yes" : "no")
                  << std::endl;
    }
}

void WG::printRooms() const {
    std::cout << "Rooms in " << name << ":" << std::endl;
    for (const auto& r : rooms) {
        std::cout << " - " << r.getName() << std::endl;
    }
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
