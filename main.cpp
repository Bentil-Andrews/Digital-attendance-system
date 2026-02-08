#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// ================= STUDENT CLASS =================
class Student {
public:
    string indexNumber;
    string fullName;
};

// ================= GLOBAL DATA =================
Student students[100];
int studentCount = 0;

// ================= FILE HANDLING (WEEK 4) =================
void loadStudents() {
    ifstream file("students.txt");
    if (!file)
        return;

    studentCount = 0;

    while (file >> students[studentCount].indexNumber) {
        file.ignore();
        getline(file, students[studentCount].fullName);
        studentCount++;
    }

    file.close();
}

void saveStudents() {
    ofstream file("students.txt");

    for (int i = 0; i < studentCount; i++) {
        file << students[i].indexNumber << " "
             << students[i].fullName << endl;
    }

    file.close();
}

// ================= WEEK 1 =================
void addStudent() {
    cout << "Enter index number: ";
    cin >> students[studentCount].indexNumber;
    cin.ignore();

    cout << "Enter full name: ";
    getline(cin, students[studentCount].fullName);

    studentCount++;
    cout << "Student registered successfully.\n";
}

void viewStudents() {
    if (studentCount == 0) {
        cout << "No students registered.\n";
        return;
    }

    cout << "\n--- Registered Students ---\n";
    for (int i = 0; i < studentCount; i++) {
        cout << students[i].indexNumber << " - "
             << students[i].fullName << endl;
    }
}

// ================= WEEK 2 =================
void createLectureSession() {
    string courseCode, date;

    cout << "Enter course code: ";
    cin >> courseCode;

    cout << "Enter date (YYYY-MM-DD): ";
    cin >> date;

    string fileName = courseCode + "_" + date + "_attendance.txt";
    ofstream file(fileName.c_str());

    for (int i = 0; i < studentCount; i++) {
        file << students[i].indexNumber << ","
             << students[i].fullName << ",Absent\n";
    }

    file.close();
    cout << "Lecture session created.\n";
}

// ================= WEEK 3 =================
void markAttendance() {
    string fileName;
    cout << "Enter attendance file name: ";
    cin >> fileName;

    ifstream file(fileName.c_str());
    if (!file) {
        cout << "File not found.\n";
        return;
    }

    string lines[200];
    int count = 0;

    while (getline(file, lines[count])) {
        count++;
    }
    file.close();

    ofstream out(fileName.c_str());

    for (int i = 0; i < count; i++) {
        cout << lines[i] << endl;
        cout << "P = Present, L = Late, A = Absent: ";

        char ch;
        cin >> ch;

        lines[i] = lines[i].substr(0, lines[i].find_last_of(',')) + ",";

        if (ch == 'P' || ch == 'p')
            lines[i] += "Present";
        else if (ch == 'L' || ch == 'l')
            lines[i] += "Late";
        else
            lines[i] += "Absent";

        out << lines[i] << endl;
    }

    out.close();
    cout << "Attendance updated.\n";
}

void viewAttendanceReport() {
    string fileName;
    cout << "Enter attendance file name: ";
    cin >> fileName;

    ifstream file(fileName.c_str());
    if (!file) {
        cout << "File not found.\n";
        return;
    }

    string line;
    int p = 0, l = 0, a = 0;

    cout << "\n--- Attendance Report ---\n";

    while (getline(file, line)) {
        cout << line << endl;

        if (line.find("Present") != string::npos)
            p++;
        else if (line.find("Late") != string::npos)
            l++;
        else
            a++;
    }

    file.close();

    cout << "\nSummary\n";
    cout << "Present: " << p << endl;
    cout << "Late: " << l << endl;
    cout << "Absent: " << a << endl;
}

// ================= MAIN =================
int main() {
    loadStudents();   // WEEK 4 addition

    int choice;
    do {
        cout << "\nDIGITAL ATTENDANCE SYSTEM\n";
        cout << "1. Register student\n";
        cout << "2. View students\n";
        cout << "3. Create lecture session\n";
        cout << "4. Mark attendance\n";
        cout << "5. View attendance report\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
            addStudent();
        else if (choice == 2)
            viewStudents();
        else if (choice == 3)
            createLectureSession();
        else if (choice == 4)
            markAttendance();
        else if (choice == 5)
            viewAttendanceReport();

    } while (choice != 0);

    saveStudents();   // WEEK 4 addition
    return 0;
}

