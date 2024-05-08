#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Student {
  private:
  //记录了学生的id，姓名，密码，以及所选的课程
    int id;
    string name;
    string password;
    vector<Course> courses;

  public:
    Student(int, string, string , vector<Course>);
    ~Student();
};

class Studentdata {
  private:
    vector<Student> students;

  public:
    Studentdata();//构造函数
    ~Studentdata();
    void addStudent(Student);//添加学生
    void removeStudent(int);
    void displayStudents();
    void displayStudent(int);
    void displayCourses(int);
    void addCourse(int, Course);
    void removeCourse(int, int);
    void displayCourse(int, int);
    void displayAllCourses();
    void displayAllStudents();
};