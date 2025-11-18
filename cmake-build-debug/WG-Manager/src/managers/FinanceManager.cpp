#include "FinanceManager.h"
#include "../model/Person.h"

void FinanceManager::addExpense(const Expense& expense) {
    expenses.push_back(expense);
}

double FinanceManager::calculateBalanceForPerson(int personId) const {
    double sum = 0.0;

    for (const auto& e : expenses) {
        if (e.getPayer()->getId() == personId) {
            sum += e.getAmount();
        }
    }
    return sum;
}

std::vector<Expense> FinanceManager::getExpenses() const {
    return expenses;
}
