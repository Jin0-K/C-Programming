#include <iostream>
#include <cstring>

using namespace std;

class Computer {
private :
    char owner[50];
public :
    Computer(char *name) {
        strcpy(owner, name);
    }

    void Calculate() {
        cout << "calculating the request..." << endl;
    }
};

class NotebookComp : public Computer {
private :
    int Battery;
public :
    NotebookComp(char *name, int initChag)
        : Computer(name), Battery(initChag) {}
    
    void Charging() {
        Battery += 5;
    }
    void UseBattery() {
        Battery -= 1;
    }
    void MovingCal() {
        if (GetBatteryInfo() < 1) {
            cout << "Need Charging" << endl;
            return;
        }
        cout << "Moving while ";
        Calculate();
        UseBattery();
    }
    int GetBatteryInfo() {
        return Battery;
    }
};

class TabletNotebook : public NotebookComp {
private :
    char regstPenModel[50];
public :
    TabletNotebook(char *name, int initChag, char *pen)
        : NotebookComp(name, initChag) {
        strcpy(regstPenModel, pen);
    }

    void Write(char *penInfo) {
        if (GetBatteryInfo() < 1) {
            cout << "Need Charging" << endl;
            return;
        }
        if (strcmp(regstPenModel, penInfo) != 0) {
            cout << "This is not a registered pen.";
            return;
        }
        cout << "Processing the written contents." << endl;
        UseBattery();
    }
};

int main(void) {
    NotebookComp nc("Jinyoung", 5);
    TabletNotebook tn("Boris", 5, "ISE-241-242");
    nc.MovingCal();
    tn.Write("ISE-241-242");

    return 0;
}