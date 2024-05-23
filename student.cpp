#include "student.h"
#include "system.h"
#include <iostream>
#include <thread>
#include <functional>
#include <algorithm>
using namespace std;

Student::Student(long long id, string name, string password)
    : id(id), name(name), password(password) {}

Student::Student()
{
    id = 0;
    name = "";
    password = "";
}

Student::~Student() {}

void Studentdata::init_data()
{
    Student student1(20232005036, "陈振业", Login::caesarEncrypt("123456"));
    Student student2(2, "李四", Login::caesarEncrypt("123456"));
    Student student3(3, "王五", Login::caesarEncrypt("123456"));
    Student student4(4, "赵六", Login::caesarEncrypt("123456"));
    Student student5(5, "孙七", Login::caesarEncrypt("123456"));
    Student student6(6, "周八", Login::caesarEncrypt("123456"));
    Student student7(7, "吴九", Login::caesarEncrypt("123456"));
    Student student8(8, "郑十", Login::caesarEncrypt("123456"));
    Student student9(9, "钱十一", Login::caesarEncrypt("123456"));
    Student student10(10, "马十二", Login::caesarEncrypt("123456"));
    Student student11(11, "test", Login::caesarEncrypt("abc123"));
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
    sortByid();
}

void Student::display() const
{
    cout << "学生ID: " << id;
    cout << "\t学生姓名: " << name;
}

void Student::displayAllCourses()
{
    StudentCourses.displayCourses();
}

void Student::setPassword(string password) { this->password = password; }

long long Student::getid() const { return id; }

string Student::getpassword() const { return password; }

string Student::getname() const { return name; }

void Student::setStudent(long long id, string name, string password)
{
    this->id = id;
    this->name = name;
    this->password = password;
}

void Studentdata::addStudent(const Student &student)
{
    students.push_back(student);
    sortByid();
}

Student Studentdata::findStudent(long long id) const
{
    int left = 0;
    int right = students.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (students[mid].getid() == id)
        {
            return students[mid];
        }
        if (students[mid].getid() < id)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << "未找到学号为" << id << "的学生" << endl;
    return Student(); // 返回一个默认的 Student 对象
}

Student &Studentdata::find_TrueStudent(long long id)
{
    int left = 0;
    int right = students.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (students[mid].getid() == id)
        {
            return students[mid];
        }
        if (students[mid].getid() < id)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << "未找到学号为" << id << "的学生" << endl;
    static Student defaultStudent; // 定义一个静态的 Student 对象
    return defaultStudent;         // 返回默认的 Student 对象
}

void Studentdata::sortByid()
{ // 根据学号来进行快速排序
    auto partition = [](vector<Student> &students, int low, int high)
    {
        Student pivot = students[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++)
        {
            if (students[j].getid() < pivot.getid())
            {
                i++;
                swap(students[i], students[j]);
            }
        }
        swap(students[i + 1], students[high]);
        return (i + 1);
    };

    function<void(int, int)> quickSort;
    quickSort = [&](int low, int high)
    {
        if (low < high)
        {
            int pi = partition(students, low, high);

            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    };

    quickSort(0, students.size() - 1);
}

void Student::addCourse(Course course)
{
    StudentCourses.addCourse(course);
}

void Student::removeCourse(const string &courseName)
{
    StudentCourses.removeCourse(courseName);
}

Course Student::findCourse(const string &courseName) const
{
    return StudentCourses.find_TrueCourse(courseName);
}

Course Student::findCourse(int courseId) const
{
    return StudentCourses.find_TrueCourse(courseId);
}

void Studentdata::changePassword(long long id, string password)
{
    Student student = findStudent(id);
    student.setPassword(password);
}

void Studentdata::displayAllStudents()
{
    for (int i = 0; i < students.size(); i++)
    {
        students[i].display();
        cout << endl;
    }
}

void Studentdata::removeStudent(long long id)
{
    int left = 0;
    int right = students.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (students[mid].getid() == id)
        {
            students.erase(students.begin() + mid);
            cout << "学生" << id << "已删除" << endl;
            return;
        }
        else if (students[mid].getid() < id)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << "未找到学生" << id << endl;
}