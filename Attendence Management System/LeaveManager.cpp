#include "LeaveManager.h"

void LeaveManager::addLeave(Leave *leave)
{
    leaves.push_back(leave);
}

vector<Leave *> LeaveManager::getLeaves() const
{
    return leaves;
}

void LeaveManager::approveLeave(const string &empId, const string &leaveType)
{
  Supervisor supervisor;
  Director director;

  if (leaveType == "Casual" && isexceedingthreasholdest(empId,leaveType)) 
  {
    cout<<"cant take more than 4 Casual Leaves "<<endl;
    supervisor.approveLeave(*this,empId,leaveType);
    director.approveLeave(*this,empId, leaveType);
  }

  if (leaveType == "Earned"){
    supervisor.approveLeave(*this,empId,leaveType);
    director.approveLeave(*this,empId, leaveType);
  }
  else if (leaveType == "Official"){
    supervisor.approveLeave(*this,empId,leaveType);
  }
  else if (leaveType == "Unpaid")
  {
    supervisor.approveLeave(*this,empId,leaveType);
  }
  else if (leaveType == "Casual"){
    
    cout<<"Approved"<<endl;
  }
  else {
    cout<<"Invalid Leave Type"<<endl;
  }
  
}

vector<Leave *> LeaveManager::getPendingLeave() const
{
    vector<Leave *> pendingLeaves;
    for (const auto &leave : leaves) {
        if (leave->getstatus() == "Pending") {
            pendingLeaves.push_back(leave);
        }
    }
    return pendingLeaves;
}

vector<Leave *> LeaveManager::getApprovedLeave() const
{
    vector<Leave *> approvedLeaves;
    for (const auto &leave : leaves) {
        if (leave->getstatus() == "Approved") {
            approvedLeaves.push_back(leave);
        }
    }
    return approvedLeaves;

}

vector<Leave *> LeaveManager::getLeavesbyempid(const string &empid) const
{
    vector<Leave *> leavesByEmpId;
    for (const auto &leave : leaves) {
        if (leave->getempId() == empid) {
            leavesByEmpId.push_back(leave);
        }
    }
    return leavesByEmpId;
}

bool LeaveManager::isexceedingthreasholdest(const string &empid, const string &leaveType) const
{
    int leaveCount = 0;
    for (Leave* leave : leaves) {
        if (leave->gettype() == leaveType && leave->getstatus() == "Approved" && leave->getstatus() == empid) {
            leaveCount++;
        }
    }
    return leaveCount >= 4;
}
