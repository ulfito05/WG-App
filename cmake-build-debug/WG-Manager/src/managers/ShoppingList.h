#pragma once
#include <vector>
#include "interfaces/IShoppingList.h"
#include "../model/ShoppingItem.h"
#include "../model/Person.h"

class ShoppingList : public IShoppingList {
private:
    std::vector<ShoppingItem> items;
    std::vector<Person*> persons;

public:
    void registerPerson(Person* p);

    void addItem(const ShoppingItem& item) override;
    void markBought(int itemId, double price, int buyerId) override;
    std::vector<ShoppingItem> getItems() const override;
};
