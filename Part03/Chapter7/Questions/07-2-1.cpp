#include <iostream>

using std::cout;
using std::endl;

class Rectangle {
private :
    int width;
    int height;
public :
    Rectangle(int width, int height)
        : width(width), height(height) {}

    void ShowAreaInfo() {
        cout << "Area: " << width*height << endl;
    }
};

class Square : public Rectangle {
public :
    Square(int length)
        : Rectangle(length, length) {}
};

int main(void) {
    Rectangle rec(4, 3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();

    return 0;
}