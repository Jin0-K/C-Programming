#include <iostream>
#include <cstring>

using namespace std;

class Gun {
private :
    int bullet;
public :
    Gun(int bnum)
        : bullet(bnum) {}
    
    void Shoot() {
        cout << "BANG!!" << endl;
        bullet--;
    }
};

class Police {
private :   
    int handcuffs;
    Gun *pistol;
public :
    Police(int bnum, int bcuff)
        : handcuffs(bcuff) {
        if (bnum > 0) {
            pistol = new Gun(bnum);
        }
        else {
            pistol = NULL;
        }
    }
    
    void PutHandcuff() {
        cout << "SNAP!" << endl;
        handcuffs--;
    }
    void Shoot() {
        if (pistol == NULL) {
            cout << "OUT OF AMMO" << endl;
        }
        else {
            pistol->Shoot();
        }
    }

    ~Police() {
        if (pistol != NULL) {
            delete pistol;
        }
    }
};

int main(void) {
    Police pman1(5, 3);
    pman1.Shoot();
    pman1.PutHandcuff();

    Police pman2(0, 3); // Police without a pistol
    pman2.Shoot();
    pman2.PutHandcuff();

    return 0;
}