#ifndef LEAVEMANAGER_HPP
#define LEAVEMANAGER_HPP

#include "Leave.h"
#include <vector>
using namespace std;

class LeaveManager {
private:
    vector<Leave*> leaves;  // Stores all leave applications

public:
    void addLeave(Leave* leave);
    vector<Leave*> getLeaves() const;
    void approveLeave(const string& empId, const string& leaveType);
    void rejectLeave(const string& empId, const string& leaveType);
};

#endif
