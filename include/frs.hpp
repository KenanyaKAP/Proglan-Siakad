#ifndef __FRS_HPP__
#define __FRS_HPP__

#include <iostream>
#include <vector>

class Matkul;

class FRS {
public:
    enum Status {
        Unproved,
        Approved
    };

private:
    std::string id;
    Status status;
    int maxSks;
    std::vector<std::string> matkulIds;
    std::vector<int> matkulSks;
    std::vector<float> nilaiMatkuls;

public:
    FRS(std::string id);

    std::string getId();
    Status getStatus();
    std::string getStatusString();
    int getMaxSKS();
    int getTotalSKS();
    std::vector<std::string> *getAllMatkulId();
    std::vector<int> *getAllMatkulSKS();
    std::vector<float> *getAllNilaiMatkul();
    float getNilaiByMatkulId(std::string matkulId);
    float getTotalNilai();
    float getIPS();

    void setStatus(Status status);
    void addMatkul(std::string matkulId, int sks, float nilai);
    void delMatkul(std::string matkulId);
    void setNilaiMatkul(std::string matkulId, float nilai);
    void setNilaiMatkul(int index, float nilai);
    void resetFRS();

    static FRS *getFRSById(std::vector<FRS> *list, std::string id);
    static std::string frsIdAddOne(std::string id);
    static std::vector<std::tuple<std::string, std::string, int, float>> makeTuples(std::vector<Matkul*> *list, std::vector<float> *nilaiList);
    static std::vector<std::string> tuplesHeader();
};

#endif