#include <iostream>
#include <cstring>

using namespace std;

class Employee {
private :
    char name[100];
public :
    Employee(char *name) {
        strcpy(this->name, name);
    }

    void ShowYourName() const {
        cout << "name: " << endl;
    }
};

class PermanentWorker : public Employee {
private :
    int salary;
public :
    PermanentWorker(char *name, int money)
        : Employee(name), salary(money) {}
    
    int GetPay() const {
        return salary;
    }
    void ShowSalaryInfo() const {
        ShowYourName();
        cout << "Salary: " << GetPay() << endl << endl;
    }
};

class TemporaryWorker : public Employee {
private :
    int workTime;
    int payPerHour;
public :
    TemporaryWorker(char *name, int pay)
        : Employee(name), workTime(0), payPerHour(pay) {}
    
    void AddWorkTime(int time) {
        workTime += time;
    }
    int GetPay() const {
        return workTime * payPerHour;
    }
    void ShowSalaryInfo() const {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};

class SalesWorker : public PermanentWorker {
private :
    int salesResult;
    double bonusRatio;
public :
    SalesWorker(char *name, int money, double ratio) 
        : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {}
    
    void AddSalesResult(int value) {
        salesResult += value;
    }
    int GetPay() const {
        return PermanentWorker::GetPay() + (int)(salesResult*bonusRatio);
    }
    void ShowSalaryInfo() const {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};

class EmployeeHandler {
private :
    Employee *empList[50];
    int empNum;
public :
    EmployeeHandler()
        : empNum(0) {}
    
    void AddEmployee(Employee *emp) {
        empList[empNum++] = emp;
    }
    void ShowAllSalaryInfo() const {
        /*
        for (int i=0; i < empNum; i++) {
            empList[i]->ShowSalaryInfo();
        }
        */
    }
    void ShowTotalSalary() const {
        int sum = 0;
        /*
        for (int i=0; i < empNum; i++) {
            sum += empList[i]->GetPay();
        }
        */
       cout << "salary sum: " << sum << endl;
    }

    ~EmployeeHandler() {
        for (int i=0; i < empNum; i++) {
            delete empList[i];
        }
    }
};

int main(void) {
    EmployeeHandler handler;

    // Register permanent employees
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));
    
    // Register temporary employees
    TemporaryWorker *alba = new TemporaryWorker("Jung", 700);
    alba->AddWorkTime(5);
    handler.AddEmployee(alba);

    // Register sales employees
    SalesWorker *seller = new SalesWorker("Hong", 1000, 0.1);
    seller->AddSalesResult(7000);
    handler.AddEmployee(seller);

    // Information of salary this month
    handler.ShowAllSalaryInfo();

    //Total amount of salary to be paid
    handler.ShowTotalSalary();
    
    return 0;
}