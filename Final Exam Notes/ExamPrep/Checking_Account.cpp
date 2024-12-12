#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance) 
    : Account{name, balance} {
    }

bool Checking_Account::deposit(double amount) {
    return Account::deposit(amount);
}

bool Checking_Account::withdraw(double amount) {
    return Account::withdraw(amount + Checking_Account::per_check_fee);
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &account){
    os << static_cast<const Account&>(account); 
    os << "Per Check Fee " << account.per_check_fee; 
    return os; 
}