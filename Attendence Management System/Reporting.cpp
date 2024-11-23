#include "Reporting.h"


void Reporting::generateAttendanceReport(const vector<Attendance*> &attendanceRecords)  const
{
    const int threshhold = double((40/7)*30)*0.80;

    for(int i=0;i<attendanceRecords.size();i++)
    {
        int total=0;
        string empid=attendanceRecords[i]->getEmployeeId();
        total += attendanceRecords[i]->getAttendanceManager().calculateTotalWeeklyHours(empid)*4.3;
        cout<<"employee id"<<empid<<endl;
        cout<<"monthly hours"<<total<<endl;
        cout<<"total threshhold"<<(total<threshhold?"below":"above")<<"80%"<<endl;
    }
}

void Reporting::generateLeaveReport(const vector<Leave*>& leaveRecords) const
{
    for (const auto& leave : leaveRecords)
    {
        if (leave->getstatus() == "Pending")
        {
            cout << "Employee ID: " << leave->getempId() << endl;
            cout << "Leave Type: " << leave->gettype() << endl;
            cout << "Start Date: " << leave->getstartDate() << endl;
            cout << "End Date: " << leave->getendDate() << endl;
            cout << "Reason: " << leave->getReason() << endl;
            cout << "Status: " << leave->getstatus() << endl;
            cout << "Supervisor Permission: " << (leave->requiresupervisorpermission() ? "Yes" : "No") << endl;
            cout << "Director Permission: " << (leave->requiredirectorpermission()? "Yes" : "No") << endl;
            cout << "----------------------------------------" << endl;
        }
    }

}

void Reporting::generateEmployeeReport(const Employee& employee, const vector<Attendance>& attendanceRecords,const vector<Leave*>& leaveRecords) const
 {
    for(int i=0;i<leaveRecords.size();i++)
    {
        if(leaveRecords[i]->getempId()==employee.getId())
        {
            cout<<"Employee: "<<employee.getName()<<endl;
            cout<<"Leave Type: "<<leaveRecords[i]->gettype()<<endl;
            cout<<"Start Date: "<<leaveRecords[i]->getstartDate()<<endl;
            cout<<"End Date: "<<leaveRecords[i]->getendDate()<<endl;
            cout<<"Reason: "<<leaveRecords[i]->getReason()<<endl<<endl;
        }
    }
 }