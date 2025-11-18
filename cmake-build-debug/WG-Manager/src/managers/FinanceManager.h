#pragma once
#include <vector>
#include "interfaces/IFinanceManager.h"
#include "../model/Expense.h"
#include "../model/Person.h"

class FinanceManager : public IFinanceManager {
private:
    std::vector<Expense> expenses;
    std::vector<Person*> persons;

public:
    void registerPerson(Person* p);

    void addExpense(const Expense& expense) override;
    double calculateBalanceForPerson(int personId) const override;
    std::vector<Expense> getExpenses() const override;

    double getTotalExpenses() const;
    double getNetBalance(int personId) const;
};
