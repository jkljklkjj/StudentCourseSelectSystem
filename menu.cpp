#include "menu.h"
#include "system.h"
#include "course.h"
#include <iostream>
#define endl "\n"
extern Coursedata coursedata;
using namespace std;

void Menu::login() { // 登录界面
    cout << "==================== 登录界面 ====================" << endl;
    cout << endl;
    cout << "\t\t欢迎来到学生选课系统!" << endl;
    cout << endl;
    cout << "\t请输入学号和密码注册或登录学生选课系统" << endl;
    cout << endl;
    cout << "\t\t输入1登录，输入2注册" << endl;
    cout << "==================================================" << endl;
}

void Menu::main_menu() { // 主菜单
    cout << "==================== 主菜单 ====================" << endl;
    cout << "\t\t1. 课程一览" << endl;
    cout << "\t\t2. 修改密码" << endl;
    cout << "\t\t3. 选课" << endl;
    cout << "\t\t4. 退课" << endl;
    cout << "\t\t5. 退出" << endl;
    cout << "==================================================" << endl;
    cout << "请输入您的选择：";
    int choice;
    cin >> choice;
    switch(choice) {
        case 1:
            show_course();
            break;
        case 2:
            resetpassword();
            break;
        case 3:
            course_menu();
            break;
        case 4:
            break;
        case 5:
            exit();
            break;
        default:
            cout << "输入错误，请重新输入！" << endl;
            main_menu();
            break;
    }
}

void Menu::show_course() { // 课程一览
    cout << "==================== 课程一览 ====================" << endl;
    coursedata.displayCourses();
    cout << "==================================================" << endl;
    cout << "请输入任意字符以返回主菜单：";
    char tmp;
    cin >> tmp;
    if(tmp) main_menu();
}

void Menu::course_menu() { // 选课
    cout << "==================== 选课 ====================" << endl;
    cout << "\t\t1. 查看所有可选课程" << endl;
    cout << "\t\t2. 查看已选课程" << endl;
    cout << "\t\t3. 返回主菜单" << endl;
    cout << "==================================================" << endl;
    cout << "请输入您的选择：";
}

void Menu::resetpassword() {
    cout << "==================== 修改密码 ====================" << endl;
    cout << "\t\t1. 修改密码" << endl;
    cout << "\t\t2. 返回主菜单" << endl;
    cout << "==================================================" << endl;
    cout << "请输入您的选择：";
}

void Menu::exit() {
    cout << "==================== 退出 ====================" << endl;
    cout << "\t\t感谢您的使用，再见！" << endl;
    cout << "==================================================" << endl;
}