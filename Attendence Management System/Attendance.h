#ifndef ATTENDANCE_HPP
#define ATTENDANCE_HPP

#include <string>

using namespace std;

class Attendance {
private:
    string employeeId;
    string date;
    string checkInTime;  // Time format: "HH:MM"
    string checkOutTime; // Time format: "HH:MM"
    double hoursWorked;  // Calculated based on check-in and check-out times

public:
    // Constructor
    Attendance(const string& empId, const string& date, const string& checkIn, const string& checkOut);

    // Getters
    string getEmployeeId() const;
    string getDate() const;
    string getCheckInTime() const;
    string getCheckOutTime() const;
    double getHoursWorked() const;

    // Calculate hours worked based on check-in and check-out
    void calculateHoursWorked();
};

#endif
