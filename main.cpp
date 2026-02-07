#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    string indexNo;
    string fullName;
    Student(string i = "", string n = "") { indexNo = i; fullName = n; }
};

vector<Student> studentList;

void loadStudents() {
    ifstream file("students.txt");
    if (!file) return;
    string line;
    while (getline(file, line)) {
        int pos = line.find(',');
        if (pos == -1) continue;
        string index = line.substr(0,pos);
        string name = line.substr(pos+1);
        studentList.push_back(Student(index,name));
    }
    file.close();
}

void saveStudents() {
    ofstream file("students.txt");
    for (int i=0;i<(int)studentList.size();i++)
        file << studentList[i].indexNo << "," << studentList[i].fullName << endl;
    file.close();
}

void addStudent() {
    string index, name;
    cout << "Enter index number: "; cin >> index;
    cin.ignore();
    cout << "Enter full name: "; getline(cin,name);
    studentList.push_back(Student(index,name));
    saveStudents();
    cout << "Student added successfully.\n";
}

void viewStudents() {
    if(studentList.size()==0){cout<<"No students registered yet.\n";return;}
    cout<<"\nRegistered Students:\n";
    for(int i=0;i<(int)studentList.size();i++)
        cout<<studentList[i].indexNo<<" - "<<studentList[i].fullName<<endl;
}

void searchStudent() {
    string index;
    cout<<"Enter index number to search: "; cin>>index;
    for(int i=0;i<(int)studentList.size();i++){
        if(studentList[i].indexNo==index){
            cout<<"Student found: "<<studentList[i].indexNo<<" - "<<studentList[i].fullName<<endl;
            return;
        }
    }
    cout<<"Student not found.\n";
}

int main() {
    loadStudents();
    int option;
    do{
        cout<<"\n===== DIGITAL ATTENDANCE SYSTEM =====\n";
        cout<<"1. Register student\n2. View students\n3. Search student\n0. Exit\nChoose option: ";
        cin>>option;
        switch(option){
            case 1:addStudent();break;
            case 2:viewStudents();break;
            case 3:searchStudent();break;
            case 0:break;
            default: cout<<"Invalid option.\n";
        }
    }while(option!=0);
    return 0;
}

