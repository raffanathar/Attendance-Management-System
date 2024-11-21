#ifndef EARNEDLEAVE_HPP
#define EARNEDLEAVE_HPP

#include "Leave.h"

class EarnedLeave : public Leave {
public:
    EarnedLeave() : Leave() {}
    EarnedLeave(const std::string& empId, const std::string& startDate, const std::string& endDate,
        const std::string& address, const std::string& reason, const std::string& appDate)
        : Leave(empId, "Earned", startDate, endDate, address, reason, appDate) {}

    int calculateLeaveDays() const override;
};

#endif
