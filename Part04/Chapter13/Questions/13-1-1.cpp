#include <iostream>

class Point {
private :
    int xpos, ypos;
public :
    Point(int x=0, int y=0) : xpos(x), ypos(y) {}

    void ShowPosition() const {
        std::cout << '[' << xpos << ", " << ypos << ']' << std::endl;
    }
};

template <class P>
void SwapData(P *P1, P *P2) {
    P temp;
    temp = *P1;
    *P2 = *P1;
    *P2 = temp;
}

int main(void) {
    Point A(1, 2);
    Point B(-2, -1);

    A.ShowPosition();
    B.ShowPosition();

    SwapData<Point>(&A, &B);
    std::cout << "SwapData<Point>(&A, &B)" << std::endl;

    A.ShowPosition();
    B.ShowPosition();

    return 0;
}