#include "Guard.h"

void Guard::markCheckIn(Attendance &attendance, const std::string &inTime){
    attendance.setCheckInTime(inTime);
}

void Guard::markCheckOut(Attendance &attendance, const std::string &outTime){
    attendance.setCheckOutTime(outTime);
}
