#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    const int num = 12;
    const int *ptr = &num;
    const int &ref = *ptr;

    cout << "Print by pointer: " << *ptr << endl;
    cout << "Print by reference: " << ref << endl;

    return 0;
}