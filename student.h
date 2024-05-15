#pragma once
#include "course.h"
#include <iostream>
#include <vector>
using namespace std;

class Student {
  private:
    // 记录了学生的id，姓名，密码，以及所选的课程
    int id;
    string name;
    string password;
    Coursedata courses;

  public:
    Student(int, string, string); 
    ~Student();

    void display();
};

class Studentdata {
  private:
    vector<Student> students;

  public:
    Studentdata(); // 构造函数
    ~Studentdata();
    void addStudent(Student); // 添加学生
    void displayAllStudents();
};