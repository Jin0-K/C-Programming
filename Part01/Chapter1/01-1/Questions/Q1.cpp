#include <iostream>

int main(void) {
    int num;
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        std::cout << "Enter integer " << i << ": ";
        std::cin >> num;
        sum += num;
    }
    
    std::cout << "Sum: " << sum << std::endl;

    return 0;
}