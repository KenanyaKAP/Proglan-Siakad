#ifndef __MATKUL_HPP__
#define __MATKUL_HPP__

#include <iostream>
#include <vector>

class Departemen;

class Matkul {
private:
    std::string name;
    std::string kode;
    int sks;
    std::string id;
    std::string departemenId;

public:
    Matkul(std::string name, std::string kode, int sks, std::string id, std::string departemenId);

    std::string getName();
    std::string getKode();
    int getSKS();
    std::string getId();
    std::string getDepartemenId();

    static Matkul *getMatkulById(std::vector<Matkul> *list, std::string id);
    static std::vector<Matkul*> getMatkulsById(std::vector<Matkul> *list, std::vector<std::string> *ids);
    static std::vector<Matkul*> getMatkulsByDeptId(std::vector<Matkul> *list, std::string id);
    static std::vector<Matkul*> getMatkulExcludeById(std::vector<Matkul> *list, std::vector<std::string> *excludeId);
	
    static std::string matkulIdAddOne(std::string id);
    static int getPositionById(std::vector<Matkul> *list, std::string id);

    // static std::vector<std::tuple<std::string, std::string, int>> makeTuples(std::vector<Matkul> *list);
    static std::vector<std::tuple<std::string, std::string, int, std::string>> makeTuples(std::vector<Matkul*> *list, std::vector<Departemen> *recDepartemen);
    static std::vector<std::string> tuplesHeader();
};

#endif