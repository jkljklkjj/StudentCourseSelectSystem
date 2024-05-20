#pragma once
#include "course.h"
#include <iostream>
#include <vector>
using namespace std;

class Student {
  private:
    // 记录了学生的id，姓名，密码，以及所选的课程
    long long id;
    string name;
    string password;
    Coursedata courses;

  public:
    Student();
    Student(long long id, string name, string password);
    void setStudent(long long, string, string);
    ~Student();
    void display() const;       // 展示学生信息
    void setPassword(string);   // 设置密码
    int getid() const;          // 获取学生id
    string getname() const;     // 获取学生姓名
    string getpassword() const; // 添加课程
    void addCourse(Course);
    void removeCourse(const string &courseName);
    Course findCourse(const string &courseName) const;
    Course findCourse(int courseId) const;
    void displayAllCourses();
};

class Studentdata {
  private:
    vector<Student> students;

  public:
    void init_data();                        // 初始化数据
    void addStudent(const Student &student); // 添加学生
    Student findStudent(long long) const;    // 查找学生
    void sortByid();
    void changePassword(long long id, string password); // 修改密码
    Student& find_TrueStudent(long long id);
};