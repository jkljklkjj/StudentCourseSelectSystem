#include <iostream>
#include "student.h"
using namespace std;

class Login {
  private:
    long long id;
    string password;
    int times;

  public:
    Login();
    void begin(const Studentdata&);
    bool check(long long , string, const Studentdata&);
    long long getid();
    string getpassword();
};