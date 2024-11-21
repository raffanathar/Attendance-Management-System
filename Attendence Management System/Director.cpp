#include "Director.h"
#include<iostream>

void Director::approveLeave(LeaveManager &leaveManager, const string &empId, const string &leaveType)
{
    vector<Leave*> leaves = leaveManager.getLeaves();
    for (Leave* leave : leaves) {
        if (leave->getempId() == empId && leave->gettype() == leaveType && leave->getstatus() == "Approved") {
            leave->setStatus("Approved by Director"); 
            cout<<"Leave Approved by Director"<<endl;
            break;
        }
    }
}
