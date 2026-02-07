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
    cin >> index;
    cin.ignore();
    getline(cin, name);
    studentList.push_back(Student(index, name));
}

void viewStudents() {
    for (int i = 0; i < studentList.size(); i++) {
        cout << studentList[i].indexNo << " "
             << studentList[i].fullName << endl;
    }
}

void createSession() {
    string week;
    cin >> week;
    ofstream file((week + "_attendance.txt").c_str());
    for (int i = 0; i < studentList.size(); i++) {
        file << studentList[i].indexNo << ","
             << studentList[i].fullName << ",Absent\n";
    }
    file.close();
}

// WEEK 3
void markAttendance() {
    string week;
    cin >> week;

    ifstream file((week + "_attendance.txt").c_str());
    if (!file) {
        cout << "Session not found.\n";
        return;
    }

    vector<string> records;
    string line;
    while (getline(file, line)) {
        records.push_back(line);
    }
    file.close();

    ofstream out((week + "_attendance.txt").c_str());
    for (int i = 0; i < records.size(); i++) {
        cout << records[i] << endl;
        cout << "Present? (1=yes 0=no): ";
        int p;
        cin >> p;

        if (p == 1) {
            int pos = records[i].find("Absent");
            records[i].replace(pos, 6, "Present");
        }
        out << records[i] << endl;
    }
    out.close();
}

int main() {
    int option;
    do {
        cout << "1.Add\n2.View\n3.Session\n4.Mark\n0.Exit\n";
        cin >> option;

        if (option == 1) addStudent();
        else if (option == 2) viewStudents();
        else if (option == 3) createSession();
        else if (option == 4) markAttendance();

    } while (option != 0);

    return 0;
}

