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

vector<string> *Departemen::getAllMahasiswaId(){ return &this->mahasiswaIds; }

void Departemen::addMatkul(string id){ this->matkulIds.push_back(id); }

void Departemen::addMahasiswa(string id){ this->mahasiswaIds.push_back(id); }
// ==================================================================



// ======================== Public Function =========================
vector<tuple<string, string>> Departemen::makeTuples(vector<Departemen> *departemens)
{
    vector<tuple<string, string>> tuples;
    for (unsigned int i = 0; i < departemens->size(); i++)
    {
        tuple<string, string> user;
        user = make_tuple(departemens->at(i).getName(), departemens->at(i).getKode());
        tuples.push_back(user);
    }
    return tuples;
}

vector<string> Departemen::tuplesHeader(){ return {"Nama Departemen", "Kode"}; }

int Departemen::getDepartemenIdInt(string departemenId)
{
    departemenId.erase(departemenId.begin(), departemenId.begin() + 2);
	return stoi(departemenId);
}

string Departemen::departemenIdAddOne(string departemenId)
{
    departemenId.erase(departemenId.begin(), departemenId.begin() + 2);
	stringstream ss;
	ss << "d_" << stoi(departemenId) + 1;
	return ss.str();
}
// ==================================================================