#ifndef __SAVE_HPP__
#define __SAVE_HPP__

#include <iostream>
#include <vector>

class User;
class Departemen;

namespace Save
{
    void saveData(std::vector<User> *data, const char *path);
    void loadData(std::vector<User> &out, const char *path);
    void saveData(std::vector<Departemen> *data, const char *path);
    void loadData(std::vector<Departemen> &out, const char *path);
};

#endif