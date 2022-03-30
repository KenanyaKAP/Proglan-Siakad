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

    int loginUser(std::string username, std::string password);
    void loadData();

    int getUserSize();
    std::vector<User> *getAllUser();
    User *getUser(std::string username);
    void addUser(std::string username, std::string password, std::string personId, User::Role role);
    void updateUser(std::string username);
    void removeUser(std::string username);
    
};

#endif