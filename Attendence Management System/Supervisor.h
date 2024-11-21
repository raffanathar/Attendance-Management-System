#ifndef SUPERVISOR_HPP
#define SUPERVISOR_HPP

#include "LeaveManager.h"

class Supervisor {
public:
    void approveLeave(LeaveManager& leaveManager, const std::string& empId, const std::string& leaveType);
    void rejectLeave(LeaveManager& leaveManager, const std::string& empId, const std::string& leaveType);
};

#endif
