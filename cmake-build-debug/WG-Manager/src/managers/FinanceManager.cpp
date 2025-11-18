#include "FinanceManager.h"

void FinanceManager::registerPerson(Person* p) {
    persons.push_back(p);
}

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

double FinanceManager::getTotalExpenses() const {
    double total = 0.0;
    for (const auto& e : expenses) {
        total += e.getAmount();
    }
    return total;
}

double FinanceManager::getNetBalance(int personId) const {
    if (persons.empty()) return 0.0;

    double total = getTotalExpenses();
    double equal = total / persons.size();
    double paid = calculateBalanceForPerson(personId);

    return paid - equal;
}
