#ifndef __SAVE_HPP__
#define __SAVE_HPP__

#include <iostream>
#include <vector>

class Data;
class User;
class Departemen;
class Matkul;
class Dosen;
class Tendik;
class Mahasiswa;
class FRS;

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
    
    void saveData(std::vector<Tendik> *data, const char *path);
    void loadData(std::vector<Tendik> &out, const char *path);
    
    void saveData(std::vector<Mahasiswa> *data, const char *path);
    void loadData(std::vector<Mahasiswa> &out, const char *path);
    
    void saveData(std::vector<FRS> *data, const char *path);
    void loadData(std::vector<FRS> &out, const char *path);
};

#endif