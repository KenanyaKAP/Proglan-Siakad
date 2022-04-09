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

public:
    Matkul(std::string name, std::string kode, int sks, std::string id, std::string departemenId);

    std::string getName();
    std::string getKode();
    int getSKS();
    std::string getId();
    std::string getDepartemenId();
    
    static std::vector<Matkul*> getMatkulsByDeptId(std::vector<Matkul> *list, std::string id);
	static std::string matkulIdAddOne(std::string id);
    static int getPositionById(std::vector<Matkul> *list, std::string id);
};

#endif