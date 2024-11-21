#include "Supervisor.h"

#include <iostream>

void Supervisor::approveLeave(LeaveManager &leaveManager, const string &empId, const string &leaveType)
{
    vector<Leave *> leaves = leaveManager.getLeaves();
    for (Leave *leave : leaves)
    {
        if (leave->getempId() == empId && leave->gettype() == leaveType && leave->getstatus() == "Pending")
        {
            if (leave->requiresupervisorpermission())
            {
                leave->setStatus("Approved");
                cout << "Approved by supervisor" << endl;
            
            if( leave->requiredirectorpermission())
            {
                Director Director;
                Director.approveLeave(leaveManager, empId, leaveType);
            }
            }
            else{
                cout << "Leave does not require approval" << endl;
            }

        }
    }
}

void Supervisor::rejectLeave(LeaveManager &leaveManager, const string &empId, const string &leaveType)
{
    vector<Leave *> leaves = leaveManager.getLeaves();
    for (Leave *leave : leaves)
    {
        if (leave->getempId() == empId && leave->gettype() == leaveType && leave->getstatus() == "Pending")
        {
            leave->setStatus("Rejected");
            cout << "Rejected by supervisor" << endl;
        }
    }
}
