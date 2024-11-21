#ifndef UNPAIDLEAVE_HPP
#define UNPAIDLEAVE_HPP

#include "Leave.h"

class UnpaidLeave : public Leave {
public:
    UnpaidLeave(const string& empId, const string& startDate, const string& endDate,
        const string& address, const string& reason, const string& appDate, const string& status)
        : Leave(empId, "Unpaid", startDate, endDate, address, reason, appDate) {}

        int calculateLeaveDays() const override;

        string gettype() const override {
        return "Official";
    }

    void processLeave() override;
    
};

#endif
