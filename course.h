#pragma once
#include <iostream>
#include <vector>
#include "student.h"
using namespace std;

class Course {
  private:
    int id;//课程号
    string name;//课程名
    int credit;//学分
    string teacher;//教师
    int score;//考试成绩

  public:
    Course(int, string, int, string);
    ~Course();

    void display();
};

class Coursedata {
  private:
    vector<Course> courses;

  public:
    void init_data();
    void findCourse(const string& courseName);//查找课程
    void findCourse(int courseId);//查找课程
    void addCourse(Course);//添加课程
    void removeCourse(const string& courseName);//删除学生的某个课程
    void removeCourse(int courseId);//删除学生的某个课程
    void displayCourses();//展示学生的所有课程
    void displayCourse(const string& courseName);//展示学生的某个课程的具体信息
};