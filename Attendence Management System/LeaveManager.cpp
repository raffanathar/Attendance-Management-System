#include "LeaveManager.h"

void LeaveManager::addLeave(Leave *leave)
{
    leaves.push_back(leave);
}

vector<Leave*> LeaveManager::getLeaves() const
{
    return leaves;
}

void LeaveManager::approveLeave(const string &empId, const string &leaveType) {
    Supervisor supervisor;
    Director director;

    // Threshold check for casual leaves
    if (leaveType == "Casual" && isExceedingThreshold(empId, leaveType)) {
        cout << "Cannot take more than 4 Casual Leaves." << endl;
        return; // Reject immediately due to threshold
    }

    bool leaveFound = false; // Track if matching leave is found

    for (Leave* leave : leaves) {
        // Check for matching pending leave
        if (leave->getempId() == empId && leave->gettype() == leaveType && leave->getstatus() == "Pending") {
            leaveFound = true;

            // Supervisor permissions
            if (leave->requiresupervisorpermission()) {
                supervisor.approveLeave(*this, empId, leaveType);
            }

            // Director permissions
            if (leave->requiredirectorpermission()) {
                director.approveLeave(*this, empId, leaveType);
            }

            // Final approval
            leave->setStatus("Approved");
            cout << "Leave approved for employee ID: " << empId << " (Type: " << leaveType << ")" << endl;
            return; // Exit after processing the leave
        }
    }

    if (!leaveFound) {
        cout << "No pending leave found for employee ID: " << empId << " (Type: " << leaveType << ")." << endl;
    }
}


vector<Leave*> LeaveManager::getPendingLeaves() const
{
    vector<Leave*> pendingLeaves;
    for (const auto &leave : leaves) {
        if (leave->getstatus() == "Pending") {
            pendingLeaves.push_back(leave);
        }
    }
    return pendingLeaves;
}

vector<Leave*> LeaveManager::getApprovedLeaves() const
{
    vector<Leave*> approvedLeaves;
    for (const auto &leave : leaves) {
        if (leave->getstatus() == "Approved") {
            approvedLeaves.push_back(leave);
        }
    }
    return approvedLeaves;
}

vector<Leave*> LeaveManager::getLeavesByEmpId(const string &empId) const
{
    vector<Leave*> leavesByEmpId;
    for (const auto &leave : leaves) {
        if (leave->getempId() == empId) {
            leavesByEmpId.push_back(leave);
        }
    }
    return leavesByEmpId;
}

bool LeaveManager::isExceedingThreshold(const string &empId, const string &leaveType) const
{
    int leaveCount = 0;
    for (Leave* leave : leaves) {
        if (leave->gettype() == leaveType && leave->getstatus() == "Approved" && leave->getempId() == empId) {
            leaveCount++;
        }
    }
    return leaveCount >= 4;
}

void LeaveManager::processLeave(Leave *leave)
{
    
}
