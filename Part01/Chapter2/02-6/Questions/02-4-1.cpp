#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::cin;

int main(void) {
    char *str1 = "Hello there!";
    char *str2 = "It's me.";
    char str3[30];

    cout << "Length of str1: " << strlen(str1) << endl;
    cout << "Length of str2: " << strlen(str2) << endl;

    strcpy(str3, str1);

    cout << "Copied str1 to str3: " << str3 << endl;

    strcat(str3, str2);

    cout << "Concatenated str3 and str2: " << str3 << endl;

    cout << "Compared str1 and str2: " << strcmp(str1, str2) << endl;

    return 0;
}