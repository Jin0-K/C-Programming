#include <iostream>

using std::cout;
using std::endl;

class Calculator {
private :
    int add, min, mul, div;
public :
    void Init(void);
    double Add(double num1, double num2);
    double Min(double num1, double num2);
    double Mul(double num1, double num2);
    double Div(double num1, double num2);
    void ShowOpCount(void);
};

int main(void) {
    Calculator cal;
    cal.Init();
    cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
    cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
    cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
    cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
    cal.ShowOpCount();

    return 0;
}

inline void Calculator::Init(void) {
    add = 0;
    min = 0;
    mul = 0;
    div = 0;
}

inline double Calculator::Add(double num1, double num2) {
    add++;
    return num1 + num2;
}

inline double Calculator::Min(double num1, double num2) {
    min++;
    return num1 - num2;
}

inline double Calculator::Mul(double num1, double num2) {
    mul++;
    return num1 * num2;
}

inline double Calculator::Div(double num1, double num2) {
    div++;
    return num1 / num2;
}

void Calculator::ShowOpCount(void) {
    cout << "Addition: " << add << " ";
    cout << "Minus: " << min << " ";
    cout << "Multiplication: " << mul << " ";
    cout << "Division: " << div << endl;
}
