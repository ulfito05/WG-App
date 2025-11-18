#pragma once
#include <string>

class Person;

class ShoppingItem {
private:
    int id;
    std::string name;
    int amount;
    double price;
    bool isBought;
    Person* boughtBy;

public:
    ShoppingItem(int id, const std::string& name, int amount);

    int getId() const;
    const std::string& getName() const;
    int getAmount() const;
    double getPrice() const;
    bool getIsBought() const;
    Person* getBuyer() const;

    void markBought(double priceValue, Person* buyer);
};
