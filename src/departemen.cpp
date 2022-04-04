#include <iostream>
#include <sstream>
#include <vector>
#include <tuple>

#include "include/departemen.hpp"

using namespace std;

// ========================== Constructor ===========================
Departemen::Departemen(string name, string kode, string id)
:name(name), kode(kode), id(id){}
// ==================================================================



// ======================== Private Function ========================
// ==================================================================



// ======================== Public Function =========================
string Departemen::getName(){ return this->name; }

string Departemen::getKode(){ return this->kode; }

string Departemen::getId(){ return this->id; }

vector<string> *Departemen::getAllMatkulId(){ return &this->matkulIds; }

vector<string> *Departemen::getAllDosenId(){ return &this->dosenIds; }

vector<string> *Departemen::getAllMahasiswaId(){ return &this->mahasiswaIds; }

void Departemen::addMatkul(string id){ this->matkulIds.push_back(id); }

void Departemen::addDosen(string id){ this->dosenIds.push_back(id); }

void Departemen::addMahasiswa(string id){ this->mahasiswaIds.push_back(id); }

void Departemen::delMatkul(string id)
{
    for (unsigned int i = 0; i < matkulIds.size(); i++)
    {
        if (matkulIds[i] == id)
        {
            matkulIds.erase(matkulIds.begin() + i);
            return;
        }
    }
}
// ==================================================================



// ======================== Public Function =========================
string Departemen::departemenIdAddOne(string departemenId)
{
    departemenId.erase(departemenId.begin(), departemenId.begin() + 2);
	stringstream ss;
	ss << "d_" << stoi(departemenId) + 1;
	return ss.str();
}

int Departemen::getPosition(std::vector<Departemen> *list, Departemen *target)
{
    for (unsigned int i = 0; i < list->size(); i++)
        if (&list->at(i) == target)
            return i;
    cout << "Cannot find position of " << target->getName() << endl;
    exit(0);
}
// ==================================================================