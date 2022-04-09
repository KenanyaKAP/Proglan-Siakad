#ifndef __FRS_HPP__
#define __FRS_HPP__

#include <iostream>
#include <vector>

class FRS {
public:
    enum Status {
        Unproved,
        Approved
    };

private:
    Status status;
    int maxSks;
    int totalSks;
    std::vector<std::string> matkulIds;

public:
    FRS();

    Status getStatus();
    int getMaxSKS();
    int getTotalSKS();
    std::vector<std::string> *getAllMatkulId();

    void setStatus(Status status);
    void addMatkul(std::string matkulId, int sks);
    void delMatkul(std::string matkulId, int sks);
};

#endif