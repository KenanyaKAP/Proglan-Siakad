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

    static User *getUser(std::vector<User> *users, std::string username);
    static std::vector<std::tuple<std::string, std::string>> makeTuples(std::vector<User> *users);
    static std::vector<std::string> tuplesHeader();
};

#endif