#include "student.h"
#include <iostream>
using namespace std;

Student::Student(long long id, string name, string password)
    : id(id), name(name), password(password) {}

Student::Student() {}

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

void Student::display() const {
    cout << "学生ID: " << id << endl;
    cout << "学生姓名: " << name << endl;
    cout << "学生所选课程: " << endl;
    courses.displayCourses();
}

void Student::setPassword(string password) { this->password = password; }

int Student::getid() const { return id; }

string Student::getpassword() const { return password; }

string Student::getname() const { return name; }

void Student::setStudent(long long id, string name, string password) {
    this->id = id;
    this->name = name;
    this->password = password;
}

void Studentdata::addStudent(Student student) { students.push_back(student); }

Student Studentdata::findStudent(long long id) const {
    int left = 0;
    int right = students.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (students[mid].getid() == id) {
            students[mid].display();
            return students[mid];
        }
        if (students[mid].getid() < id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << "未找到学号为" << id << "的学生" << endl;
    return Student(); // 返回一个默认的 Student 对象
}

void Student::addCourse(Course course) { courses.addCourse(course); }

void Student::removeCourse(const string &courseName) {
    courses.removeCourse(courseName);
}

Course Student::findCourse(const string &courseName) const {
    return courses.findCourse(courseName);
}

Course Student::findCourse(int courseId) const { return courses.findCourse(courseId); }

void Student::displayAllCourses() { courses.displayCourses(); }