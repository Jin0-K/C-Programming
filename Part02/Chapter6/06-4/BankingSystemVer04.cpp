#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

// Constant Variable
const int MENU_OPTION_NUM = 5;
const int CUSTOMER_NAME_LEN = 20;
const int MAX_ACC_NUM = 100;

// Account Class
class Account {
private :
    static int account_num;
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

    static int getAccountNum(void) {
        return account_num;
    }
    static int addAccount(void) {
        return ++account_num;
    }
    int modBalance(int amount) {
        if (this->balance + amount < 0) {
            return -1;
        }
        this->balance += amount;
        return this->balance;
    }
};

int Account::account_num = 0;

// Function Declaration
void printMenu(void);
int getMenuOption(void);
int createAccount(void);
int isIdIn(int id);
int deposit(void);
int withdraw(void);
int printAllAccounts(void);

// Static Array
static Account *accounts = new Account[MAX_ACC_NUM];

// Main Function
int main(void) {
    int option;
    int exit = 0;

    while (!exit) {
        printMenu();
        option = getMenuOption();
        // If the user input wrong range of number
        if (option == -1) {
            cout << "You have entered wrong range of option number" << endl;
            continue;
        }
        cout << endl;

        switch (option) {
            case 1 :
                createAccount();
                Account::addAccount();
                break;

            case 2 :
                deposit();
                break;

            case 3 :
                withdraw();
                break;

            case 4 :
                printAllAccounts();
                break;

            case 5 :
                exit = 1;
                break;

            default :
                break;
        }
        cout << endl;
    }
    
    delete []accounts;

    return 0;
}


// Function Implementation
void printMenu(void) {
    cout << "-----Menu-----" << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Print All Account Info" << endl;
    cout << "5. End Program" << endl;
}

int getMenuOption(void) {
    int option;
    cout << "You Choose: ";
    cin >> option;

    // wrong input range
    if (option < 0 || option > MENU_OPTION_NUM) {
        return -1;
    }

    return option;
}

int createAccount(void) {
    unsigned int id;
    string name;
    int balance;

    cout << "[Create Account]" << endl;
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

    accounts[Account::getAccountNum()] = Account(id, name, balance);

    return 1;
}

int isIdIn(int id) {
    unsigned int i = 0;
    while (i < Account::getAccountNum()) {
        if (id == (accounts + i)->getID()) {
            return i;
        }
        i++;
    }
    return -1;
}

int deposit(void) {
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

    (accounts + pos)->modBalance(amount);
    cout << "Deposit Complete" << endl;

    return 1;
}

int withdraw(void) {
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
    if ((bal_left = (accounts + pos)->modBalance(amount*(-1))) < 0) {
        cout << "Not enough balance in the account. Unable to Withdraw." << endl;
        return -1;
    }
    cout << "Withdraw Complete" << endl;
    cout << "Current Balance: " << bal_left << endl;

    return bal_left;
}

int printAllAccounts(void) {
    for (int i = 0; i < Account::getAccountNum(); i++) {
        cout << "ID: " << accounts[i].getID() << endl;
        cout << "Name: " << accounts[i].getName() << endl;
        cout << "Balance: " << accounts[i].getBalance() << endl;
        cout << endl;
    }

    return 1;
}