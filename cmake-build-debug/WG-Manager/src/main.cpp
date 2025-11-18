#include <iostream>
#include "model/WG.h"
#include "model/ShoppingItem.h"

int main() {
    WG wg("Hausgemeinschaft");

    Person* alice = wg.createPerson("Alice", true);  // admin
    Person* bob   = wg.createPerson("Bob");
    wg.printResidents();
    wg.createRoom("Küche");
    wg.createRoom("Bad");
    wg.printRooms();
    auto* t1 = wg.getTaskManager().createTask("Bad putzen", "Einmal pro Woche");
    auto* t2 = wg.getTaskManager().createTask("Einkaufen gehen");


}