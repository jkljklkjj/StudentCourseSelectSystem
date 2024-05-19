#include "system.h"
#include "student.h"
#include "menu.h"
#include <iostream>
#include <thread>

extern Studentdata studentdata;
extern Coursedata coursedata;
extern long long id;
using namespace std;

Login::Login() {
    Menu::login();
    times = 3;
    start();
}

void Login::signup(){
    long long id;
    cout<<"请输入您的学号";
    cin>>id;
    string name;
    cout<<"请输入您的名字";
    cin>>name;
    string password;
    cout<<"请输入您要的密码";
    cin>>password;
    Student newstudent(id,name,password);
    studentdata.addStudent(newstudent);
}

bool Login::check(long long id, string password) {
    Student student = studentdata.findStudent(id);
    if (student.getid() == id && student.getpassword() == password) {
        return true;
    }
    times--;
    cout << "密码错误，您还有" << times << "次机会" << endl;
    if (times == 0) {
        cout << "您已经输错密码三次，系统将退出" << endl;
        exit(0);
    }
    return false;
}

long long Login::getid() { return id; }

string Login::getpassword() { return password; }

void Login::begin() {
    while (times > 0) {
        cout << "请输入您的学号：";
        cin >> id;
        cout << "请输入您的密码：";
        cin >> password;
        if (check(id, password)) {
            cout << "登录成功！" << endl;
            cout << "欢迎您，" << studentdata.findStudent(id).getname() << "同学！"
                 << endl;
            this_thread::sleep_for(chrono::seconds(3));
            system("cls");
            break;
        } else {
            cout << "登录失败！" << endl;
        }
    }
}

void Login::start() {
    while (true) {
        cout << "请输入1登录，2注册：";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                begin();
                return;
            case 2:
                signup();
                return;
            default:
                cout << "无效的选择，请重新输入。" << endl;
                continue;
        }
    }
}