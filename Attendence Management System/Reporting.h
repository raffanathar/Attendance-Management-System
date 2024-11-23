#ifndef REPORTING_HPP
#define REPORTING_HPP

#include <vector>
#include "Employee.h"
#include "Leave.h"
#include "AttenanceManager.h"

class Reporting
{
public:
    // Generate attendance report
    void generateAttendanceReport(const vector<Attendance*> &attendanceRecords) const;

    // Generate leave report
    void generateLeaveReport(const vector<Leave *> &leaveRecords) const;

    // Generate detailed report for an employee
    void generateEmployeeReport(const Employee &employee, const vector<Attendance> &attendanceRecords,
                                const vector<Leave *> &leaveRecords) const;
};

#endif
