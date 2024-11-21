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
    string status;

public:
    Leave();
    Leave(const string& empId, const string& type, const string& startDate, const string& endDate,
        const string& address, const string& reason, const string& appDate , const string& status = "Pending");

    virtual int calculateLeaveDays() const = 0; // Pure virtual function to calculate leave days

    string getstatus() const { return status; }
    void setStatus(const string& status) { this->status = status; }

    virtual string gettype() const = 0;
    virtual void processLeave() = 0;

};

#endif
