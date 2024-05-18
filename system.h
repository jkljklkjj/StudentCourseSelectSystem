#include "student.h"
#include <iostream>
using namespace std;

class Login {
  private:
    long long id;
    string password;
    int times;

  public:
    Login();
    void begin();                  // 进入登录系统
    bool check(long long, string); // 检查密码是否正确
    long long getid();             // 获取学号
    string getpassword();          // 获取密码
    
};
