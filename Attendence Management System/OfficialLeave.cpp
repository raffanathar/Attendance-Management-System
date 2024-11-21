#include "OfficialLeave.h"


bool isLeapYear(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                return true;
            else
                return false;
        }
        else
            return true;
    }
    return false;
}
int getDaysInMonth(int month, int year)
{
    // Days in each month for a non-leap year
    vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Adjust February days if it's a leap year
    if (month == 2 && isLeapYear(year))
        return 29;
    
    return daysInMonth[month - 1];
}
int calculateDaysSince1900(int year, int month, int day)
{
    int totalDays = 0;
    
    // Add days for each year from 1900 to the previous year
    for (int y = 1900; y < year; ++y)
    {
        totalDays += isLeapYear(y) ? 366 : 365;
    }

    // Add days for each month in the current year
    for (int m = 1; m < month; ++m)
    {
        totalDays += getDaysInMonth(m, year);
    }

    // Add the days in the current month
    totalDays += day;

    return totalDays;
}
int OfficialLeave::calculateLeaveDays() const
{
    // Parse the start and end date into year, month, day
    int startYear, startMonth, startDay;
    int endYear, endMonth, endDay;

    // Parse the start date string "YYYY-MM-DD"
    sscanf(startDate.c_str(), "%d-%d-%d", &startYear, &startMonth, &startDay);
    // Parse the end date string "YYYY-MM-DD"
    sscanf(endDate.c_str(), "%d-%d-%d", &endYear, &endMonth, &endDay);

    // Calculate the total days from 1st January 1900 to the start date and end date
    int startTotalDays = calculateDaysSince1900(startYear, startMonth, startDay);
    int endTotalDays = calculateDaysSince1900(endYear, endMonth, endDay);

    // The difference in days
    int diffDays = endTotalDays - startTotalDays;

    return diffDays;
}

void OfficialLeave::processLeave()
{
        if (!employee) {
        std::cerr << "Error: Employee is null for leave processing." << std::endl;
        setStatus("Rejected");
        return;
    }

    // Calculate the number of leave days
    int leaveDays = calculateLeaveDays();

    // Check if the employee has enough official leave balance
    if (employee->getOfficialLeaveBalance() >= leaveDays) {
        // Deduct the leave balance and approve the leave
        if (employee->deductLeave("Official", leaveDays)) {
            setStatus("Approved");
            std::cout << "Leave approved for employee ID: " << empId << std::endl;
        } else {
            setStatus("Rejected");
            std::cerr << "Error: Unable to deduct leave balance." << std::endl;
        }
    } else {
        // If not enough leave balance, reject the leave
        setStatus("Rejected");
        std::cerr << "Insufficient earned leave balance for employee ID: " << empId << std::endl;
    }
}

bool OfficialLeave::requiresupervisorpermission() const
{
    return true;
}

bool OfficialLeave::requiredirectorpermission() const
{
    return false;
}
