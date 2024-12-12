#include "Account.h"

Account::Account(std::string name, double balance)
    : name{name}, balance{balance} { 
    }
bool Account::deposit(double amount) {
    if (amount < 0)
        return false;
    else {
        balance += amount;
        return true; 
    }
}
bool Account::withdraw(double amount) {
    if (balance-amount >= 0) {
        balance -=amount;
        return true;
    } else
        return false; 
}

// Implement the overloaded operator below this line
std::ostream &operator<<(std::ostream &os, const Account &account) {
    os << "Account Name " << account.name << "Account Balance" << account.balance << std::endl; 
    return os; 
}
// Implement the overloaded operator above this line

