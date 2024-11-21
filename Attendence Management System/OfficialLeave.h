#ifndef OFFICIALLEAVE_HPP
#define OFFICIALLEAVE_HPP

#include "Leave.h"

class OfficialLeave : public Leave {
public:
    OfficialLeave() : Leave() {}
    OfficialLeave(const std::string& empId, const std::string& startDate, const std::string& endDate,
        const std::string& address, const std::string& reason, const std::string& appDate)
        : Leave(empId, "Official", startDate, endDate, address, reason, appDate) {}

    int calculateLeaveDays() const override;
};

#endif
