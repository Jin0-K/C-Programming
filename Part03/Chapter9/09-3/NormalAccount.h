/*
* File Name : NormalAccount.h
* Writer : Jinyoung Kim
* Update Info : [2024, 02, 16] file version 0.7
*/

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

class NormalAccount : public Account {
private :
    double interest_rate;
public :
    NormalAccount(unsigned int ID, string name, int balance, double interest_rate)
        : Account(ID, name, balance), interest_rate(interest_rate) {}

    double getInterestRate() const {
        return interest_rate;
    }
    virtual int deposit(int amount) {
        modBalance(amount * (1 + interest_rate));
        return this->getBalance();
    }
    virtual void showAccountInfo() const {
        Account::showAccountInfo();
        cout << "Interest Rate: " << (this->getInterestRate())*100 << "%" << endl;
    }
};

#endif