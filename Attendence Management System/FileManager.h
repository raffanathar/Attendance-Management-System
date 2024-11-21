#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include "Employee.h"
#include "Attendance.h"
#include "Leave.h"
#include <vector>
#include <string>

class FileManager {
public:
    static void loadEmployeesFromFile(const std::string& fileName, std::vector<Employee>& employees);
    static void saveAttendanceToFile(const std::string& fileName, const std::vector<Attendance>& attendanceRecords);
    static void saveLeaveToFile(const std::string& fileName, const std::vector<Leave*>& leaves);
    static void loadLeaveFromFile(const std::string& fileName, std::vector<Leave*>& leaves);
};

#endif
