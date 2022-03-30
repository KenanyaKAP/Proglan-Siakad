#ifndef __USER_HPP__
#define __USER_HPP__

#include <iostream>
#include <cstring>

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
    std::string username;
    std::string password;
    std::string personId;
    Role role;
    static std::string getRoleString(Role role);

public:
    User();
    // User(const std::string username, const std::string password, const std::string personId, Role role);
    User(class S_User sUser);
    User(std::string username, std::string password, std::string personId, Role role);
    std::string getUsername();
    std::string getPassword();
    std::string getPersonId();
    Role getRole();
    void changePassword(std::string newPassword);
    static std::vector<std::vector<std::string>> MakeVector(std::vector<User> *users);
};

class S_User {
public:
    char username[20];
    char password[20];
    char personId[20];
    User::Role role;

    S_User();
    S_User(User user);
    // S_User(const char *username, const char *password, const char *personId, User::Role role);
};

#endif