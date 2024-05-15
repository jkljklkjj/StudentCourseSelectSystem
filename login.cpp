#pragma once
#include "login.h"
#include <iostream>

void setlogin(){
    long long id;
    string password;
    cout << "请输入学号：";
    cin >> id;
    cout << "请输入密码：";
    cin >> password;
    this->id = id;
    this->password = password;
}