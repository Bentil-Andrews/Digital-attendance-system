#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

// ================= STUDENT CLASS =================
class Student {
public:
    string indexNo;
    string fullName;

    Student(string i, string n) {
        indexNo = i;
        fullName = n;
    }
};

// ================= GLOBAL LIST =================
vector<Student> studentList;

// ================= WEEK 1 FUNCTIONS =================
void addStudent() {
    string index, name;
    cout << "Enter index number: ";
    cin >> index;
    cin.ignore(); // ignore leftover newline
    cout << "Enter full name: ";
    getline(cin, name);

    studentList.push_back(Student(index, name));
    cout << "Student added successfully.\n";
}

void viewStudents() {
    if (studentList.size() == 0) {
        cout << "No students registered yet.\n";
        return;
    }

    cout << "\nRegistered Students:\n";
    for (int i = 0; i < (int)studentList.size(); i++) {
        cout << studentList[i].indexNo << " - " << studentList[i].fullName << endl;
    }
}

// ================= WEEK 2 FUNCTION =================
void createSession() {
    string week;
    cout << "Enter week name (e.g. week1): ";
    cin >> week;

    ofstream file((week + "_attendance.txt").c_str());
    if (!file) {
        cout << "Error creating session file.\n";
        return;
    }

    for (int i = 0; i < (int)studentList.size(); i++) {
        file << studentList[i].indexNo << "," 
             << studentList[i].fullName << ",Absent" << endl;
    }

    file.close();
    cout << "Lecture session created for " << week << ".\n";
}

// ================= WEEK 3 FUNCTION =================
void markAttendance() {
    string week;
    cout << "Enter week name (e.g. week1): ";
    cin >> week;

    ifstream file((week + "_attendance.txt").c_str());
    if (!file) {
        cout << "Attendance file not found.\n";
        return;
    }

    vector<string> records;
    string line;
    while (getline(file, line)) {
        records.push_back(line);
    }
    file.close();

    ofstream out((week + "_attendance.txt").c_str());
    if (!out) {
        cout << "Error opening attendance file.\n";
        return;
    }

    for (int i = 0; i < (int)records.size(); i++) {
        string indexNo, name, status;
        int firstComma = records[i].find(',');
        int secondComma = records[i].find(',', firstComma + 1);

        if (firstComma == -1 || secondComma == -1) continue;

        indexNo = records[i].substr(0, firstComma);
        name = records[i].substr(firstComma + 1, secondComma - firstComma - 1);
        status = records[i].substr(secondComma + 1);

        cout << indexNo << " - " << name << " [Current: " << status << "]\n";
        cout << "Mark present? (1 = Yes, 0 = No): ";
        int choice;
        cin >> choice;
        if (choice == 1) status = "Present";

        out << indexNo << "," << name << "," << status << endl;
    }

    out.close();
    cout << "Attendance marked successfully.\n";
}

// ================= WEEK 4 FUNCTION =================
void viewReport() {
    string week;
    cout << "Enter week name (e.g. week1): ";
    cin >> week;

    ifstream file((week + "_attendance.txt").c_str());
    if (!file) {
        cout << "Attendance file not found.\n";
        return;
    }

    cout << "\nAttendance Report for " << week << ":\n";
    string line;
    while (getline(file, line)) cout << line << endl;

    file.close();
}

// ================= MAIN MENU =================
int main() {
    int option;

    do {
        cout << "\n===== DIGITAL ATTENDANCE SYSTEM =====\n";
        cout << "1. Register student (Week 1)\n";
        cout << "2. View students (Week 1)\n";
        cout << "3. Create lecture session (Week 2)\n";
        cout << "4. Mark attendance (Week 3)\n";
        cout << "5. View attendance report (Week 4)\n";
        cout << "0. Exit\n";
        cout << "Choose option: ";
        cin >> option;

        if (option == 1) addStudent();
        else if (option == 2) viewStudents();
        else if (option == 3) createSession();
        else if (option == 4) markAttendance();
        else if (option == 5) viewReport();
        else if (option != 0) cout << "Invalid option. Try again.\n";

    } while (option != 0);

    return 0;
}

