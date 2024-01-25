#include <iostream>

using std::cout;
using std::endl;

class Point {
private :
    int xpos, ypos;
public :
    Point(int x, int y) : xpos(x), ypos(y) {}

    void ShowPointInfo() const {
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
};

class Circle {
private :
    Point center;
    int radius;
public :
    Circle(int x, int y, int rad) : center(x, y), radius(rad) {}
    
    Point getCenter(void) const {
        return center;
    }

    int getRadius(void) const {
        return radius;
    }
};

class Ring {
private :
    Circle inner;
    Circle outer;
public :
    Ring(int in_x, int in_y, int in_rad, int out_x, int out_y, int out_rad) 
        : inner(in_x, in_y, in_rad), outer(out_x, out_y, out_rad) {}
    
    void ShowRingInfo(void) const {
        cout << "Inner Circle Info..." << endl;
        cout << "radius: " << inner.getRadius() << endl;
        inner.getCenter().ShowPointInfo();
        cout << "Outer Circle Info..." << endl;
        cout << "radius: " << outer.getRadius() << endl;
        outer.getCenter().ShowPointInfo();
    }
};

int main(void) {
    Ring ring(1, 1, 4, 2, 2, 9);
    ring.ShowRingInfo();

    return 0;
}