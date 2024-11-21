#ifndef SUPERVISOR_HPP
#define SUPERVISOR_HPP

#include "LeaveManager.h"
#include "Director.h"

class Supervisor {
public:
    void approveLeave(LeaveManager& leaveManager, const string& empId, const string& leaveType);
    void rejectLeave(LeaveManager& leaveManager, const string& empId, const string& leaveType);
};

#endif
