#pragma once
#include "login.h"
#include "student.h"
#include <iostream>
#include <thread>
using namespace std;

Login::Login() {
    long long id;
    string password;
    cout << "请输入您的学号：";
    cin >> id;
    cout << "请输入您的密码：";
    cin >> password;
    this->id = id;
    this->password = password;
    times = 3;
}

bool Login::check(long long id, string password,
                  const Studentdata &studentdata) {
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

void Login::begin(const Studentdata &studentdata) {
    if (check(id, password, studentdata)) {
        cout << "登录成功！" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        system("cls");
    } else {
        cout << "登录失败！" << endl;
    }
}
