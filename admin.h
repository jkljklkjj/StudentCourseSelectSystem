#include "student.h"
#include "course.h" 
#include <iostream>


class Admin {
    private:
        string name;
        string password;
        long long admin_id;
    public:
        Admin(long long id, string name, string password);
        Admin();
        long long getid() const;
        string getname() const;
        string getpassword() const;
        void setpassword(string password);
        static void main_menu();
        static void student_menu();
        static void course_menu();
        void changePassword(string);
};

class Admindata {
    private:
        vector<Admin> admindata;
    public:
        void init_data();
        Admin& findAdmin(long long id);
};