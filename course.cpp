#include "course.h"
#include <iostream>
#include <map>
#include <vector>
using namespace std;

Course::Course() {
    id = 0;
    name = "";
    teacher = "";
    credit = 0;
    score = 0;
}

Course::Course(int id, string name, string teacher, int credit)
    : id(id), name(name), teacher(teacher), credit(credit), score(0) {}

Course::~Course() {}

int Course::getid() const { return id; }

string Course::getname() const { return name; }

void Course::display() const {
    cout << "课程ID: " << id << " ";
    cout << "\t课程名称: " << name << " ";
    cout << "\t课程学分: " << credit << " ";
    cout << "\t课程教师: " << teacher << endl;
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

void Coursedata::addCourse(Course course) {
    courses.push_back(course);
    }

void Coursedata::removeCourse(const string &courseName) {
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

int longestCommonSubsequence(const string &s1, const string &s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

void Coursedata::findCourse(const string &courseName) const {
    // 展示所有模糊匹配的课程
    map<int, vector<Course>, greater<int>> matchedCourses;

    for (const auto &course : courses) {
        int matchLength =
            longestCommonSubsequence(course.getname(), courseName);
        if (matchLength > 0) {
            matchedCourses[matchLength].push_back(course);
        }
    }

    for (const auto &pair : matchedCourses) {
        for (const auto &course : pair.second) {
            course.display();
        }
    }
}

Course Coursedata::find_TrueCourse(const string &courseName) const {
    int minDistance = INT_MAX;

    map<int, vector<Course>, greater<int>> matchedCourses;

    for (const auto &course : courses) {
        int matchLength =
            longestCommonSubsequence(course.getname(), courseName);
        if (matchLength > 0) {
            matchedCourses[matchLength].push_back(course);
        }
    }

    if (minDistance==0) {
        cout << "未找到课程" << courseName << endl;
        return Course();
    } else {
        if (minDistance > 3)
            return matchedCourses.begin()->second[0];
        else {
            cout << "您要找的课程是不是：" << matchedCourses.begin()->second[0].getid() << " "
                 << matchedCourses.begin()->second[0].getname() << "？" << endl;
            cout << "请输入课程ID以确认：" << endl;
            int courseId;
            cin >> courseId;
            if (courseId == matchedCourses.begin()->second[0].getid()) {
                matchedCourses.begin()->second[0].display();
                return matchedCourses.begin()->second[0];
            } else {
                cout << "未找到课程" << courseName << endl;
                return Course();
            }
        }
    }
}

Course Coursedata::find_TrueCourse(int courseId) const {
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

void Coursedata::displayCourses() const {
    for (int i = 0; i < courses.size(); i++) {
        courses[i].display();
    }
}

void Coursedata::displayCourse(const string &courseName) {
    for (int i = 0; i < courses.size(); i++) {
        if (courses[i].getname() == courseName) {
            courses[i].display();
            return;
        }
    }
    cout << "未找到课程" << courseName << endl;
}

void Coursedata::displayCourse(int courseId) {
    Course tmp = find_TrueCourse(courseId);
    if (tmp.getid() == courseId) {
        tmp.display();
        return;
    } else
        cout << "未找到课程" << courseId << endl;
}
