#ifndef __USER_HPP__
#define __USER_HPP__

#include <iostream>
#include <cstring>
#include <tuple>

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
    User(class S_User sUser);
    User(std::string username, std::string password, std::string personId, Role role);
    
    std::string getUsername();
    std::string getPassword();
    std::string getPersonId();
    Role getRole();
    void changePassword(std::string newPassword);
    
    static std::vector<std::tuple<std::string, std::string>> makeTuples(std::vector<User> *users);
    static std::vector<std::string> tuplesHeader();
};

class S_User {
public:
    char username[20];
    char password[20];
    char personId[20];
    User::Role role;

    S_User();
    S_User(User user);
};

#endif