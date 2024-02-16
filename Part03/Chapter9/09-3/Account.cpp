/*
* File Name : Account.cpp
* Writer : Jinyoung Kim
* Update Info : [2024, 02, 16] file version 0.7
*/

#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(unsigned int ID, string name, int balance)
    :ID(ID), name(name), balance(balance) {}

Account::Account(const Account &ref)
    : ID(ref.ID), name(ref.name), balance(ref.balance) {}

unsigned int Account::getID() const {
    return ID;
}
string Account::getName() const {
    return name;
}
int Account::getBalance() const {
    return balance;
}
int Account::modBalance(int amount) {
    if (this->balance + amount < 0) {
        return -1;
    }
    this->balance += amount;
    return this->balance;
}
void Account::showAccountInfo() const {
    cout << "ID: " << this->getID() << endl;
    cout << "Name: " << this->getName() << endl;
    cout << "Balance: " << this->getBalance() << endl;
}
