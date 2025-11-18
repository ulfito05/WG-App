#pragma once
#include <string>

class Person;

class Expense {
private:
    Person* payer;
    double amount;
    std::string reason;

public:
    Expense(Person* payer, double amount, const std::string& reason);

    Person* getPayer() const;
    double getAmount() const;
    const std::string& getReason() const;
};
