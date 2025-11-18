#pragma once
#include <vector>
#include "interfaces/IShoppingList.h"
#include "interfaces/IFinanceManager.h"
#include "../model/ShoppingItem.h"
#include "../model/Person.h"

class ShoppingList : public IShoppingList {
private:
    std::vector<ShoppingItem> items;
    std::vector<Person*> persons;
    IFinanceManager* financeManager;

public:
    ShoppingList();

    void registerPerson(Person* p);
    void connectFinanceManager(IFinanceManager* fm);

    void addItem(const ShoppingItem& item) override;
    void markBought(int itemId, double price, int buyerId) override;
    std::vector<ShoppingItem> getItems() const override;
};
