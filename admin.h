#include "student.h"
#include "course.h" 
#include <iostream>


class Admin {
    private:
        long long id;
        string name;
        string password;
    public:
        Admin(long long id, string name, string password);
        void getid() const;
        void getname() const;
        void getpassword() const;
        void main_menu();
        void student_menu();
        void course_menu();
        void changePassword(long long id, string password);
};

class Admindata {
    private:
        vector<Admin> admins;
    public:
        void init_data();
        void addAdmin(const Admin &admin);
        void removeAdmin(long long id);
        Admin findAdmin(long long id) const;
        void sortByid();
        void changePassword(long long id, string password);
};