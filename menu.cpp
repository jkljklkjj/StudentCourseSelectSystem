#include "menu.h"
#include "course.h"
#include "system.h"
#include <iostream>
#include <thread>
#define endl "\n"
extern Coursedata coursedata;
extern Studentdata studentdata;
extern long long id;
using namespace std;

void Menu::login()
{ // 登录界面
    cout << "==================== 登录界面 ====================" << endl;
    cout << endl;
    cout << "\t\t欢迎来到学生选课系统!" << endl;
    cout << endl;
    cout << "\t请输入学号和密码注册或登录学生选课系统" << endl;
    cout << endl;
    cout << "\t\t输入1登录，输入2注册" << endl;
    cout << "==================================================" << endl;
}

void Menu::main_menu()
{ // 主菜单
    system("cls");
    cout << "==================== 主菜单 ====================" << endl;
    cout << "\t\t1. 课程一览" << endl;
    cout << "\t\t2. 修改密码" << endl;
    cout << "\t\t3. 选课" << endl;
    cout << "\t\t4. 退课" << endl;
    cout << "\t\t5. 退出" << endl;
    cout << "================================================" << endl;
    cout << "请输入您的选择：";
    while (true)
    {
        int choice;
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
            Menu::show_course();
            break;
        case 2:
            Menu::resetpassword();
            break;
        case 3:
            Menu::course_menu();
            break;
        case 4:
            Menu::drop_course();
            break;
        case 5:
            Menu::exit();
        default:
            cout << "无效的选择，请重新输入。" << endl;
            continue;
        }
    }
}

void Menu::show_course()
{ // 课程一览
    cout << "==================== 课程一览 ====================" << endl;
    coursedata.displayCourses();
    cout << "==================================================" << endl;
    cout << "请输入任意字符以返回主菜单：";
    char tmp;
    cin >> tmp;
    if (tmp)
        main_menu();
}

void Menu::course_menu()
{ // 选课
    system("cls");
    cout << "==================== 选课 ====================" << endl;
    cout << "\t\t1. 查看所有可选课程" << endl;
    cout << "\t\t2. 查看已选课程" << endl;
    cout << "\t\t3. 选课" << endl;
    cout << "\t\t4. 搜索课程" << endl;
    cout << "\t\t5. 评论课程" << endl;
    cout << "\t\t6. 返回主菜单" << endl;
    cout << "==============================================" << endl;
    cout << "请输入您的选择：";
    int choice;
    cin >> choice;
    string courseid;
    char tmp;
    string coursename;
    bool isNumber = true;
    Course course;
    Course *TrueCourse;
    switch (choice)
    {
    case 1:
        coursedata.displayCourses();
        cout << "请输入任意字符以返回：";
        cin >> tmp;
        if (tmp)
            course_menu();
        break;
    case 2:
        studentdata.findStudent(id).displayAllCourses();
        cout << "请输入任意字符以返回：";
        cin >> tmp;
        if (tmp)
            course_menu();
        break;
    case 3:
        cout << "请输入课程号或者课程名称：";
        cin >> courseid;
        for (char c : courseid)
        {
            if (!isdigit(c))
            {
                isNumber = false;
                break;
            }
        }
        if (isNumber)
        {
            int realid = stoi(courseid);
            course = coursedata.find_TrueCourse(realid);
            if (course.getname().empty() && course.getid() == 0)
            {
                cout << "没有找到课程" << endl;
            }
            else
            {
                studentdata.find_TrueStudent(id).addCourse(course);
                cout << "选课成功！" << endl;
            }
        }
        else
        {
            course = coursedata.find_TrueCourse(courseid);
            if (course.getname().empty() && course.getid() == 0)
            {
                cout << "没有找到课程" << endl;
            }
            else
            {
                studentdata.find_TrueStudent(id).addCourse(course);
                cout << "选课成功！" << endl;
            }
        }
        this_thread::sleep_for(chrono::seconds(2));
        course_menu();
        break;
    case 4:
        cout << "请输入课程名称：";
        cin >> coursename;
        coursedata.findCourse(coursename);
        cout << "请输入任意字符以返回：";
        cin >> tmp;
        if (tmp)
            course_menu();
        break;
    case 5:
        system("cls");
        cout << "==================== 评论课程 ====================\n"
             << "\t\t1. 评论课程\n"
             << "\t\t2. 查看评论\n"
             << "\t\t3. 返回课程菜单\n"
             << "==================================================\n"
             << "请输入您的选择：";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "请输入课程号：";
            cin >> courseid;
            TrueCourse = &coursedata.find_TrueCourse(stoi(courseid));
            if (TrueCourse->getname().empty() && TrueCourse->getid() == 0)
            {
                cout << "没有找到课程" << endl;
            }
            else
            {
                cout << "请输入评论：";
                string comment;
                cin >> comment;
                TrueCourse->addComment(comment);
                cout << "评论成功！" << endl;
            }
            this_thread::sleep_for(chrono::seconds(2));
            course_menu();
            break;
        case 2:
            cout << "请输入课程号：";
            cin >> courseid;
            TrueCourse = &coursedata.find_TrueCourse(stoi(courseid));
            if (TrueCourse->getname().empty() && TrueCourse->getid() == 0)
            {
                cout << "没有找到课程" << endl;
            }
            else
            {
                TrueCourse->show_comments();
            }
            cout << "请输入任意字符以返回：";
            cin >> tmp;
            if (tmp)
                course_menu();
            break;
        case 3:
            course_menu();
            break;
        }

    case 6:
        main_menu();
        break;
    }
}

void Menu::resetpassword()
{ // 重置密码
    cout << "==================== 修改密码 ====================" << endl;
    cout << "\t\t1. 修改密码" << endl;
    cout << "\t\t2. 返回主菜单" << endl;
    cout << "==================================================" << endl;
    cout << "请输入您的选择：";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        cout << "请输入新密码：";
        string newpassword;
        cin >> newpassword;
        studentdata.find_TrueStudent(id).setPassword(newpassword);
        cout << "密码修改成功！" << endl;
        this_thread::sleep_for(chrono::seconds(3));
        main_menu();
        break;
    }
    case 2:
        main_menu();
        break;
    }
}

void Menu::drop_course()
{ // 退课
    system("cls");
    cout << "==================== 退课 ====================" << endl;
    cout << "\t\t1. 查看已选课程" << endl;
    cout << "\t\t2. 退课" << endl;
    cout << "\t\t3. 返回主菜单" << endl;
    cout << "==============================================" << endl;
    cout << "请输入您的选择：";
    int choice;
    cin >> choice;
    char tmp;
    switch (choice)
    {
    case 1:
        studentdata.find_TrueStudent(id).displayAllCourses();
        cout << "请输入任意字符以返回：";
        cin >> tmp;
        if (tmp)
            drop_course();
        break;
    case 2:
        studentdata.find_TrueStudent(id).displayAllCourses();
        cout << "请输入您要退的课程号：";
        int courseid;
        cin >> courseid;
        studentdata.find_TrueStudent(id).removeCourse(
            coursedata.find_TrueCourse(courseid).getname());
        this_thread::sleep_for(chrono::seconds(3));
        drop_course();
        break;
    case 3:
        main_menu();
        break;
    }
}

void Menu::exit()
{
    cout << "==================== 退出 ====================" << endl;
    cout << "\t感谢使用学生选课系统！" << endl;
    cout << "\t\t再见！" << endl;
    cout << "==================================================" << endl;
    std::exit(0);
}