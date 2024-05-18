#include "course.h"
#include "student.h"
#include "system.h"
#include <iostream>
using namespace std;

Studentdata studentdata;
Coursedata coursedata;
long long id;

int main() {
    studentdata.init_data();
    coursedata.init_data();
    Login login;
    login.begin();

    return 0;
}