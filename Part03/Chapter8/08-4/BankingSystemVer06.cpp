#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

// Constant Variable
namespace constvar {
    const int MENU_OPTION_NUM = 5;
    const int CUSTOMER_NAME_LEN = 20;
    const int MAX_ACC_NUM = 100;
}

using namespace constvar;

// Credit Level
enum {
    LEVEL_A = 7,
    LEVEL_B = 4,
    LEVEL_C = 2
};

// Account Class
class Account {
private :
    unsigned int ID;
    string name;
    int balance;
public :
    Account()
        : ID(0), name("_"), balance(0) {}

    Account(unsigned int ID, string name, int balance)
        :ID(ID), name(name), balance(balance) {}

    Account(Account &ref)
        : ID(ref.ID), name(ref.name), balance(ref.balance) {}
    
    unsigned int getID() const {
        return ID;
    }
    string getName() const {
        return name;
    }
    int getBalance() const {
        return balance;
    }
    int modBalance(int amount) {
        if (this->balance + amount < 0) {
            return -1;
        }
        this->balance += amount;
        return this->balance;
    }
    virtual int deposit(int amount) = 0;
    virtual void showAccountInfo() const {
        cout << "ID: " << this->getID() << endl;
        cout << "Name: " << this->getName() << endl;
        cout << "Balance: " << this->getBalance() << endl;
    }
};

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

// Control Class
class AccountHandler {
private :
    Account *accounts[MAX_ACC_NUM];
    int account_num;

public :
    AccountHandler() 
        : account_num(0) {}
    ~AccountHandler() {
        for (int i = 0; i < getAccountNum(); ++i) {
            delete accounts[i];
        }
    }

    void printMenu(void) const;
    int getMenuOption(void) const;
    int createAccount(void);
    int isIdIn(unsigned int id) const;
    int deposit(void);
    int withdraw(void);
    void printAllAccounts(void) const;
    int getAccountNum(void) const {
        return account_num;
    }
    int addAccount(void) {
        return ++account_num;
    }
};

// Main Function
int main(void) {
    int option;
    int exit = 0;
    AccountHandler manager;

    while (!exit) {
        manager.printMenu();
        option = manager.getMenuOption();
        // If the user input wrong range of number
        if (option == -1) {
            cout << "You have entered wrong range of option number" << endl;
            continue;
        }
        cout << endl;

        switch (option) {
            case 1 :
                manager.createAccount();
                break;

            case 2 :
                manager.deposit();
                break;

            case 3 :
                manager.withdraw();
                break;

            case 4 :
                manager.printAllAccounts();
                break;

            case 5 :
                exit = 1;
                break;

            default :
                break;
        }
        cout << endl;
    }
    
    return 0;
}


// Function Implementation
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