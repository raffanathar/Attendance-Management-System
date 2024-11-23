#ifndef LEAVE_HPP
#define LEAVE_HPP

#include <string>
#include <iostream>
#include <vector>
#include "Employee.h"
using namespace std;

class Leave
{
protected:
    Employee *employee;
    string empId;
    string type;
    string startDate;
    string endDate;
    string reason;
    string address;
    string appDate;
    string status;

public:
    Leave(Employee *emp, string &empId, const string &type, const string &startDate, const string &endDate,
          const string &address, const string &reason, const string &appDate, const string &status = "Pending");

    virtual int calculateLeaveDays() const = 0;

    string getstatus() const { return status; }
    string getempId() const { return empId; }

    string getstartDate() const { return startDate; }
    string getendDate() const { return endDate; }
    string getReason() const { return reason; }

    void setStatus(const string &status) { this->status = status; }

    virtual string gettype() const = 0;
     virtual void processLeave() = 0;

    virtual bool requiresupervisorpermission() const = 0;
    virtual bool requiredirectorpermission() const = 0;
        virtual ~Leave() = default;

};

#endif
