#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    string indexNo;
    string fullName;
    Student(string i="", string n=""){ indexNo=i; fullName=n; }
};

vector<Student> studentList;

void loadStudents() {
    ifstream file("students.txt");
    if(!file) return;
    string line;
    while(getline(file,line)){
        int pos=line.find(',');
        if(pos==-1) continue;
        string index=line.substr(0,pos);
        string name=line.substr(pos+1);
        studentList.push_back(Student(index,name));
    }
    file.close();
}

void createSession() {
    string course, date, startTime;
    int duration;
    cout<<"Enter course code: "; cin>>course;
    cout<<"Enter date (YYYY-MM-DD): "; cin>>date;
    cout<<"Enter start time (HH:MM): "; cin>>startTime;
    cout<<"Enter duration (hours): "; cin>>duration;

    string filename = course + "_" + date + "_attendance.txt";
    ofstream file(filename.c_str());
    for(int i=0;i<(int)studentList.size();i++)
        file<<studentList[i].indexNo<<","<<studentList[i].fullName<<",Absent"<<endl;
    file.close();
    cout<<"Lecture session created: "<<filename<<endl;
}

int main() {
    loadStudents();
    int option;
    do{
        cout<<"\n===== DIGITAL ATTENDANCE SYSTEM =====\n";
        cout<<"1. Create lecture session\n0. Exit\nChoose option: ";
        cin>>option;
        switch(option){
            case 1: createSession(); break;
            case 0: break;
            default: cout<<"Invalid option.\n";
        }
    }while(option!=0);
    return 0;
}

