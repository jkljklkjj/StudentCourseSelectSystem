#pragma once
#include <iostream>
#include <vector>
#include "student.h"
using namespace std;

class Course {
  private:
    int id;
    string name;
    string instructor;
    int credit;
    string teacher;

  public:
    Course(int, string, string, int);
    ~Course();

    void display();
};

class Coursedata {
  private:
    vector<Course> courses;

  public:
    Coursedata();
    ~Coursedata();
    void addCourse(Course);
    void removeCourse(const string& courseName);//删除学生的某个课程
    void displayCourses();//展示学生的所有课程
    void displayCourse(const string& courseName);//展示学生的某个课程的具体信息
    // void displayStudents(int);//同下
    // void addStudent(int, Student);//可以是第二次才实现的功能
    // void removeStudent(int, int);
    // void displayStudent(int, int);
    // void displayAllStudents();
    // void displayAllCourses();
};