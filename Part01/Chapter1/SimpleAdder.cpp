#include <iostream>

int main(void) {
    double val1;
    std::cout<<"Enter first number: ";
    std::cin>>val1;

    double val2;
    std::cout<<"Enter second number: ";
    std::cin>>val2;

    double result = val1 + val2;
    std::cout<<"Addition Result: "<<result<<std::endl;

    return 0;
}