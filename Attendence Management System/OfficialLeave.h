#ifndef OFFICIALLEAVE_HPP
#define OFFICIALLEAVE_HPP

#include "Leave.h"

class OfficialLeave : public Leave
{
public:
    OfficialLeave(Employee *emp, string &empId, const string &startDate, const string &endDate,
                const string &address, const string &reason, const string &appDate, const string &status)
        : Leave(emp, empId, "Official", startDate, endDate, address, reason, appDate, status) {}


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
