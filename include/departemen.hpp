#ifndef __DEPARTEMEN_HPP__
#define __DEPARTEMEN_HPP__

#include <iostream>
#include <vector>
#include <tuple>

class Departemen
{
private:
    std::string name;
    std::string kode;
    std::string id;
    std::vector<std::string> matkulIds;
    std::vector<std::string> dosenIds;
    std::vector<std::string> mahasiswaIds;

public:
    Departemen(std::string name, std::string kode, std::string id);

    std::string getName();
    std::string getKode();
    std::string getId();
    std::vector<std::string> *getAllMatkulId();
    std::vector<std::string> *getAllDosenId();
    std::vector<std::string> *getAllMahasiswaId();

    void addMatkul(std::string id);
    void addDosen(std::string id);
    void addMahasiswa(std::string id);
    void delMatkul(std::string id);

	static std::string departemenIdAddOne(std::string departemenId);
    static int getPosition(std::vector<Departemen> *list, Departemen *target);
};

#endif