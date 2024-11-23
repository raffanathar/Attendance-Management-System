#include "Employee.h"

Employee::Employee(string id, string name)
{
    this->id = id;
    this->name = name;
    casualLeaveBalance = 15;
    earnedLeaveBalance = 21;
    officialLeaveBalance = 0;
    unpaidLeaveBalance = 0;
}

string Employee::getId() const
{
    return id;
}

string Employee::getName() const
{
    return name;
}

int Employee::getCasualLeaveBalance() const
{
    return casualLeaveBalance;
}

int Employee::getEarnedLeaveBalance() const
{
    return earnedLeaveBalance;
}

int Employee::getOfficialLeaveBalance() const
{
    return officialLeaveBalance;
}

int Employee::getUnpaidLeaveBalance() const
{
    return unpaidLeaveBalance;
}

bool Employee::deductLeave(const string &leaveType, int days)
{
    if (leaveType == "Casual")
    {
        if (casualLeaveBalance >= days)
        {
            casualLeaveBalance -= days;
            return true;
        }
    }
    else if (leaveType == "Earned")
    {
        if (earnedLeaveBalance >= days)
        {
            earnedLeaveBalance -= days;
            return true;
        }
    }
    else if (leaveType == "Official")
    {
        if (officialLeaveBalance >= days)
        {
            officialLeaveBalance -= days;
            return true;
        }
    }
    else if (leaveType == "Unpaid")
    {
        if (unpaidLeaveBalance >= days)
        {
            unpaidLeaveBalance -= days;
            return true;
        }
    }
    return false;
}

void Employee::resetLeaveBalance(const string &leaveType, int newBalance)
{
    if (leaveType == "Casual")
    {
        casualLeaveBalance = 15;
    }
    else if (leaveType == "Earned")
    {
        earnedLeaveBalance = 21;
    }
    else if (leaveType == "Official")
    {
        officialLeaveBalance = 0;
    }
    else if (leaveType == "Unpaid")
    {
        unpaidLeaveBalance = 0;
    }
}

bool Employee::cantakeleave(const string &leaveType, int days)
{
    if (leaveType == "Casual")
    {
        return casualLeaveBalance >= days;
    }
    else if (leaveType == "Earned")
    {
        return earnedLeaveBalance >= days;
    }
    else if (leaveType == "Official")
    {
        return officialLeaveBalance >= days;
    }
    else if (leaveType == "Unpaid")
    {
        return unpaidLeaveBalance >= days;
    }
    return false;
}