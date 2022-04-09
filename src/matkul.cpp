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
// ==================================================================



// ===================== Public Static Function =====================
vector<Matkul*> Matkul::getMatkulsByDeptId(vector<Matkul> *list, string id)
{
    vector<Matkul*> output;
    for (Matkul &matkul : *list)
        if (matkul.getDepartemenId() == id)
            output.push_back(&matkul);
    return output;
}

string Matkul::matkulIdAddOne(string id)
{
	id.erase(id.begin(), id.begin() + 2);
	stringstream ss;
	ss << "m_" << stoi(id) + 1;
	return ss.str();
}

int Matkul::getPositionById(vector<Matkul> *list, string id)
{
    for (int i = 0; i < int(list->size()); i++)
        if (list->at(i).getId() == id)
            return i;
    cout << "Cannot find position of matkul id: " << id << endl;
    exit(0);
}
// ==================================================================