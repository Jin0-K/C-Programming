#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Printer {
private :
    string str;
public :
    void SetString(string str_input);
    void ShowString(void);
};

int main(void) {
    Printer pnt;
    pnt.SetString("Hello World!");
    pnt.ShowString();

    pnt.SetString("I love C++");
    pnt.ShowString();

    return 0;
}

void Printer::SetString(string str_input) {
    str = str_input;
}

void Printer::ShowString(void) {
    cout << str << endl;
}