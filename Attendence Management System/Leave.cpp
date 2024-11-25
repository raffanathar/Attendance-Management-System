#include "Leave.h"

Leave::Leave(Employee *emp, string &empId, const string &type, const string &startDate, const string &endDate, const string &address, const string &reason, const string &appDate, const string &status)
{
    this->employee = emp;
    this->empId = empId;
    this->type = type;
    this->startDate = startDate;
    this->endDate = endDate;
    this->address = address;
    this->reason = reason;
    this->appDate = appDate;
    this->status = status;
}
