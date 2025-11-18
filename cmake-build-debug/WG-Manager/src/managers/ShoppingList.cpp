#include "ShoppingList.h"
#include "../model/Expense.h"
#include <stdexcept>

ShoppingList::ShoppingList()
    : financeManager(nullptr) {}

void ShoppingList::registerPerson(Person* p) {
    persons.push_back(p);
}

void ShoppingList::connectFinanceManager(IFinanceManager* fm) {
    financeManager = fm;
}

void ShoppingList::addItem(const ShoppingItem& item) {
    items.push_back(item);
}

void ShoppingList::markBought(int itemId, double price, int buyerId) {
    for (auto& item : items) {
        if (item.getId() == itemId) {

            Person* buyer = nullptr;
            for (auto* p : persons) {
                if (p->getId() == buyerId) {
                    buyer = p;
                    break;
                }
            }

            if (!buyer)
                throw std::runtime_error("ShoppingList: buyerId not found");

            item.markBought(price, buyer);

            if (financeManager) {
                Expense e(buyer, price, "Einkauf: " + item.getName());
                financeManager->addExpense(e);
            }

            return;
        }
    }

    throw std::runtime_error("ShoppingList: itemId not found");
}

std::vector<ShoppingItem> ShoppingList::getItems() const {
    return items;
}
