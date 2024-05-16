#include<iostream>
#include "student.h"
#include "course.h"
#include "login.h"
using namespace std;

int main() {
    Studentdata studentdata;
    studentdata.init_data();
    Login login;
    login.begin(studentdata);
    
    return 0;
}