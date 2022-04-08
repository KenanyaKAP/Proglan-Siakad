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

void Departemen::delDosen(string id)
{
    for (unsigned int i = 0; i < dosenIds.size(); i++)
    {
        if (dosenIds[i] == id)
        {
            dosenIds.erase(dosenIds.begin() + i);
            return;
        }
    }
}

void Departemen::delMahasiswa(string id)
{
    for (unsigned int i = 0; i < mahasiswaIds.size(); i++)
    {
        if (mahasiswaIds[i] == id)
        {
            mahasiswaIds.erase(mahasiswaIds.begin() + i);
            return;
        }
    }
}
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

string Departemen::departemenIdAddOne(string id)
{
    id.erase(id.begin(), id.begin() + 2);
	stringstream ss;
	ss << "d_" << stoi(id) + 1;
	return ss.str();
}

int Departemen::getPositionById(vector<Departemen> *list, string id)
{
    for (unsigned int i = 0; i < list->size(); i++)
        if (list->at(i).getId() == id)
            return i;
    cout << "Cannot find position of: " << id << endl;
    exit(0);
}

Departemen *Departemen::getDepartemenById(vector<Departemen> *list, string id)
{
    for (Departemen &dept : *list)
        if (dept.getId() == id)
            return &dept;
    cout << "Cannot find Departemen with id: " << id << endl;
    exit(0);
}
// ==================================================================