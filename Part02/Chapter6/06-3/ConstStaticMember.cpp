#include <iostream>

using namespace std;

class CountryArea {
public :
    const static int RUSSIA     = 1707540;
    const static int CANADA     = 998467;
    const static int CHINA      = 957290;
    const static int SOUTH_KOREA    = 9922;
};

int main(void) {
    cout << "Area of Russia: " << CountryArea::RUSSIA << "km^2" << endl;
    cout << "Area of Canada: " << CountryArea::CANADA << "km^2" << endl;
    cout << "Area of China: " << CountryArea::CHINA << "km^2" << endl;
    cout << "Area of South Korea: " << CountryArea::SOUTH_KOREA << "km^2" << endl;

    return 0;
}