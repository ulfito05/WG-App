#include "Expense.h"

Expense::Expense(Person* payer, double amount, const std::string& reason)
    : payer(payer), amount(amount), reason(reason) {}

Person* Expense::getPayer() const {
    return payer;
}

double Expense::getAmount() const {
    return amount;
}

const std::string& Expense::getReason() const {
    return reason;
}
