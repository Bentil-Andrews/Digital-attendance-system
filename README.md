
# 📚 Digital Attendance System

A simple console-based **Digital Attendance System** developed in C++ that allows student registration, searching, and lecture session creation using file handling.

---

Features

### 👨‍🎓 Student Management
- Register new students
- View all registered students
- Search for a student using index number
- Stores student records in `students.txt`
 Session Management
- Create lecture sessions
- Stores session details in separate text files
- Includes:
  - Course Code
  - Date
  - Start Time
  - Duration

---

Technologies Used

- C++
- File Handling (`fstream`)
- Standard Input/Output
- Console-based interface

---
 File Structure

```
Digital-Attendance-System/
│
├── main.cpp
├── students.txt
├── session_<coursecode>_<date>.txt
└── README.md
```

---

## ▶️ How to Run

1. Compile the program:

```
g++ main.cpp -o attendance
```

2. Run the program:

```
./attendance
```

---
 Menu Options

```
1. Register Student
2. View Students
3. Search Student
4. Create Lecture Session
5. Exit
```

---
 Learning Objectives

This project demonstrates:

- File handling in C++
- Functions and modular programming
- Menu-driven console applications
- Basic data storage and retrieval
- String manipulation

---

 Future Improvements

- Add attendance marking feature
- Generate attendance reports
- Use structured data instead of plain text
- Implement login authentication
- Add error handling for files

---
 Author

**Bentil-Andrews**  
GitHub: https://github.com/Bentil-Andrews
📜 License

This project is for academic and learning purposes.
