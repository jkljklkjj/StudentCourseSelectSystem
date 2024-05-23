#include "system.h"
#include "admin.h"
#include "menu.h"
#include "student.h"
#include <iostream>
#include <thread>

extern Studentdata studentdata;
extern Coursedata coursedata;
extern Admindata admindata;
extern long long id;
using namespace std;

//-------------------------Login-------------------------start
Login::Login() {
    Menu::login();
    times = 3;
    start();
}

void Login::signup() { // 注册
    long long tmp;
    cout << "请输入您的学号：";
    cin >> tmp;
    string name;
    cout << "请输入您的名字：";
    cin >> name;
    string password;
    cout << "请输入您要的密码：";
    cin >> password;
    password = caesarEncrypt(password);
    Student newstudent(tmp, name, password);
    studentdata.addStudent(newstudent);
    cout << "注册成功！" << endl;
    studentdata.sortByid(); // 重新排序
    this_thread::sleep_for(chrono::seconds(3));
    Login();
}

bool Login::check(string password) {
    Student student = studentdata.findStudent(id);

    if (student.getid() == id && caesarDecrypt(student.getpassword()) == password) {
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
        if (id / 1000 == 2019) {
            Admin admin = admindata.findAdmin(id);
            if (admin.getid() == id && caesarDecrypt(admin.getpassword()) == password) {
                cout << "登录成功！" << endl;
                cout << "欢迎您，" << admin.getname() << "管理员！" << endl;
                this_thread::sleep_for(chrono::seconds(3));
                Admin::main_menu();
                break;
            }
            else {
                cout << "登录失败！" << endl;
                break;
            }
        }
        if (check(password)) {
            cout << "登录成功！" << endl;
            cout << "欢迎您，" << studentdata.findStudent(id).getname()
                 << "同学！" << endl;
            this_thread::sleep_for(chrono::seconds(3));
            Menu::main_menu();
            break;
        } else {
            cout << "登录失败！" << endl;
        }
    }
}

void Login::start() {
    while (true) {
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
//-------------------------Login-------------------------end

string Login::caesarEncrypt(const string& text) {
    int shift = 3;
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i]))
            result += char(int(text[i] + shift - 65) % 26 + 65);
        else if (islower(text[i]))
            result += char(int(text[i] + shift - 97) % 26 + 97);
        else if (isdigit(text[i]))
            result += char(int(text[i] + shift - 48) % 10 + 48);
    }

    return result;
}

string Login::caesarDecrypt(const string& text) {
    int shift = -3;
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i]))
            result += char(int(text[i] + shift - 65) % 26 + 65);
        else if (islower(text[i]))
            result += char(int(text[i] + shift - 97) % 26 + 97);
        else if (isdigit(text[i]))
            result += char(int(text[i] + shift - 48) % 10 + 48);
    }

    return result;
}