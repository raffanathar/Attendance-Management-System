#ifndef EARNEDLEAVE_HPP
#define EARNEDLEAVE_HPP

#include "Leave.h"

class EarnedLeave : public Leave
{
public:
    EarnedLeave(Employee *emp, string &empId, const string &startDate, const string &endDate,
                const string &address, const string &reason, const string &appDate, const string &status)
        : Leave(emp, empId, "Earned", startDate, endDate, address, reason, appDate, status) {}

    int calculateLeaveDays() const override;

    string gettype() const override
    {
        return "Earned";
    }

    void processLeave() override;

    bool requiresupervisorpermission() const  override;
    bool requiredirectorpermission() const override;
};

#endif
