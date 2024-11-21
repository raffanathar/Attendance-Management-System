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

    // Getter and Setter for Employee details
    string getId() const;
    string getName() const;

    // Leave Balance related functions
    int getCasualLeaveBalance() const;
    int getEarnedLeaveBalance() const;
    int getOfficialLeaveBalance() const;
    int getUnpaidLeaveBalance() const;

    // Functions to modify leave balances
    void deductCasualLeave(int days);
    void deductEarnedLeave(int days);
    void deductOfficialLeave(int days);
    void deductUnpaidLeave(int days);

    // Attendance related functions
    void markAttendance(bool isPresent);
    void viewAttendance();
};
#endif
