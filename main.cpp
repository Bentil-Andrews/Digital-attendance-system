#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Student {
public:
    string indexNo;
    string fullName;

    Student(string i, string n) {
        indexNo = i;
        fullName = n;
    }
};

vector<Student> studentList;

void addStudent() {
    string index, name;
    cout << "Enter index number: ";
    cin >> index;
    cin.ignore();
    cout << "Enter full name: ";
    getline(cin, name);
    studentList.push_back(Student(index, name));
}

void viewStudents() {
    for (int i = 0; i < studentList.size(); i++) {
        cout << studentList[i].indexNo << " - "
             << studentList[i].fullName << endl;
    }
}

// WEEK 2
void createSession() {
    string week;
    cout << "Enter week name (e.g. week2): ";
    cin >> week;

    ofstream file((week + "_attendance.txt").c_str());

    for (int i = 0; i < studentList.size(); i++) {
        file << studentList[i].indexNo << ","
             << studentList[i].fullName << ",Absent\n";
    }

    file.close();
    cout << "Session created.\n";
}

int main() {
    int option;

    do {
        cout << "\n1. Add student\n";
        cout << "2. View students\n";
        cout << "3. Create lecture session\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> option;

        if (option == 1) addStudent();
        else if (option == 2) viewStudents();
        else if (option == 3) createSession();

    } while (option != 0);

    return 0;
}

