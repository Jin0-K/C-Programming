#include <iostream>

using std::cout;
using std::endl;

void numIncrement(int &num) {
    num++;
}

void signConversion(int &num) {
    num *= -1;
}

int main(void) {
    int num = 0;
    int &ref = num;

    cout << num << ' ';
    for (int i = 0; i < 3; i++) {
        numIncrement(ref);
        cout << num << ' ';
    }
    cout << endl;

    signConversion(ref);
    cout << num << endl;

    return 0;
}