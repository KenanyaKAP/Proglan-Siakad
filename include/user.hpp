#ifndef __USER_HPP__
#define __USER_HPP__

#include <iostream>

class User {
public:
    enum Role
    {
        Admin,
        Dosen,
        Tendik,
        Mahasiswa
    };

private:
    char username[20];
    char password[20];
    char personId[20];
    Role role;

public:
    User();
    User(const char username[], const char password[], const char personId[], Role role);
    User(char username[], char password[], char personId[], Role role);
    char* getUsername();
    char* getPassword();
    char* getPersonId();
    Role getRole();
    void changePassword(char newPassword[]);
};

#endif