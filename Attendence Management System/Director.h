#ifndef DIRECTOR_HPP
#define DIRECTOR_HPP

#include "LeaveManager.h"

class Director {
public:
    void approveLeave(LeaveManager& leaveManager, const std::string& empId, const std::string& leaveType);
};

#endif
