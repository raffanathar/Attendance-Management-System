#ifndef GUARD_HPP
#define GUARD_HPP

#include "Attendance.h"

class Guard {
public:
    void markAttendance(Attendance& attendance, const std::string& inTime, const std::string& outTime);
};

#endif
