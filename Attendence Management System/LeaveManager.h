#ifndef LEAVEMANAGER_HPP
#define LEAVEMANAGER_HPP

#include<iostream>
#include "Leave.h"
#include "Supervisor.h"
#include "Director.h"
#include <vector>
using namespace std;

class LeaveManager {
private:
    vector<Leave*> leaves;  

public:
    void addLeave(Leave* leave);
    vector<Leave*> getLeaves() const;
    void approveLeave(const string& empId, const string& leaveType);
    vector<Leave*> getPendingLeave() const;
    vector<Leave*> getApprovedLeave() const;
    vector<Leave*> getLeavesbyempid(const string& empid) const;
    bool isexceedingthreasholdest(const string& empid, const string& leaveType) const;
};

#endif
