#ifndef ATTENDANCE_HPP
#define ATTENDANCE_HPP

#include <string>

using namespace std;

class Attendance {
private:
    string employeeId;   // Employee ID
    string date;         // Attendance date in format "YYYY-MM-DD"
    string checkInTime;  // Time format: "HH:MM"
    string checkOutTime; // Time format: "HH:MM"
    double hoursWorked;  // Hours worked on the given date

public:
    // Constructors
    Attendance(); // Default constructor
    Attendance(const string& empId, const string& date, const string& checkIn, const string& checkOut);

    // Getters
    string getEmployeeId() ;
    string getDate() ;
    string getCheckInTime() ;
    string getCheckOutTime();
    int getHoursWorked();

    // Setters
    void setCheckInTime(const string& checkIn);
    void setCheckOutTime(const string& checkOut);

    // Core Functions
    void calculateHoursWorked(); // Calculate hours worked from check-in and check-out
    bool isValidTimeFormat(const string& time); // Validate "HH:MM" format
    bool isValidAttendance(); // Ensure checkIn < checkOut and times are valid
};

#endif
