#include <iostream>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
using namespace std;

// Displays Account objects in a vector of Account object pointers
void display (const std::vector<Account *> &accounts) {
    std::cout << "\n=== Accounts=============================="
    << std::endl;
    for (const auto acc: accounts)
        std::cout << *acc << std::endl;
}

int main() {

    Account *account_1003 = new Checking_Account("Account_1003", 1000);
    Account *account_1004 = new Savings_Account("Account_1004", 2000);

    account_1003->withdraw(500);  
    cout << *account_1003 << endl; 

    account_1004->deposit(500); 
    cout << *account_1004 << endl; 

    std::vector<Account *> accounts;
    accounts.push_back(account_1003); 
    accounts.push_back(account_1004); 

    display(accounts); 

    delete account_1003;
    delete account_1004;

    return 0; 
}