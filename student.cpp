#include "student.h"
#include<iostream>
using namespace std;

Student::Student(int id, string name, string password) {
    //构造函数，学号，姓名，密码
    this->id = id;
    this->name = name;
    this->password = password;
}

Student::~Student() {
    cout<<"学生"<<name<<"的信息已删除"<<endl;
}

void Student::display() {
    cout << "学生ID: " << id << endl;
    cout << "学生姓名: " << name << endl;
    cout << "学生密码: " << password << endl;
    cout << "学生所选课程: " << endl;
    courses.displayCourses();
}

void Studentdata::displayAllStudents() {
    for (int i = 0; i < students.size(); i++) {
        students[i].display();
    }
}

void Studentdata::addStudent(Student student) {
    students.push_back(student);
}