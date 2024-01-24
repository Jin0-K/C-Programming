#include <iostream>
#include "Rectangle.h"

using namespace std;

bool Rectangle::InitMembers(const Point &ul, const Point &lr) {
    if ((ul.GetX() > lr.GetX()) || (ul.GetY() > lr.GetY())) {
        cout << "Wrong coordination input" << endl;
        return false;
    }
    upLeft = ul;
    lowRight = lr;

    return true;
}

void Rectangle::ShowRecInfo() const {
    cout << "Top Left: " << '[' << upLeft.GetX() << ", ";
    cout << upLeft.GetY() << ']' << endl;
    cout << "Bottom Right: " << '[' << lowRight.GetX() << ", ";
    cout << lowRight.GetY() << ']' << endl << endl;
}