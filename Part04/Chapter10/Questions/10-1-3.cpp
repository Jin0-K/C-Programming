#include <iostream>

using std::cout;
using std::endl;

class Point {
private :
    int xpos, ypos;
public :
    Point (int x=0, int y=0)
        : xpos(x), ypos(y) {}

    void ShowPosition() const {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }

    friend Point operator+(const Point &pos1, const Point &pos2);
    friend Point operator-(const Point &pos1, const Point &pos2);
    Point &operator+=(const Point &pos2) {
        xpos += pos2.xpos;
        ypos += pos2.ypos;
        return *this;
    }
    Point &operator-=(const Point &pos2) {
        xpos -= pos2.xpos;
        ypos -= pos2.ypos;
        return *this;
    }
    friend bool operator==(const Point &pos1, const Point &pos2);
    friend bool operator!=(const Point &pos1, const Point &pos2);
};

Point operator+(const Point &pos1, const Point &pos2) {
    Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
    return pos;
}

Point operator-(const Point &pos1, const Point &pos2) {
    Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
    return pos;
}

bool operator==(const Point &pos1, const Point &pos2) {
    if ((pos1.xpos == pos2.xpos) && (pos1.ypos == pos2.ypos)) {
        return true;
    } 
    return false;
}

bool operator!=(const Point &pos1, const Point &pos2) {
    return !operator==(pos1, pos2);
}


int main(void) {
    Point pos1(3, 4);
    Point pos2(10, 20);
    Point pos3(3, 4);

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();

    if (pos1 != pos2) {
        cout << "pos1 != pos2" << endl;
    }
    else {
        cout << "pos1 == pos2" << endl;
    }

    if (pos1 == pos3) {
        cout << "pos1 == pos3" << endl;
    }
    else {
        cout << "pos1 != pos3" << endl;
    }

    return 0;
}