#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// ================= STUDENT CLASS =================
class Student {
public:
    string indexNumber;
    string name;

    Student(string idx, string n) {
        indexNumber = idx;
        name = n;
    }
};

// ================= GLOBAL STORAGE =================
vector<Student> students;

// ================= STUDENT MANAGEMENT =================
void addStudent() {
    string idx, name;

    cout << "Enter Index Number: ";
    cin >> idx;
    cin.ignore();
    cout << "Enter Student Name: ";
    getline(cin, name);

    students.push_back(Student(idx, name));
    cout << "Student added successfully!\n";
}

void viewStudents() {
    cout << "\n--- Registered Students ---\n";
    for (int i = 0; i < students.size(); i++) {
        cout << students[i].indexNumber
             << " - "
             << students[i].name << endl;
    }
}

// ================= WEEK 2: LECTURE SESSION =================
void createSession() {
    string course, date;
    cout << "Enter Course Code: ";
    cin >> course;
    cout << "Enter Date (YYYY-MM-DD): ";
    cin >> date;

    string filename = "session_" + course + "_" + date + ".txt";
    ofstream file(filename.c_str());

    for (int i = 0; i < students.size(); i++) {
        file << students[i].indexNumber << " "
             << students[i].name << " Absent\n";
    }
    file.close();

    cout << "Lecture session created successfully!\n";
}

// ================= MAIN PROGRAM =================
int main() {
    int choice;
    do {
        cout << "\n=== WEEK 2 MENU ===\n";
        cout << "1. Register Student\n";
        cout << "2. View Students\n";
        cout << "3. Create Lecture Session\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) addStudent();
        else if (choice == 2) viewStudents();
        else if (choice == 3) createSession();

    } while (choice != 0);

    return 0;
}

