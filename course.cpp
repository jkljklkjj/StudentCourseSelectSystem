#include "course.h"
#include <iostream>
using namespace std;

void Course::display() const{
    cout << "课程ID: " << id << " ";
    cout << "课程名称: " << name << " ";
    cout << "课程学分: " << credit << " ";
    cout << "课程教师: " << teacher << endl;
}

void Coursedata::init_data() {
    Course course1(1, "高等数学", "张三", 4);
    Course course2(2, "线性代数", "李四", 3);
    Course course3(3, "大学英语", "王五", 2);
    Course course4(4, "C++程序设计", "赵六", 3);
    Course course5(5, "数据结构", "钱七", 3);
    Course course6(6, "计算机组成原理", "孙八", 3);
    Course course7(7, "操作系统", "周九", 3);
    Course course8(8, "计算机网络", "吴十", 3);
    Course course9(9, "数据库系统", "刘一", 3);
    Course course10(10, "软件工程", "陈二", 3);
    Course course11(11, "人工智能", "张三", 3);
    Course course12(12, "机器学习", "李四", 3);
    Course course13(13, "深度学习", "王五", 3);
    Course course14(14, "网络安全", "赵六", 3);
    Course course15(15, "编译原理", "钱七", 3);
    Course course16(16, "计算机图形学", "孙八", 3);
    Course course17(17, "虚拟现实", "周九", 3);
    Course course18(18, "云计算", "吴十", 3);
    
    courses.push_back(course1);
    courses.push_back(course2);
    courses.push_back(course3);
    courses.push_back(course4);
    courses.push_back(course5);
    courses.push_back(course6);
    courses.push_back(course7);
    courses.push_back(course8);
    courses.push_back(course9);
    courses.push_back(course10);
    courses.push_back(course11);
    courses.push_back(course12);
    courses.push_back(course13);
    courses.push_back(course14);
    courses.push_back(course15);
    courses.push_back(course16);
    courses.push_back(course17);
    courses.push_back(course18);
}

void Coursedata::addCourse(Course course) { courses.push_back(course); }

void Coursedata::removeCourse(const string& courseName) {
    for (int i = 0; i < courses.size(); i++) {
        if (courses[i].getname() == courseName) {
            courses.erase(courses.begin() + i);
            cout << "课程" << courseName << "已删除" << endl;
            return;
        }
    }
    cout << "未找到课程" << courseName << endl;
}

void Coursedata::removeCourse(int courseId) {
    for (int i = 0; i < courses.size(); i++) {
        if (courses[i].getid() == courseId) {
            courses.erase(courses.begin() + i);
            cout << "课程" << courseId << "已删除" << endl;
            return;
        }
    }
    cout << "未找到课程" << courseId << endl;
}

Course Coursedata::findCourse(const string& courseName) const {
    for (int i = 0; i < courses.size(); i++) {
        if (courses[i].getname() == courseName) {
            courses[i].display();
            return courses[i];
        }
    }
    cout << "未找到课程" << courseName << endl;
    return Course();
}

Course Coursedata::findCourse(int courseId) const {
    // 使用二分查找，把复杂度降低到O(logn)
    int left = 0;
    int right = courses.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (courses[mid].getid() == courseId) {
            courses[mid].display();
            return courses[mid];
        }
        if (courses[mid].getid() < courseId) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << "未找到课程" << courseId << endl;
    return Course();
}

void Coursedata::displayCourses() const{
    for (int i = 0; i < courses.size(); i++) {
        courses[i].display();
    }
}
