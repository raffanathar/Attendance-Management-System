#ifndef GUARD_HPP
#define GUARD_HPP

#include "Attendance.h"

class Guard
{
public:
    void markCheckIn(Attendance &attendance, const std::string &inTime);
    void markCheckOut(Attendance &attendance, const std::string &outTime);
};

#endif
