#pragma once
#include <vector>

class ShoppingItem;

class IShoppingList {
public:
    virtual void addItem(const ShoppingItem& item) = 0;
    virtual void markBought(int itemId, double price, int buyerId) = 0;
    virtual std::vector<ShoppingItem> getItems() const = 0;

    virtual ~IShoppingList() = default;
};
