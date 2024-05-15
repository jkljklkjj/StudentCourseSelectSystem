#include "course.h"
#include <iostream>
using namespace std;

void Course::display() {
    cout << "课程ID: " << id << endl;
    cout << "课程名称: " << name << endl;
    cout << "课程学分: " << credit << endl;
    cout << "课程教师: " << teacher << endl;
}