#pragma once
#include <iostream>
using namespace std;

class Course {
  private:
    int id;
    string name;
    string instructor;

  public:
    Course(int, string, string, int);
    ~Course();
};