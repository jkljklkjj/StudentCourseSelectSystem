#include <iostream>
using namespace std;

class Login {
  private:
    long long id;
    string password;

  public:
    void login(long long, string);
    long long getid();
    string getpassword();
};