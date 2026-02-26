#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Student class
class Student {
public:
    string indexNumber;
    string name;

    Student(string i, string n) {
        indexNumber = i;
        name = n;
    }
};

// Attendance Record
class Attendance {
public:
    string indexNumber;
    string name;
    string status;

    Attendance(string i, string n, string s) {
        indexNumber = i;
        name = n;
        status = s;
    }
};

// global lists
vector<Student> students;
vector<Attendance> records;

// ------------------ STUDENT FUNCTIONS ------------------
void addStudent() {
    string index, name;

    cout << "Enter Index Number: ";
    cin >> index;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    students.push_back(Student(index, name));
    cout << "Student added successfully.\n";
}

void viewStudents() {
    cout << "\n--- STUDENT LIST ---\n";
    for (int i = 0; i < students.size(); i++) {
        cout << students[i].indexNumber << " - " << students[i].name << endl;
    }
}

// ------------------ ATTENDANCE ------------------
void markAttendance() {
    string index, status;
    bool found = false;

    cout << "Enter Student Index: ";
    cin >> index;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].indexNumber == index) {
            cout << "Enter Status (Present/Absent/Late): ";
            cin >> status;

            records.push_back(
                Attendance(students[i].indexNumber,
                           students[i].name,
                           status)
            );

            cout << "Attendance Recorded!\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found!\n";
    }
}

// ------------------ REPORT ------------------
void showSummary() {
    int present = 0, absent = 0, late = 0;

    for (int i = 0; i < records.size(); i++) {
        if (records[i].status == "Present") present++;
        else if (records[i].status == "Absent") absent++;
        else if (records[i].status == "Late") late++;
    }

    cout << "\n--- ATTENDANCE SUMMARY ---\n";
    cout << "Present: " << present << endl;
    cout << "Absent : " << absent << endl;
    cout << "Late   : " << late << endl;
}

// ------------------ EXPORT TO EXCEL ------------------
void exportToCSV() {
    ofstream file("attendance_report.csv");

    file << "Index Number,Name,Status\n";

    for (int i = 0; i < records.size(); i++) {
        file << records[i].indexNumber << ","
             << records[i].name << ","
             << records[i].status << "\n";
    }

    file.close();

    cout << "\nAttendance exported to Excel file successfully!\n";
    cout << "File name: attendance_report.csv\n";
}

// ------------------ MAIN MENU ------------------
int main() {
    int choice;

    do {
        cout << "\n===== DIGITAL ATTENDANCE SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Mark Attendance\n";
        cout << "4. Show Summary\n";
        cout << "5. Export to Excel (CSV)\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: markAttendance(); break;
            case 4: showSummary(); break;
            case 5: exportToCSV(); break;
        }

    } while (choice != 0);

    return 0;
}
