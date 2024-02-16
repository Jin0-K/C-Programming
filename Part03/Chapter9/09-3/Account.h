/*
* File Name : Account.h
* Writer : Jinyoung Kim
* Update Info : [2024, 02, 16] file version 0.7
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Account {
private :
    unsigned int ID;
    string name;
    int balance;
public :
    Account(unsigned int ID, string name, int balance);
    Account(const Account &ref);
    
    unsigned int getID() const;
    string getName() const;
    int getBalance() const;
    int modBalance(int amount);
    virtual int deposit(int amount) = 0;
    virtual void showAccountInfo() const;
};

#endif