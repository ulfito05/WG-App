#pragma once
#include <vector>

class Expense;

class IFinanceManager {
public:
    virtual void addExpense(const Expense& expense) = 0;
    virtual double calculateBalanceForPerson(int personId) const = 0;
    virtual std::vector<Expense> getExpenses() const = 0;

    virtual ~IFinanceManager() = default;
};
