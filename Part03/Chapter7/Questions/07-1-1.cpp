#include <iostream>

using std::cout;
using std::endl;

class Car {
private :
    int gasolineGauge;
public :
    Car()
        : gasolineGauge(0) {}
    Car(int gasoline)
        : gasolineGauge(gasoline) {}
    
    int GetGasGauge() {
        return gasolineGauge;
    }
};

class HybridCar : public Car {
private :
    int electricGauge;
public :
    HybridCar()
        : electricGauge(0) {}
    HybridCar(int gasoline)
        : Car(gasoline), electricGauge(0) {}
    HybridCar(int gasoline, int electric)
        : Car(gasoline), electricGauge(electric) {}

    int GetElecGauge() {
        return electricGauge;
    }
};

class HybridWaterCar : public HybridCar {
private :
    int waterGauge;
public :
    HybridWaterCar()
        : waterGauge(0) {}
    HybridWaterCar(int gasoline)
        : HybridCar(gasoline), waterGauge(0) {}
    HybridWaterCar(int gasoline, int electric)
        : HybridCar(gasoline, electric), waterGauge(0) {}
    HybridWaterCar(int gasoline, int electric, int water)
        : HybridCar(gasoline, electric), waterGauge(water) {}
    
    void ShowCurrentGauge() {
        cout << "Gasoline left: " << GetGasGauge() << endl;
        cout << "Electric left: " << GetElecGauge() << endl;
        cout << "Water left: " << waterGauge << endl;
    }
};