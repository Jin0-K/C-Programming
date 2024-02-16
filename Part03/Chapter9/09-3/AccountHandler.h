/*
* File Name : AccountHandler.h
* Writer : Jinyoung Kim
* Update Info : [2024, 02, 16] file version 0.7
*/

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "BankingCommonDecl.h"

class AccountHandler {
private :
    Account *accounts[MAX_ACC_NUM];
    int account_num;

public :
    AccountHandler();
    ~AccountHandler();

    void printMenu(void) const;
    int getMenuOption(void) const;
    int createAccount(void);
    int isIdIn(unsigned int id) const;
    int deposit(void);
    int withdraw(void);
    void printAllAccounts(void) const;
    int getAccountNum(void) const;
    int addAccount(void);
};

#endif