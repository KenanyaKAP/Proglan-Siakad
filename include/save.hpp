#ifndef __SAVE_HPP__
#define __SAVE_HPP__

#include <iostream>
#include <vector>

class Data;
class User;
class Departemen;
class Matkul;
class Dosen;

namespace Save
{
    void saveData(Data *data, const char *path);
    void loadData(Data &out, const char *path);

    void saveData(std::vector<User> *data, const char *path);
    void loadData(std::vector<User> &out, const char *path);
    
    void saveData(std::vector<Departemen> *data, const char *path);
    void loadData(std::vector<Departemen> &out, const char *path);
    
    void saveData(std::vector<Matkul> *data, const char *path);
    void loadData(std::vector<Matkul> &out, const char *path);

    void saveData(std::vector<Dosen> *data, const char *path);
    void loadData(std::vector<Dosen> &out, const char *path);
};

#endif