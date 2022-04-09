#include <iostream>
#include <vector>

#include "include/frs.hpp"
#include "include/matkul.hpp"

// ========================== Constructor ===========================
FRS::FRS()
{

}
// ==================================================================



// ======================== Private Function ========================
// ==================================================================



// ======================== Public Function =========================
FRS::Status FRS::getStatus()
{
    return this->status;
}

int FRS::getMaxSKS()
{
    return this->maxSks;
}

int FRS::getTotalSKS()
{
    return this->totalSks;
}

std::vector<std::string> *FRS::getAllMatkulId()
{
    return &this->matkulIds;
}

void FRS::setStatus(FRS::Status status)
{
    this->status = status;
}

void FRS::addMatkul(std::string matkulId, int sks)
{
    this->matkulIds.push_back(matkulId);
    this->totalSks += sks;
}

void FRS::delMatkul(std::string matkulId, int sks)
{
    for (unsigned int i = 0; i < matkulIds.size(); i++)
    {
        if (matkulIds[i] == matkulId)
        {
            matkulIds.erase(matkulIds.begin() + i);
            this->totalSks -= sks;
            return;
        }
    }
}
// ==================================================================



// ===================== Public Static Function =====================
// ==================================================================


