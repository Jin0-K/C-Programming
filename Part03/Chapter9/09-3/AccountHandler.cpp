/*
* File Name : AccountHandler.cpp
* Writer : Jinyoung Kim
* Update Info : [2024, 02, 16] file version 0.7
*/

#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

using std::cin;

AccountHandler::AccountHandler() 
    : account_num(0) {}
AccountHandler::~AccountHandler() {
    for (int i = 0; i < getAccountNum(); ++i) {
        delete accounts[i];
    }
}

void AccountHandler::printMenu(void) const {
    cout << "-----Menu-----" << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Print All Account Info" << endl;
    cout << "5. End Program" << endl;
}

int AccountHandler::getMenuOption(void) const {
    int option;
    cout << "You Choose: ";
    cin >> option;

    // wrong input range
    if (option < 0 || option > MENU_OPTION_NUM) {
        return -1;
    }

    return option;
}

int AccountHandler::createAccount(void) {
    unsigned int id;
    string name;
    int balance;
    int acc_type;
    double interest;

    cout << "[Create Account]" << endl;

    cout << "<Choose the type of the Account>" << endl;
    cout << "1. Normal Account   2. High Credit Account" << endl;
    cin >> acc_type;
    acc_type %= 2;

    if (acc_type) {
        cout << "<Create Normal Account>" << endl;
    }
    else {
        cout << "<Create High Credit Account>" << endl;
    }

    while (1) {
        cout << "Account ID: ";
        cin >> id;
        if (isIdIn(id) >= 0) {
            cout << "Duplicated ID Input. Please try another one." << endl;
            continue;
        }
        break;
    }
    
    cout << "Name: ";
    cin >> name;
    
    cout << "Balance: ";
    cin >> balance;

    cout << "Interest Rate: ";
    cin >> interest;
    interest *= 0.01;

    if (acc_type == 1) {
        accounts[getAccountNum()] = new NormalAccount(id, name, balance, interest);
    }
    else {
        int credit;
        cout << "Credit Level(1toA, 2toB, 3toC): ";
        cin >> credit;
        switch (credit)
        {
        case 1:
            credit = LEVEL_A;
            break;
        case 2:
            credit = LEVEL_B;
            break;
        case 3:
            credit = LEVEL_C;
            break;
        
        default:
            cout << "Wrong Input" << endl;
            return -1;
        }
        accounts[getAccountNum()] = new HighCreditAccount(id, name, balance, interest, credit);
    }

    addAccount();

    return 1;
}

int AccountHandler::isIdIn(unsigned int id) const {
    int i = 0;
    while (i < getAccountNum()) {
        if (id == accounts[i]->getID()) {
            return i;
        }
        i++;
    }
    return -1;
}

int AccountHandler::deposit(void) {
    unsigned int id;
    int amount;
    int pos;

    // Get input
    cout << "[Deposit]" << endl;
    cout << "ID: ";
    cin >> id;
    cout << "Deposit Amount: ";
    cin >> amount;

    // If the ID doesn't exist
    if ((pos = isIdIn(id)) == -1) {
        cout << "No such ID available. Unable to Deposit." << endl;
        return -1;
    }

    accounts[pos]->deposit(amount);
    cout << "Deposit Complete" << endl;

    return 1;
}

int AccountHandler::withdraw(void) {
    unsigned int id;
    int amount;
    int pos;
    int bal_left;

    // Get input
    cout << " [Withdraw]" << endl;
    cout << "ID: ";
    cin >> id;
    cout << "Withdraw amount: ";
    cin >> amount;

    // If the ID doesn't exist
    if ((pos = isIdIn(id)) == -1) {
        cout << "No such ID available. Unable to Withdraw." << endl;
        return -1;
    }

    // If there is not enough withdraw amount
    if ((bal_left = (*accounts + pos)->modBalance(amount*(-1))) < 0) {
        cout << "Not enough balance in the account. Unable to Withdraw." << endl;
        return -1;
    }
    cout << "Withdraw Complete" << endl;
    cout << "Current Balance: " << bal_left << endl;

    return bal_left;
}

void AccountHandler::printAllAccounts(void) const {
    for (int i = 0; i < getAccountNum(); i++) {
        accounts[i]->showAccountInfo();
        cout << endl;
    }
}
int AccountHandler::getAccountNum(void) const {
    return account_num;
}
int AccountHandler::addAccount(void) {
    return ++account_num;
}
