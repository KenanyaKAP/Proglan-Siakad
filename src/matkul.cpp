#include <iostream>
#include <string>
#include <vector>
#include <tuple>
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

void Matkul::addDosen(string id){ this->dosenId.push_back(id); }

void Matkul::addKelas(string id){ this->kelasId.push_back(id); }
// ==================================================================



// ===================== Public Static Function =====================
vector<Matkul*> Matkul::getMatkulsByDepartemenId(vector<Matkul> *matkuls, string departemenId)
{
    vector<Matkul*> output;

    for (Matkul &matkul : *matkuls)
        if (matkul.getDepartemenId() == departemenId)
            output.push_back(&matkul);

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

int Matkul::getPosition(vector<Matkul> *list, Matkul *target)
{
    for (unsigned int i = 0; i < list->size(); i++)
        if (&list->at(i) == target)
            return i;
    cout << "Cannot find position of " << target->getName() << endl;
    exit(0);
}

int Matkul::getPosition(vector<Matkul> *list, string id)
{
    for (int i = 0; i < int(list->size()); i++)
        if (list->at(i).getId() == id)
            return i;
    cout << "Cannot find position of matkul id: " << id << endl;
    exit(0);
}
// ==================================================================