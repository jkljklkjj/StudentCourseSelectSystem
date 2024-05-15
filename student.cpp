#include "student.h"
#include "course.h"
#include <iostream>
using namespace std;

Student::Student(long long id, string name, string password)
    : id(id), name(name), password(password) {}

Student::~Student() { cout << "学生" << name << "的信息已删除" << endl; }

void Studentdata::init_data() {
    Student student1(20232005036, "陈振业", "123456");
    Student student2(2, "李四", "123456");
    Student student3(3, "王五", "123456");
    Student student4(4, "赵六", "123456");
    Student student5(5, "孙七", "123456");
    Student student6(6, "周八", "123456");
    Student student7(7, "吴九", "123456");
    Student student8(8, "郑十", "123456");
    Student student9(9, "钱十一", "123456");
    Student student10(10, "马十二", "123456");
    Student student11(11, "test", "abc123");
    addStudent(student1);
    addStudent(student2);
    addStudent(student3);
    addStudent(student4);
    addStudent(student5);
    addStudent(student6);
    addStudent(student7);
    addStudent(student8);
    addStudent(student9);
    addStudent(student10);
}

void Student::display() {
    cout << "学生ID: " << id << endl;
    cout << "学生姓名: " << name << endl;
    cout << "学生所选课程: " << endl;
    courses.displayCourses();
}

void Student::setPassword(string password) { this->password = password; }

int Student::getid() { return id; }

void Studentdata::displayAllStudents() {
    for (int i = 0; i < students.size(); i++) {
        students[i].display();
    }
}

void Studentdata::addStudent(Student student) { students.push_back(student); }

void Student::addCourse(Course course) { courses.addCourse(course); }

void Student::removeCourse(const string& courseName) {
    courses.removeCourse(courseName);
}

Course Student::findCourse(const string& courseName) {
    courses.findCourse(courseName);
}

void Student::displayAllCourses() { courses.displayCourses(); }