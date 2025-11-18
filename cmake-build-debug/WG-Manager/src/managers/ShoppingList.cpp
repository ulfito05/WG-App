#include "ShoppingList.h"

void ShoppingList::registerPerson(Person* p) {
    persons.push_back(p);
}

void ShoppingList::addItem(const ShoppingItem& item) {
    items.push_back(item);
}

void ShoppingList::markBought(int itemId, double price, int buyerId) {
    for (auto& i : items) {
        if (i.getId() == itemId) {
            for (auto* p : persons) {
                if (p->getId() == buyerId) {
                    i.markBought(price, p);
                    return;
                }
            }
        }
    }
}

std::vector<ShoppingItem> ShoppingList::getItems() const {
    return items;
}
