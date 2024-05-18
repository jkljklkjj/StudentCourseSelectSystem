#pragma once
#include "student.h"
#include <iostream>
#include <vector>
using namespace std;

class Course {
  private:
    int id;         // 课程号
    string name;    // 课程名
    int credit;     // 学分
    string teacher; // 教师
    int score;      // 考试成绩

  public:
    Course();
    Course(int, string, string, int);
    ~Course();

    void display() const;
    int getid() const;
    string getname() const;
};

class Coursedata {
  private:
    vector<Course> courses;

  public:
    void init_data();
    Course findCourse(const string &courseName) const; // 查找课程
    Course findCourse(int courseId) const;             // 查找课程
    void addCourse(Course);                            // 添加课程
    void removeCourse(const string &courseName); // 删除学生的某个课程
    void removeCourse(int courseId);             // 删除学生的某个课程
    void displayCourses() const;                 // 展示学生的所有课程
    void displayCourse(const string &courseName); // 展示学生的某个课程的具体信息
};