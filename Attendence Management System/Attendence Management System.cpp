#include "AttenanceManager.h"

void AttendanceManager::markCheckIn(const string &empId, const string &date, const string &checkInTime)
{
    // Check if employee has already marked attendance for the given date
    for (auto &record : attendanceRecords)
    {
        if (record.getEmployeeId() == empId && record.getDate() == date)
        {
            record.setCheckInTime(checkInTime);
            return;
        }
    }
}
void AttendanceManager::markCheckOut(const string &empId, const string &date, const string &checkOutTime)
{
    for (auto &record : attendanceRecords)
    {
        if (record.getEmployeeId() == empId && record.getDate() == date)
        {
            record.setCheckOutTime(checkOutTime);
            record.calculateHoursWorked();
            return;
        }
    }
}

// Generate attendance report AttendanceManager::
vector<string> AttendanceManager::generateAttendanceReport(double threshold)
{
    
}

// Get attendance details for an employee
vector<Attendance> AttendanceManager::getAttendanceDetails(const string &empId)
{
    vector<Attendance> result;
    for (auto &record : attendanceRecords)
    {
        if (record.getEmployeeId() == empId)
        {
            result.push_back(record);
        }
    }
    return result;
}

// Helper to calculate total weekly hours for an employee
double AttendanceManager::calculateTotalWeeklyHours(const string &empId)
{
    int totalHours = 0;
    for (int i = 0; i <7;i++)
    {
       totalHours +=attendanceRecords[i].getHoursWorked();
    }
    return totalHours;
}