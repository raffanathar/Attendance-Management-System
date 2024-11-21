#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>
using namespace std;

class Employee {
private:
    string id;
    string name;
    int casualLeaveBalance;
    int earnedLeaveBalance;
    int officialLeaveBalance;
    int unpaidLeaveBalance;
    Attendance *attendance;

public:
    Employee(string id, string name);

    string getId() const;
    string getName() const;

    int getCasualLeaveBalance() const;
    int getEarnedLeaveBalance() const;
    int getOfficialLeaveBalance() const;
    int getUnpaidLeaveBalance() const;

    bool deductLeave(const string& leaveType, int days); 
    void resetLeaveBalance(const string& leaveType, int newBalance); 
};

#endif
