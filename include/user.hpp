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
    std::string username;
    std::string password;
    std::string personId;
    Role role;

public:
    User();
    // User(const std::string username, const std::string password, const std::string personId, Role role);
    User(std::string username, std::string password, std::string personId, Role role);
    std::string getUsername();
    std::string getPassword();
    std::string getPersonId();
    Role getRole();
    void changePassword(std::string newPassword);
};

#endif