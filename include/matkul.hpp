#ifndef __MATKUL_HPP__
#define __MATKUL_HPP__

#include <iostream>
#include <vector>

class Matkul {
private:
    std::string name;
    std::string kode;
    int sks;
    std::string id;
    std::string departemenId;
    std::vector<std::string> dosenId;
    std::vector<std::string> kelasId;

public:
    Matkul(std::string name, std::string kode, int sks, std::string id, std::string departemenId);

    std::string getName();
    std::string getKode();
    int getSKS();
    std::string getId();
    std::string getDepartemenId();
    std::vector<std::string> *getAllDosenId();
    std::vector<std::string> *getAllKelasId();

    void addDosen(std::string id);
    void addKelas(std::string id);

    static std::vector<Matkul*> getMatkulsByDepartemenId(std::vector<Matkul> *matkuls, std::string departemenId);
    static int getMatkulIdInt(std::string matkulId);
	static std::string matkulIdAddOne(std::string matkulId);
    static std::vector<std::tuple<std::string, std::string, int>> makeTuples(std::vector<Matkul*> *matkuls);
    static std::vector<std::string> tuplesHeader();
    static int getPosition(std::vector<Matkul> matkuls, Matkul *target);
    static int getPosition(std::vector<Matkul> matkuls, std::string id);
};

#endif