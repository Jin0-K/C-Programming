#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

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

    Police &operator=(const Police &ref) {
        handcuffs = ref.handcuffs;
        if (pistol != NULL)
            delete pistol;
        if (ref.pistol != NULL) {
            pistol = new Gun(*(ref.pistol));
        }
        else {
            pistol = NULL;
        }

        return *this;
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
    Police pman2(0, 3); // Police without a pistol
    pman1.Shoot();
    pman2 = pman1;
    pman2.Shoot();
    pman2.PutHandcuff();

    return 0;
}