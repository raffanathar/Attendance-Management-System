#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <vector>
#include "Employee.h"
#include "Leave.h"
#include "Attendance.h"

using namespace std;
class FileManager {
public:
    // Save and load employees
    static void saveEmployees(const vector<Employee>& employees);
    static void loadEmployees(vector<Employee>& employees);

    // Save and load leave records
    static void saveLeaveRecords(const vector<Leave*>& leaveRecords);
    static void loadLeaveRecords(vector<Leave*>& leaveRecords);

    // Save and load attendance records
    static void saveAttendanceRecords(const vector<Attendance>& attendanceRecords);
    static void loadAttendanceRecords(vector<Attendance>& attendanceRecords);
};

#endif
