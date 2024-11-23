#ifndef CASUALLEAVE_HPP
#define CASUALLEAVE_HPP

#include "Leave.h"

class CasualLeave : public Leave
{
public:
    CasualLeave(Employee *emp, string &empId, const string &startDate, const string &endDate,
                const string &address, const string &reason, const string &appDate, const string &status)
        : Leave(emp, empId, "Casual", startDate, endDate, address, reason, appDate, status) {}

    int calculateLeaveDays() const override;

    string gettype() const override
    {
        return "Casual";
    }

    void processLeave() override;

    bool requiresupervisorpermission() const override;
    bool requiredirectorpermission() const override;
};

#endif
