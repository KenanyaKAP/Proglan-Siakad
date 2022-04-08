#ifndef __USER_HPP__
#define __USER_HPP__

#include <iostream>
#include <vector>

class User {
public:
    enum Role {
        Admin,
        Dosen,
        Tendik,
        Mahasiswa
    };

private:
    std::string username;
    std::string password;
    Role role;
    std::string personId;

public:
    User(std::string username, std::string password, Role role, std::string personId);

    std::string getUsername();
    std::string getPassword();
    Role getRole();
    std::string getRoleString();
    std::string getPersonId();

    void changePassword(std::string newPassword);

    static int getPositionById(std::vector<User> *list, std::string id);
    static User *getUserByUname(std::vector<User> *list, std::string username);
};

#endif