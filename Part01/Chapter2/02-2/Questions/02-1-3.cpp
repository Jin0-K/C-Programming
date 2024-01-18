#include <iostream>

using std::cout;
using std::endl;

void SwapPointer(int *n1, int *n2) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int main(void) {
    int num1 = 5;
    int *ptr1 = &num1;
    int num2 = 10;
    int *ptr2 = &num2;

    SwapPointer(ptr1, ptr2);

    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;

    return 0;
}