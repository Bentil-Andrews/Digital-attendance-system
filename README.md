
# 📚 Digital Attendance System
PROJECT DESCRIPTION

This project is a console-based Digital Attendance System developed using C++.

The system replaces the traditional paper-based attendance system used in lecture halls. 
It allows students to be registered, lecture sessions to be created, attendance to be marked, 
and attendance reports to be generated.

The program runs offline on Windows and stores data using text files to ensure persistence.


OBJECTIVES

- Apply C++ programming concepts to solve a real-world problem
- Use file handling (fstream) for data storage
- Design a menu-driven console application
- Practice version control using GitHub
- Implement structured and readable C++ code


DEVELOPMENT TOOLS

Programming Language: C++
Development Environment: Dev C++ / VS Code
Platform: Windows (Offline)
File Handling: fstream
Version Control: GitHub


PROJECT STRUCTURE

digital-attendance-system/
│── main.cpp
│── README.md
│── students.txt
│── session_courseCode_date.txt


FEATURES IMPLEMENTED

1. Student Management
   - Register students
   - View registered students
   - Search students by index number

2. Lecture Session Management
   - Create lecture session (course code, date, start time, duration)
   - Automatically generates session file
   - Mark attendance (Present / Absent / Late)
   - Update attendance records

3. Reports and Summary
   - Display attendance list for a session
   - Display attendance summary (Present, Absent, Late counts)

4. File Storage
   - Students saved in students.txt
   - Each session saved as a separate file
   - Data persists after program is closed


HOW TO RUN THE PROGRAM

1. Open Dev C++ or VS Code
2. Open main.cpp
3. Compile the program
4. Run the executable
5. Use the menu options to interact with the system


WEEKLY PROGRESS SUMMARY

Week 1:
- Project setup
- Student registration feature
- View and search students

Week 2:
- Session creation feature
- Improved menu structure

Week 3:
- Attendance marking functionality
- Attendance display and summary
- Input validation improvement

Week 4:
- Update attendance feature
- File handling refinement
- Final testing and documentation


KEY C++ CONCEPTS USED

- Functions
- File handling (ifstream and ofstream)
- Loops
- Conditional statements
- String manipulation
- Menu-driven program design


TESTING

The program was tested by:
- Registering multiple students
- Creating multiple sessions
- Marking attendance
- Updating attendance records
- Generating attendance summaries

All features work correctly and data is saved between executions.


CONCLUSION

This project demonstrates how C++ can be used to develop a practical digital attendance system.

The system improves efficiency compared to paper-based attendance and ensures organized and reliable record keeping. Add error handling for files

---
 Author

**Bentil-Andrews**  
GitHub: https://github.com/Bentil-Andrews
📜 License

This project is for academic and learning purposes.


## 📊 How I Converted My C++ Attendance System into Excel Format

### 🔹 Introduction

In my project, I was asked to display attendance in a **table or Excel form**.
Since C++ does not easily create real Excel files (`.xlsx`), I used a simpler method called **CSV (Comma Separated Values)**.

A CSV file can be opened directly in **Microsoft Excel** and it will automatically appear as a table.

---

### 🔹 What is a CSV File?

A CSV file is just a **normal text file** where:

* Each line = one row in Excel
* Each comma = separates columns

Example of CSV:

```
Index Number,Name,Status
ATU12345,John Mensah,Present
ATU67890,Akosua Boateng,Late
```

When this is opened in Excel, it becomes a proper table.

---

### 🔹 How I Implemented It in My C++ Code

To achieve this, I used **file handling in C++** using the `fstream` library.

#### Step 1: Include file library

```cpp
#include <fstream>
```

---

#### Step 2: Create the export function

I created a function called:

```cpp
void exportToCSV()
```

This function is responsible for creating the Excel file.

---

#### Step 3: Create the CSV file

Inside the function I used:

```cpp
ofstream file("attendance_report.csv");
```

This creates a file called:

```
attendance_report.csv
```

in the same folder as my program.

---

#### Step 4: Add column titles

I wrote the first line as:

```cpp
file << "Index Number,Name,Status\n";
```

These are the column headings that appear in Excel.

---

#### Step 5: Write attendance records

My program stores attendance in a vector called `records`.
So I used a loop to write all records:

```cpp
for (int i = 0; i < records.size(); i++) {
    file << records[i].indexNumber << ","
         << records[i].name << ","
         << records[i].status << "\n";
}
```

Each line becomes one row in Excel.

---

#### Step 6: Close the file

Finally I closed the file using:

```cpp
file.close();
```

This saves everything correctly.

---

### 🔹 How I Connected It to the Menu

In my main menu, I added:

```cpp
cout << "5. Export to Excel (CSV)\n";
```

So when the user selects option **5**, the program calls:

```cpp
exportToCSV();
```

---

### 🔹 What Happens When the Program Runs

1. I add students
2. I mark attendance
3. I select **Export to Excel**
4. The system creates the file:

```
attendance_report.csv
```

---

### 🔹 Opening the File in Excel

To open it:

1. Go to the project folder
2. Find `attendance_report.csv`
3. Double click it

It will open automatically in Excel as a table like this:

| Index Number | Name           | Status  |
| ------------ | -------------- | ------- |
| ATU12345     | John Mensah    | Present |
| ATU67890     | Akosua Boateng | Late    |

---

### 🔹 Why I Chose CSV Method

I used CSV because:

* It is simple to implement in C++
* It does not require external libraries
* It works perfectly with Microsoft Excel
* It produces a clean table for attendance

---

### 🔹 Challenges I Faced

While doing this part, I faced some small challenges like:

* Learning how to use `ofstream`
* Making sure commas separate the values correctly
* Making sure the file closes properly so data is saved

---

### 🔹 Conclusion

By using **C++ file handling and CSV format**, I was able to successfully convert my attendance system output into a **table that opens in Excel**.

This approach is simple, effective, and meets the requirement of showing attendance in **Excel/table form**.

