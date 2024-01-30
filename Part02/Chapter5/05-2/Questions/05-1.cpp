#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

namespace COMP_POS {
    enum {
        CLERK = 0,
        SENIOR = 1,
        ASSIST = 2,
        MANAGER = 3
    };
}

class NameCard {
private :
    char *name;
    char *company_name;
    char *phone_num;
    int position;

public :
    NameCard(char *myname, char *compname, char *phonenum, int comppos)
        : position(comppos) {
            int len = strlen(myname) + 1;
            name = new char[len];
            strcpy(name, myname);

            len = strlen(compname) + 1;
            company_name = new char[len];
            strcpy(company_name, compname);

            len = strlen(phonenum) + 1;
            phone_num = new char[len];
            strcpy(phone_num, phonenum);
    }

    void ShowNameCardInfo() const {
        cout << "Name: " << name << endl;
        cout << "Company: " << company_name << endl;
        cout << "Phone Number: " << phone_num << endl;
        cout << "Position: ";
        switch(position) {
            case COMP_POS::CLERK :
                cout << "Clerk" << endl;
                break;
            case COMP_POS::SENIOR :
                cout << "Senior" << endl;
                break;
            case COMP_POS::ASSIST :
                cout << "Assist" << endl;
                break;
            case COMP_POS::MANAGER :
                cout << "Manager" << endl;
                break;
            default :
                break;
        }
        cout << endl;
    }

    ~NameCard() {
        delete []name;
        delete []company_name;
        delete []phone_num;
    }
};

int main(void) {
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard copy1 = manClerk;
    NameCard manSenior("Hong", "OrangEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard copy2 = manSenior;

    copy1.ShowNameCardInfo();
    copy2.ShowNameCardInfo();

    return 0;
}