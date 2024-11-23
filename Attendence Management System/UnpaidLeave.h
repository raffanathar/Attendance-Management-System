#ifndef UNPAIDLEAVE_HPP
#define UNPAIDLEAVE_HPP

#include "Leave.h"

class UnpaidLeave : public Leave
{
public:
    UnpaidLeave(Employee *emp, string &empId, const string &startDate, const string &endDate,
                const string &address, const string &reason, const string &appDate, const string &status)
        : Leave(emp, empId, "Unpaid", startDate, endDate, address, reason, appDate, status) {}

    int calculateLeaveDays() const override;

    string gettype() const override
    {
        return "Official";
    }

    void processLeave() override;

    bool requiresupervisorpermission() const override;
    bool requiredirectorpermission() const override;
};

#endif
