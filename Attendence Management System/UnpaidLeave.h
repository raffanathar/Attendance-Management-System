#ifndef UNPAIDLEAVE_HPP
#define UNPAIDLEAVE_HPP

#include "Leave.h"

class UnpaidLeave : public Leave {
public:
    UnpaidLeave() : Leave() {}
    UnpaidLeave(const std::string& empId, const std::string& startDate, const std::string& endDate,
        const std::string& address, const std::string& reason, const std::string& appDate)
        : Leave(empId, "Unpaid", startDate, endDate, address, reason, appDate) {}

    int calculateLeaveDays() const override;
};

#endif
