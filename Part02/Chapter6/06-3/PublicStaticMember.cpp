#include <iostream>

using namespace std;

class SoSimple {
public :
    static int simObjCnt;
public :    // Inserted for divisoion of variables and functions
    SoSimple() {
        simObjCnt++;
    }
};

int SoSimple::simObjCnt = 0;

int main(void) {
    cout << SoSimple::simObjCnt << "th SoSimple Object" << endl;
    SoSimple sim1;
    SoSimple sim2;

    cout << SoSimple::simObjCnt << "th SoSimple Object" << endl;
    cout << sim1.simObjCnt << "th SoSimple Object" << endl;
    cout << sim2.simObjCnt << "th SoSimple Object" << endl;

    return 0;
}