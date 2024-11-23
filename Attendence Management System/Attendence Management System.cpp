#include <iostream>
#include <vector>
#include "Employee.h"
#include "AttendanceManager.h"
#include "LeaveManager.h"
#include "CasualLeave.h"
#include "EarnedLeave.h"
#include "OfficialLeave.h"
#include "UnpaidLeave.h"
#include "Supervisor.h"
#include "Director.h"
#include "Guard.h"

using namespace std;

int main() {
    vector<Employee*> employees;       // List of employees
    LeaveManager leaveManager;         // Leave manager
    AttendanceManager attendanceManager; // Attendance manager
    Supervisor supervisor;             // Supervisor
    Director director;                 // Director
    Guard guard;                       // Guard to handle attendance

    int choice;
    do {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Add Employee\n";
        cout << "2. Mark Attendance\n";
        cout << "3. Apply for Leave\n";
        cout << "4. Approve Leave (Supervisor)\n";
        cout << "5. Approve Leave (Director)\n";
        cout << "6. View Attendance Report\n";
        cout << "7. View Leave Status\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string id, name;
                cout << "Enter Employee ID: ";
                cin >> id;
                cout << "Enter Employee Name: ";
                cin >> name;
                employees.push_back(new Employee(id, name));
                cout << "Employee added successfully!\n";
                break;
            }
            case 2: {
                string empId, date, time;
                int subChoice;
                cout << "1. Check-In\n2. Check-Out\nEnter your choice: ";
                cin >> subChoice;
                cout << "Enter Employee ID: ";
                cin >> empId;
                cout << "Enter Date (YYYY-MM-DD): ";
                cin >> date;
                cout << "Enter Time (HH:MM): ";
                cin >> time;

                // Find employee
                Employee* emp = nullptr;
                for (auto e : employees) {
                    if (e->getId() == empId) {
                        emp = e;
                        break;
                    }
                }

                if (emp) {
                    Attendance attendance(empId, date, "", "");
                    if (subChoice == 1) {
                        guard.markCheckIn(attendance, time); // Guard marks check-in
                        attendanceManager.markCheckIn(empId, date, time);
                        cout << "Check-in marked successfully.\n";
                    } else if (subChoice == 2) {
                        guard.markCheckOut(attendance, time); // Guard marks check-out
                        attendanceManager.markCheckOut(empId, date, time);
                        cout << "Check-out marked successfully.\n";
                    } else {
                        cout << "Invalid choice!\n";
                    }
                } else {
                    cout << "Employee not found!\n";
                }

                break;
            }
            case 3: {
                string empId, type, startDate, endDate, address, reason, appDate;
                cout << "Enter Employee ID: ";
                cin >> empId;
                cout << "Enter Leave Type (Casual/Earned/Official/Unpaid): ";
                cin >> type;
                cout << "Enter Start Date (YYYY-MM-DD): ";
                cin >> startDate;
                cout << "Enter End Date (YYYY-MM-DD): ";
                cin >> endDate;
                cout << "Enter Address During Leave: ";
                cin.ignore();
                getline(cin, address);
                cout << "Enter Reason for Leave: ";
                getline(cin, reason);
                cout << "Enter Application Date (YYYY-MM-DD): ";
                cin >> appDate;

                Employee* emp = nullptr;
                for (auto e : employees) {
                    if (e->getId() == empId) {
                        emp = e;
                        break;
                    }
                }

                if (emp) {
                    Leave* leave = nullptr;
                    if (type == "Casual")
                        leave = new CasualLeave(emp, empId, startDate, endDate, address, reason, appDate, "Pending");
                    else if (type == "Earned")
                        leave = new EarnedLeave(emp, empId, startDate, endDate, address, reason, appDate, "Pending");
                    else if (type == "Official")
                        leave = new OfficialLeave(emp, empId, startDate, endDate, address, reason, appDate, "Pending");
                    else if (type == "Unpaid")
                        leave = new UnpaidLeave(emp, empId, startDate, endDate, address, reason, appDate, "Pending");

                    if (leave) {
                        leaveManager.addLeave(leave);
                        cout << "Leave applied successfully!\n";
                    } else {
                        cout << "Invalid leave type!\n";
                    }
                } else {
                    cout << "Employee not found!\n";
                }

                break;
            }
            case 4: {
                string empId, type;
                cout << "Enter Employee ID: ";
                cin >> empId;
                cout << "Enter Leave Type: ";
                cin >> type;
                supervisor.approveLeave(leaveManager, empId, type);
                break;
            }
            case 5: {
                string empId, type;
                cout << "Enter Employee ID: ";
                cin >> empId;
                cout << "Enter Leave Type: ";
                cin >> type;
                director.approveLeave(leaveManager, empId, type);
                break;
            }
            case 6: {
                double threshold;
                cout << "Enter Weekly Hours Threshold: ";
                cin >> threshold;
                vector<string> report = attendanceManager.generateAttendanceReport(threshold);
                cout << "Attendance Report:\n";
                for (const auto& entry : report)
                    cout << entry << endl;
                break;
            }
            case 7: {
                string empId;
                cout << "Enter Employee ID: ";
                cin >> empId;
                vector<Leave*> leaves = leaveManager.getLeavesByEmpId(empId);
                cout << "Leave Status:\n";
                for (auto leave : leaves) {
                    cout << "Type: " << leave->gettype() 
                         << ", Status: " << leave->getstatus() << endl;
                }
                break;
            }
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    // Clean up dynamically allocated memory
    for (auto emp : employees)
        delete emp;

    return 0;
}
