#ifndef CASUALLEAVE_HPP
#define CASUALLEAVE_HPP

#include "Leave.h"

class CasualLeave : public Leave {
public:
    CasualLeave() : Leave() {}
    CasualLeave(const std::string& empId, const std::string& startDate, const std::string& endDate,
        const std::string& address, const std::string& reason, const std::string& appDate)
        : Leave(empId, "Casual", startDate, endDate, address, reason, appDate) {}

    int calculateLeaveDays() const override;
};

#endif
