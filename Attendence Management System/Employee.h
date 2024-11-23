#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>
#include<vector>
#include "Attendance.h"
#include "Leave.h"
using namespace std;

class Employee {
private:
    string id;
    string name;
    int casualLeaveBalance;
    int earnedLeaveBalance;
    int officialLeaveBalance;
    int unpaidLeaveBalance;
  
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
    bool cantakeleave(const string& leaveType , int days);
};

#endif
