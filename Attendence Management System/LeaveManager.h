#ifndef LEAVEMANAGER_HPP
#define LEAVEMANAGER_HPP

#include <iostream>
#include <vector>
#include "Leave.h"
#include "Supervisor.h"
#include "Director.h"

using namespace std;

class LeaveManager {
private:
    vector<Leave*> leaves;  

public:
    void addLeave(Leave* leave);
    vector<Leave*> getLeaves() const;
    void approveLeave(const string& empId, const string& leaveType);
    vector<Leave*> getPendingLeaves() const;
    vector<Leave*> getApprovedLeaves() const;
    vector<Leave*> getLeavesByEmpId(const string& empId) const;
    bool isExceedingThreshold(const string& empId, const string& leaveType) const;
    void processLeave(Leave* leave);
};

#endif
