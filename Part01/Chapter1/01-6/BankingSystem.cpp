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

// Structure Definition
typedef struct {
    unsigned int ID;
    string name;
    int balance;
} Account;

// Function Declaration
void printMenu(void);
int getMenuOption(void);
int createAccount(void);
int isIdIn(int id);
int deposit(void);
int withdraw(void);
int printAllAccounts(void);

// Static Array
static Account accounts[MAX_ACC_NUM];
static int account_num;

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

        switch (option) {
            case 1 :
                createAccount();
                account_num++;
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
    }
    
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

    cout << "[Create Account]" << endl;
    while (1) {
        cout << "Account ID: ";
        cin >> id;
        if (isIdIn(id) >= 0) {
            cout << "Duplicated ID Input. Please try another one." << endl;
            continue;
        }
        accounts[account_num].ID = id;
        break;
    }
    
    cout << "Name: ";
    cin >> accounts[account_num].name;
    
    cout << "Balance: ";
    cin >> accounts[account_num].balance;

    return 1;
}

int isIdIn(int id) {
    unsigned int i = 0;
    while (i < account_num) {
        if (id == accounts[i].ID) {
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

    accounts[pos].balance += amount;
    cout << "Deposit Complete" << endl;

    return 1;
}

int withdraw(void) {
    unsigned int id;
    int amount;
    int pos;

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
    if (accounts[pos].balance < amount) {
        cout << "Not enough balance in the account. Unable to Withdraw." << endl;
        return -1;
    }

    accounts[pos].balance -= amount;
    cout << "Withdraw Complete" << endl;

    return 1;
}

int printAllAccounts(void) {
    for (int i = 0; i < account_num; i++) {
        cout << "ID: " << accounts[i].ID << endl;
        cout << "Name: " << accounts[i].name << endl;
        cout << "Balance: " << accounts[i].balance << endl;
        cout << endl;
    }

    return 1;
}