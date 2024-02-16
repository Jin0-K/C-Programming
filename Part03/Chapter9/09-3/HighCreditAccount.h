/*
* File Name : HighCreditAccount.h
* Writer : Jinyoung Kim
* Update Info : [2024, 02, 16] file version 0.7
*/

#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "NormalAccount.h"
#include "BankingCommonDecl.h"

class HighCreditAccount : public NormalAccount {
private :
    int credit;
public :
    HighCreditAccount(unsigned int ID, string name, int balance, double interest_rate, int credit)
        : NormalAccount(ID, name, balance, interest_rate) {
        this->credit = credit;
    }
    char getCreditLevel() const {
        switch (credit)
        {
        case LEVEL_A:
            return 'A';
        case LEVEL_B:
            return 'B';
        case LEVEL_C:
            return 'C';
        default:
            return 'N';
        }
    }
    virtual int deposit(int amount) {
        modBalance(amount * (1 + getInterestRate() + 0.01 * credit));
        cout << amount * (1 + getInterestRate() + 0.01 * credit) << endl;
        return this->getBalance();
    }
    virtual void showAccountInfo() const {
        NormalAccount::showAccountInfo();
        cout << "Credit Level: " << this->getCreditLevel() << endl;
    }
};

#endif