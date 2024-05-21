#include "admin.h"
#include "course.h"
#include "menu.h"
#include "student.h"
#include <iostream>
#include <thread>

extern Coursedata coursedata;
extern Studentdata studentdata;
extern long long id;

using namespace std;

Admin::Admin(long long id, string name, string password) {
    this->id = id;
    this->name = name;
    this->password = password;
}

void Admin::main_menu() {
    cout << "================== 管理员菜单 ===================" << endl;
    cout << "\t1. 学生菜单" << endl;
    cout << "\t2. 课程菜单" << endl;
    cout << "\t3. 修改密码" << endl;
    cout << "\t4. 退出登录" << endl;
    cout << "================================================" << endl;
    cout << "请输入您的选择：";
    int choice;
    cin >> choice;
    string password;
    switch (choice) {
    case 1:
        student_menu();
        break;
    case 2:
        course_menu();
        break;
    case 3:
        cout << "请输入新密码：";
        cin >> password;
        changePassword(id, password);
        break;
    case 4:
        cout << "退出成功！" << endl;
        break;
    default:
        cout << "输入错误！" << endl;
        break;
    }
}

void Admin::student_menu() {
    cout << "================== 学生菜单 ===================" << endl;
    cout << "\t1. 添加学生" << endl;
    cout << "\t2. 删除学生" << endl;
    cout << "\t4. 查找学生" << endl;
    cout << "\t5. 显示所有学生" << endl;
    cout << "\t6. 返回主菜单" << endl;
    cout << "================================================" << endl;
    cout << "请输入您的选择：";
    int choice;
    cin >> choice;
    long long student_id;
    string student_name;
    string student_password;
    Student student;
    switch (choice) {
    case 1:
        cout << "请输入学生学号" << endl;
        cin >> student_id;
        cout << "请输入学生姓名" << endl;
        cin >> student_name;
        cout << "请输入学生密码" << endl;
        cin >> student_password;
        student.setStudent(student_id, student_name, student_password);
        studentdata.addStudent(student);
        cout << "添加成功！" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        student_menu();
        break;
    case 2:
        cout << "请输入学生学号" << endl;
        cin >> student_id;
        studentdata.removeStudent(student_id);
        cout << "删除成功！" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        student_menu();
        break;
    case 3:
        cout << "请输入学生学号" << endl;
        cin >> student_id;
        student = studentdata.findStudent(student_id);
        student.display();
        student.displayAllCourses();
        cout<<"按任意键继续"<<endl;
        getchar();
        student_menu();
        break;
    case 4:
        studentdata.displayAllStudents();
        cout<<"按任意键继续"<<endl;
        getchar();
        student_menu();
        break;
    case 5:
        main_menu();
        break;
    default:
        cout << "输入错误！" << endl;
        break;
    }
}

void Admin::course_menu() {
    cout << "================== 课程菜单 ===================" << endl;
    cout << "\t1. 添加课程" << endl;
    cout << "\t2. 删除课程" << endl;
    cout << "\t3. 查找课程" << endl;
    cout << "\t4. 显示所有课程" << endl;
    cout << "\t5. 返回主菜单" << endl;
    cout << "================================================" << endl;
    cout << "请输入您的选择：";
    int choice;
    cin >> choice;
    int course_id;
    string course_name;
    string course_teacher;
    int course_credit;
    Course course;
    switch (choice) {
    case 1:
        cout << "请输入课程号" << endl;
        cin >> course_id;
        cout << "请输入课程名" << endl;
        cin >> course_name;
        cout << "请输入课程教师" << endl;
        cin >> course_teacher;
        cout << "请输入课程学分" << endl;
        cin >> course_credit;
        course = Course(course_id, course_name, course_teacher, course_credit);
        coursedata.addCourse(course);
        cout << "添加成功！" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        course_menu();
        break;
    case 2:
        cout << "请输入课程id" << endl;
        cin >> course_name;
        coursedata.removeCourse(course_name);
        cout << "删除成功！" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        course_menu();
        break;
    case 3:
        cout << "请输入课程名" << endl;
        cin >> course_name;
        coursedata.findCourse(course_name);
        cout<<"按任意键继续"<<endl;
        getchar();
        course_menu();
        break;
    case 4:
        coursedata.displayCourses();
        cout<<"按任意键继续"<<endl;
        getchar();
        course_menu();
        break;
    case 5:
        main_menu();
        break;
    default:
        cout << "输入错误！" << endl;
        break;
    }
}

void Admin::changePassword(long long id, string password) {
    Admindata.changePassword(id, password);
    cout << "修改成功！" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    main_menu();
}