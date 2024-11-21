#ifndef ATTENDANCE_HPP
#define ATTENDANCE_HPP

#include <string>
#include <vector>

using namespace std;
class Attendance {
private:
    string empId;
    vector<string> attendanceIn;  // Arrival times
    vector<string> attendanceOut; // Leaving times

public:
    Attendance(const string& empId);
    void markAttendance(const string& inTime, const string& outTime);
    vector<string> getAttendanceIn() const;
    vector<string> getAttendanceOut() const;
};

#endif
