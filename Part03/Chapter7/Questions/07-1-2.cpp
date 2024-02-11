#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class MyFriendInfo {
private :
    char *name;
    int age;
public :
    MyFriendInfo(char *name, int age) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->age = age;
    }

    ~MyFriendInfo() {
        delete []name;
    }

    void ShowMyFriendInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class MyFriendDetailInfo : public MyFriendInfo {
private :
    char *addr;
    char *phone;
public :
    MyFriendDetailInfo(char *name, int age, char *addr, char *phone)
        : MyFriendInfo(name, age) {
        this->addr = new char[strlen(addr) + 1];
        strcpy(this->addr, addr);
        this->phone = new char[strlen(phone) + 1];
        strcpy(this->phone, phone);
    }

    ~MyFriendDetailInfo() {
        delete []addr;
        delete []phone;
    }

    void ShowMyFriendDetailInfo() {
        ShowMyFriendInfo();
        cout << "Address: " << addr << endl;
        cout << "Phone Number: " << phone << endl << endl;
    }
};

int main(void) {
    MyFriendDetailInfo frnd("Jinyoung", 22, "Seoul", "010-1234-4321");
    frnd.ShowMyFriendDetailInfo();

    return 0;
}