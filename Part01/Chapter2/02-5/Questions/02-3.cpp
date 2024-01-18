#include <iostream>

using std::cout;
using std::endl;
using std::cin;

typedef struct __Point {
    int xpos;
    int ypos;
} Point;

Point &PntAdder(const Point &p1, const Point &p2);

int main(void) {
    Point *p1 = new Point;
    Point *p2 = new Point;

    cout << "Enter x coordination of p1: ";
    cin >> p1->xpos;
    cout << "Enter y coordination of p1: ";
    cin >> p1->ypos;

    cout << "Enter x coordination of p2: ";
    cin >> p2->xpos;
    cout << "Enter y coordination of p2: ";
    cin >> p2->ypos;

    Point &point_added = PntAdder(*p1, *p2);

    cout << "x coordination of the result: " << point_added.xpos << endl;
    cout << "y coordination of the result: " << point_added.ypos << endl;
    
    return 0;
}

Point &PntAdder(const Point &p1, const Point &p2) {
    Point *result = new Point;
    result->xpos = p1.xpos + p2.xpos;
    result->ypos = p1.ypos + p2.ypos;

    return *result;
}