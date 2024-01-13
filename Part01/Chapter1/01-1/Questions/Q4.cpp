#include <iostream>

int main(void) {
    int base_salary = 50;
    int selling_price;

    while (1) {
        std::cout << "Enter Selling price in 10k units (-1 to end): ";
        std::cin >> selling_price;
        if (selling_price == -1) {
            break;
        }

        std::cout << "This month's salary: " << base_salary + selling_price*0.12 << "man won" << std::endl;

    }

    std::cout << "End Prgram" << std::endl;

    return 0;
}