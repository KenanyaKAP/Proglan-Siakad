#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <tuple>
#include <math.h>

#include "include/frs.hpp"
#include "include/matkul.hpp"

using namespace std;

// ========================== Constructor ===========================
FRS::FRS(string id)
:id(id)
{
    this->status = FRS::Status::Unproved;
    this->maxSks = 24;
}
// ==================================================================



// ======================== Private Function ========================
// ==================================================================



// ======================== Public Function =========================
string FRS::getId(){ return this->id; }

FRS::Status FRS::getStatus(){ return this->status; }

string FRS::getStatusString()
{
    switch (this->status)
    {
    case FRS::Status::Unproved:
        return "Belum Disetujui";
    case FRS::Status::Approved:
        return "Disetujui";
    default:
        return "\0";
    }
}

int FRS::getMaxSKS(){ return this->maxSks; }

int FRS::getTotalSKS()
{
    int total = 0;
    for (int sks : matkulSks)
        total += sks;
    return total;
}

vector<string> *FRS::getAllMatkulId(){ return &this->matkulIds; }

vector<int> *FRS::getAllMatkulSKS(){ return &this->matkulSks; }

vector<float> *FRS::getAllNilaiMatkul(){ return &this->nilaiMatkuls; }

float FRS::getNilaiByMatkulId(std::string matkulId)
{
    for (unsigned int i = 0; i < matkulIds.size(); i++)
        if (matkulIds.at(i) == matkulId)
            return nilaiMatkuls.at(i);
    return 0.0f;
}

float FRS::getTotalNilai()
{
    float output = 0.0f;
    for (unsigned int i = 0; i < matkulIds.size(); i++)
    {
        output += nilaiMatkuls.at(i) * matkulSks.at(i);
    }
    return output;
}

float FRS::getIPS()
{
    return fmax(0.0f, getTotalNilai() / getTotalSKS());
}

void FRS::setStatus(FRS::Status status){ this->status = status; }

void FRS::addMatkul(std::string matkulId, int sks, float nilai)
{
    this->matkulIds.push_back(matkulId);
    this->matkulSks.push_back(sks);
    this->nilaiMatkuls.push_back(nilai);
}

void FRS::delMatkul(string matkulId)
{
    for (unsigned int i = 0; i < matkulIds.size(); i++)
    {
        if (matkulIds[i] == matkulId)
        {
            matkulIds.erase(matkulIds.begin() + i);
            matkulSks.erase(matkulSks.begin() + i);
            nilaiMatkuls.erase(nilaiMatkuls.begin() + i);
            return;
        }
    }
}

void FRS::setNilaiMatkul(string matkulId, float nilai)
{
    for (unsigned int i = 0; i < matkulIds.size(); i++)
    {
        if (matkulIds[i] == matkulId)
        {
            this->nilaiMatkuls.at(i) = nilai;
            return;
        }
    }
}

void FRS::setNilaiMatkul(int index, float nilai)
{
    nilaiMatkuls.at(index) = nilai;
}

void FRS::resetFRS()
{
    this->status = FRS::Status::Unproved;
    this->maxSks = 24;
    matkulIds.clear();
    matkulSks.clear();
    nilaiMatkuls.clear();
}
// ==================================================================



// ===================== Public Static Function =====================
FRS *FRS::getFRSById(vector<FRS> *list, string id)
{
    for (FRS &frs : *list)
        if (frs.getId() == id)
            return &frs;
    cout << "Cannot find FRS with id: " << id << endl;
    exit(0);
}

string FRS::frsIdAddOne(string id)
{
	id.erase(id.begin(), id.begin() + 2);
	stringstream ss;
	ss << "f_" << stoi(id) + 1;
	return ss.str();
}

vector<tuple<string, string, int, float>> FRS::makeTuples(vector<Matkul*> *list, vector<float> *nilaiList)
{
    vector<tuple<string, string, int, float>> tuples;
    for (unsigned int i = 0; i < list->size(); i++)
    {
        tuple<string, string, int, float> row;
        row = make_tuple(list->at(i)->getKode(), list->at(i)->getName(), list->at(i)->getSKS(), nilaiList->at(i));
        tuples.push_back(row);
    }
    return tuples;
}

vector<string> FRS::tuplesHeader(){ return {"Kode", "Mata Kuliah", "SKS", "Nilai"}; }
// ==================================================================