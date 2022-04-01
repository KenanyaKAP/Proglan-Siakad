#ifndef __DEPARTEMEN_HPP__
#define __DEPARTEMEN_HPP__

#include <iostream>
#include <vector>

class Departemen
{
private:
    std::string name;
    std::string kode;
    std::vector<std::string> matkulIds;
    std::vector<std::string> mahasiswaIds;

public:
    Departemen(std::string name, std::string kode);

    std::string getName();
    std::string getKode();

    void addMatkul(std::string id);
    void addMahasiswa(std::string id);
};

#endif