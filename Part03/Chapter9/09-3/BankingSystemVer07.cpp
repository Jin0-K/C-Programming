/*
* Software Version: Banking System Ver 0.7
*
* File Name : BankingSystemMain.cpp
* Writer : Jinyoung Kim
* Update Info : [2024, 02, 16] file version 0.7
*/

#include "BankingCommonDecl.h"
#include "AccountHandler.h"


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
