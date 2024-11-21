#include "Attendance.h"
#include <string>

using namespace std;

Attendance::Attendance(const string &empId, const string &date, const string &checkIn, const string &checkOut)
{
    this->employeeId = empId;
    this->date = date;
    this->checkInTime = '0';
    this->checkOutTime = '0';
}

string Attendance::getEmployeeId()
{
    return employeeId;
}
string Attendance::getDate()
{
    return date;
}
string Attendance::getCheckInTime()
{
    return checkInTime;
}
string Attendance::getCheckOutTime()
{
    return checkOutTime;
}
int Attendance::getHoursWorked()
{
    if (isValidAttendance())
    {
        int hoursWorked = stoi(checkOutTime.substr(0, 2)) - stoi(checkInTime.substr(0, 2));
        int minutesWorked = stoi(checkOutTime.substr(3, 2)) - stoi(checkInTime.substr(3, 2));
        return hoursWorked + (minutesWorked / 60.0);
    }
    return 0.0;
}

// Setters
void Attendance::setCheckInTime(const string &checkIn)
{
    this->checkInTime = checkIn;
}
void Attendance::setCheckOutTime(const string &checkOut)
{
    this->checkOutTime = checkOut;
}
// Core Functions
void Attendance::calculateHoursWorked()
{
    if (isValidAttendance())
    {
        int hoursWorked = stoi(checkOutTime.substr(0, 2)) - stoi(checkInTime.substr(0, 2));
        int minutesWorked = stoi(checkOutTime.substr(3, 2)) - stoi(checkInTime.substr(3, 2));
        hoursWorked += (minutesWorked / 60.0);
    }
} // Calculate hours worked from check-in and check-out
bool Attendance::isValidTimeFormat(const string &time)
{
    return time.length() == 5 && time[2] == ':' && isdigit(time[0]) && isdigit(time[1]) && isdigit(time[3]) && isdigit(time[4]) && stoi(time.substr(0, 2)) >= 0 && stoi(time.substr(0, 2)) <= 23 && stoi(time.substr(3, 2)) >= 0 && stoi(time.substr(3, 2)) <= 59;
    // Validate "HH:MM" format
} // Validate "HH:MM" format
bool Attendance::isValidAttendance()
{
    if (checkInTime < checkOutTime)
        return false;
    return true;

} // Ensure checkIn < checkOut and times are valid
