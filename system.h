#include "student.h"
#include <iostream>
using namespace std;

class Login {
  private:
    string password;
    int times;

  public:
    Login();
    void begin();         // 进入登录系统
    bool check(string);   // 检查密码是否正确
    long long getid();    // 获取学号
    string getpassword(); // 获取密码
    void signup();        // 注册
    void start();         // 进入系统
    static string caesarEncrypt(const string &); // 凯撒加密
    static string caesarDecrypt(const string &); // 凯撒解密
};
