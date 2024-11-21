#ifndef LEAVE_HPP
#define LEAVE_HPP

#include <string>
using namespace std;

class Leave {
protected:
    string empId;
    string type;
    string startDate;
    string endDate;
    string reason;
    string address;
    string appDate;

public:
    Leave();
    Leave(const string& empId, const string& type, const string& startDate, const string& endDate,
        const string& address, const string& reason, const string& appDate);

    virtual int calculateLeaveDays() const = 0; // Pure virtual function to calculate leave days

    string getEmpId() const;
    string getType() const;
    string getStartDate() const;
    string getEndDate() const;
    string getReason() const;
    string getAddress() const;
    string getAppDate() const;
};

#endif
