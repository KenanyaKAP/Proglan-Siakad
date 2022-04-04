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

    static User *getUser(std::vector<User> *list, std::string username);
    static int getPosition(std::vector<User> *list, User *target);
};

#endif