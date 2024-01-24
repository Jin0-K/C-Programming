#include <iostream>
#include <cstring>

using namespace std;

namespace CAR_CONST {
        enum {
        ID_LEN = 20,
        MAX_SPD = 200,
        FUEL_STEP = 2,
        ACC_STEP = 10,
        BRK_STEP = 10
    };
}

class Car {
private :
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGuage;
    int curSpeed;
public :
    void InitMembers(char *ID, int fuel);
    void ShowCarState();
    void Accel();
    void Break();
};

void Car::InitMembers(char *ID, int fuel) {
    strcpy(gamerID, ID);
    fuelGuage = fuel;
    curSpeed = 0;
}

void Car::ShowCarState() {
    cout << "Owner ID: " << gamerID << endl;
    cout << "Fuel State: " << fuelGuage << endl;
    cout << "Current Speed: " << curSpeed << endl << endl;
}

void Car::Accel() {
    if (fuelGuage <= 0) {
        return;
    }
    else {
        fuelGuage -= CAR_CONST::FUEL_STEP;
    }

    if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD) {
        curSpeed = CAR_CONST::MAX_SPD;
        return;
    }
    curSpeed += CAR_CONST::BRK_STEP;
}

void Car::Break() {
    if (curSpeed < CAR_CONST::BRK_STEP) {
        curSpeed = 0;
        return;
    }
    curSpeed -= CAR_CONST::BRK_STEP;
}

int main(void) {
    Car run99;
    run99.InitMembers("run99", 100);
    run99.Accel();
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();

    return 0;
}