#include "menu.h"

#include<iostream>
#define endl '\n'
using namespace std;

void Menu::login() {//登录界面
    cout << "==================== 登录界面 ====================" << endl+endl;
    cout << "\t\t欢迎来到学生选课系统!" << endl+endl;
    cout << "\t请输入学号和密码注册或登录学生选课系统" << endl+endl;
    cout << "\t\t输入1登录，输入2注册" << endl;
    cout << "\t==================================================" << endl;
}

void Menu::main_menu() {//主菜单
    cout << "==================== 主菜单 ====================" << endl+endl;
    cout << "\t\t1. 课程一览" << endl;
    cout << "\t\t2. 修改密码" << endl;
    cout << "\t\t3. 选课" << endl;
    cout << "\t\t4. 退课" << endl;
    cout << "\t\t5. 退出" << endl;
    cout << "==================================================" << endl;
    cout << "请输入您的选择：";
}

void Menu::course_menu() {//课程一览
    cout << "==================== 课程一览 ====================" << endl+endl;
    cout << "\t\t1. 查看所有可选课程" << endl;
    cout << "\t\t2. 查看已选课程" << endl;
    cout << "\t\t3. 返回主菜单" << endl;
    cout << "==================================================" << endl;
    cout << "请输入您的选择：";
}

