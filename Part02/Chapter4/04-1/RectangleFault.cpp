#include <iostream>

using namespace std;

class Point {
public :
    int x;  // should be between 0 and 100
    int y;  // should be between 0 and 100
};

class Rectangle {
public :
    Point upLeft;
    Point lowRight;
public :
    void ShowRecInfo() {
        cout << "Top Left: " << '[' << upLeft.x << ", ";
        cout << upLeft.y << ']' << endl;
        cout << "Bottom Right: " << '[' << lowRight.x << ", ";
        cout << lowRight.y << ']' << endl << endl;

    }
};

int main(void) {
    Point pos1 = {-2, 4};
    Point pos2 = {5, 9};
    Rectangle rec = {pos2, pos1};
    rec.ShowRecInfo();

    return 0;
}