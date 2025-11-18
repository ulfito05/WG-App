#pragma once
#include <vector>
#include "interfaces/IFinanceManager.h"
#include "../model/Expense.h"

class FinanceManager : public IFinanceManager {
private:
    std::vector<Expense> expenses;

public:
    void addExpense(const Expense& expense) override;
    double calculateBalanceForPerson(int personId) const override;
    std::vector<Expense> getExpenses() const override;
};
