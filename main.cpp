#include <iostream>
#include <vector>

using namespace std;

// student information
class Student {
public:
    string indexNo;
    string fullName;

    Student(string i, string n) {
        indexNo = i;
        fullName = n;
    }
};

// list to store students
vector<Student> studentList;

// add a new student
void addStudent() {
    string index, name;

    cout << "Enter index number: ";
    cin >> index;
    cin.ignore();

    cout << "Enter full name: ";
    getline(cin, name);

    studentList.push_back(Student(index, name));
    cout << "Student added successfully.\n";
}

// display all students
void viewStudents() {
    cout << "\nRegistered Students:\n";

    if (studentList.size() == 0) {
        cout << "No students registered yet.\n";
        return;
    }

    for (int i = 0; i < studentList.size(); i++) {
        cout << i + 1 << ". "
             << studentList[i].indexNo
             << " - "
             << studentList[i].fullName << endl;
    }
}

int main() {
    int option;

    do {
        cout << "\n===== STUDENT REGISTRATION =====\n";
        cout << "1. Add student\n";
        cout << "2. View students\n";
        cout << "0. Exit\n";
        cout << "Choose option: ";
        cin >> option;

        if (option == 1) {
            addStudent();
        } else if (option == 2) {
            viewStudents();
        }

    } while (option != 0);

    return 0;
}

