#ifndef __DATA_HPP__
#define __DATA_HPP__

#include <iostream>
#include <vector>
#include <fstream>

#include "include/user.hpp"

struct Data {
private:
    std::vector<User> recUser;

    template <class T>
    int getDataSize(std::fstream& dataFile);
    template <class Base, class Save>
    void writeData(int position, Base input, const char *filePath);
    template <class T>
    T readData(std::fstream& dataFile, int position);
    template <class Base, class Save>
    std::vector<Base> loadData(const char *filePath);

public:
    Data();

    int getUserSize();
    std::vector<User> *getAllUser();
    User *getUser(char *username);
    void removeUser(char *username);
    void addUser(const char *username, const char *password, const char *personId, User::Role role);
    void addUser(char *username, char *password, char *personId, User::Role role);
    int loginUser(char *username, char *password);

    void checkUname(char *uname);

};

#endif