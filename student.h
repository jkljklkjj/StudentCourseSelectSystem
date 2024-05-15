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
    setStudent(int, string, string);
    Student(int, string, string); 
    ~Student();

    void display();//展示学生信息
    void setPassword(string);//设置密码
    int getid();//获取学生id
};

class Studentdata {
  private:
    vector<Student> students;

  public:
    Studentdata(); // 构造函数
    ~Studentdata();
    void init_data(); // 初始化数据
    void addStudent(Student); // 添加学生
    
    void addCourse(Course);
    void removeCourse(const string& courseName);
    Course findCourse(const string& courseName);
    Course findCourse(int courseId);
    void displayAllCourses();
};