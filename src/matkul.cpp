#include <iostream>
#include <string>
#include <sstream>

#include "include/matkul.hpp"

using namespace std;

// ========================== Constructor ===========================
Matkul::Matkul(string name, string kode, int sks, string id, string departemenId)
:name(name), kode(kode), sks(sks), id(id), departemenId(departemenId){}
// ==================================================================



// ======================== Private Function ========================
// ==================================================================



// ======================== Public Function =========================
string Matkul::getName(){ return this->name; }

string Matkul::getKode(){ return this->kode; }

int Matkul::getSKS(){ return this->sks; }

string Matkul::getId(){ return this->id; }

string Matkul::getDepartemenId(){ return this->departemenId; }

vector<string> *Matkul::getAllKelasId(){ return &this->kelasId; }

vector<string> *Matkul::getAllDosenId(){ return &this->dosenId; }

void Matkul::addDosen(std::string id){ this->dosenId.push_back(id); }

void Matkul::addKelas(std::string id){ this->kelasId.push_back(id); }
// ==================================================================



// ===================== Public Static Function =====================
vector<Matkul*> *Matkul::getMatkulByDepartemenId(vector<Matkul> *matkuls, string departemenId)
{
    vector<Matkul*> *output = {};

    for (Matkul &matkul : *matkuls)
        if (matkul.getDepartemenId() == departemenId)
            output->push_back(&matkul);

    return output;
}

int Matkul::getMatkulIdInt(string personId)
{
	personId.erase(personId.begin(), personId.begin() + 2);
	return stoi(personId);
}

string Matkul::matkulIdAddOne(string personId)
{
	personId.erase(personId.begin(), personId.begin() + 2);
	stringstream ss;
	ss << "m_" << stoi(personId) + 1;
	return ss.str();
}
// ==================================================================