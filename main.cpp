#include "course.h"
#include "student.h"
#include "system.h"
#include "admin.h"
#include <iostream>
using namespace std;

Studentdata studentdata;
Coursedata coursedata;
Admindata admindata;
long long id;

int main() {
    studentdata.init_data();
    coursedata.init_data();
    admindata.init_data();
    Login login;

    return 0;
}