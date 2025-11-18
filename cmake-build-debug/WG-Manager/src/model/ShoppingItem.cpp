#include "ShoppingItem.h"

ShoppingItem::ShoppingItem(int id, const std::string& name, int amount)
        : id(id), name(name), amount(amount),
          price(0.0), isBought(false), boughtBy(nullptr) {}

int ShoppingItem::getId() const { return id; }
const std::string& ShoppingItem::getName() const { return name; }
int ShoppingItem::getAmount() const { return amount; }
double ShoppingItem::getPrice() const { return price; }
bool ShoppingItem::getIsBought() const { return isBought; }
Person* ShoppingItem::getBuyer() const { return boughtBy; }

void ShoppingItem::markBought(double priceValue, Person* buyer) {
    isBought = true;
    price = priceValue;
    boughtBy = buyer;
}
