#ifndef ATTENDANCEMANAGER_HPP
#define ATTENDANCEMANAGER_HPP

#include <vector>
#include <string>
#include "Attendance.h"

class AttendanceManager {
private:
    vector<Attendance> attendanceRecords;
    
public:
    // Mark attendance (check-in and check-out)
    void markCheckIn(const string& empId, const string& date, const string& checkInTime);
    void markCheckOut(const string& empId, const string& date, const string& checkOutTime);
    // Generate attendance report
    vector<string> generateAttendanceReport(double threshold);

    // Get attendance details for an employee
    vector<Attendance> getAttendanceDetails(const string& empId);

    // Helper to calculate total weekly hours for an employee
    double calculateTotalWeeklyHours(string& empId);
};

#endif
