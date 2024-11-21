#ifndef EARNEDLEAVE_HPP
#define EARNEDLEAVE_HPP

#include "Leave.h"

class EarnedLeave : public Leave
{
public:
    EarnedLeave(const string &empId, const string &startDate, const string &endDate,
                const string &address, const string &reason, const string &appDate, const string &status)
        : Leave(empId, "Earned", startDate, endDate, address, reason, appDate, status) {}

    int calculateLeaveDays() const override;

    string gettype() const override
    {
        return "Earned";
    }

    void processLeave() override;
};

#endif
