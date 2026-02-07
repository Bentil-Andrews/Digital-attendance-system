#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main(){

string week;
    cout << "Enter week name (e.g. week1): ";
    cin >> week;

    ifstream file((week + "_attendance.txt").c_str());

    if (!file) {
        cout << "Attendance file not found.\n";
        return 0;
    }

    cout << "\nAttendance Report:\n";
    string line;

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}



    
