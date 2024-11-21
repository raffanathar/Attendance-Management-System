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

public:
    // Constructor
    Employee(string id, string name);

    // Getters for Employee details
    string getId() const;
    string getName() const;

    // Getters for Leave Balances
    int getCasualLeaveBalance() const;
    int getEarnedLeaveBalance() const;
    int getOfficialLeaveBalance() const;
    int getUnpaidLeaveBalance() const;

    // Functions to modify leave balances
    bool deductLeave(const string& leaveType, int days); // Generalized for all leave types
    void resetLeaveBalance(const string& leaveType, int newBalance); // Optional, for leave resets
};

#endif
