#include <iostream>

int main(void) {
    char name[10];
    char pnum[20];

    std::cout << "Enter your name: ";
    std::cin >> name;

    std::cout << "Enter your phone number: ";
    std::cin >> pnum;

    std::cout << name << ' ' << pnum << std::endl;

    return 0;
}