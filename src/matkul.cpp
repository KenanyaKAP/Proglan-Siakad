#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <sstream>
#include <algorithm>

#include "include/matkul.hpp"
#include "include/departemen.hpp"

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
Matkul *Matkul::getMatkulById(vector<Matkul> *list, string id)
{
    for (Matkul &matkul : *list)
        if (matkul.getId() == id)
            return &matkul;
    cout << "Cannot find position of matkul id: " << id << endl;
    exit(0);
}

vector<Matkul*> Matkul::getMatkulsById(vector<Matkul> *list, vector<string> *ids)
{
    vector<Matkul*> output;
    for (string &id : *ids)
    {
        for (unsigned int i = 0; i < list->size(); i++)
        {
            if (list->at(i).getId() ==  id)
            {
                output.push_back(&list->at(i));
                break;
            }
        }
    }
    return output;
}

vector<Matkul*> Matkul::getMatkulsByDeptId(vector<Matkul> *list, string id)
{
    vector<Matkul*> output;
    for (Matkul &matkul : *list)
        if (matkul.getDepartemenId() == id)
            output.push_back(&matkul);
    return output;
}

vector<Matkul*> Matkul::getMatkulExcludeById(vector<Matkul> *list, vector<string> *excludeId)
{
    vector<Matkul*> output;
    for (Matkul &matkul : *list)
    {
        if (!count(excludeId->begin(), excludeId->end(), matkul.getId())) {
            output.push_back(&matkul);
        }
    }
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

// vector<tuple<string, string, int>> Matkul::makeTuples(vector<Matkul> *list)
// {
//     vector<tuple<string, string, int>> tuples;
//     for (unsigned int i = 0; i < list->size(); i++)
//     {
//         tuple<string, string, int> row;
//         row = make_tuple(list->at(i).getKode(), list->at(i).getName(), list->at(i).getSKS());
//         tuples.push_back(row);
//     }
//     return tuples;
// }

vector<tuple<string, string, int, string>> Matkul::makeTuples(vector<Matkul*> *list, vector<Departemen> *recDepartemen)
{
    vector<tuple<string, string, int, string>> tuples;
    for (unsigned int i = 0; i < list->size(); i++)
    {
        tuple<string, string, int, string> row;
        row = make_tuple(list->at(i)->getKode(), list->at(i)->getName(), list->at(i)->getSKS(), Departemen::getDepartemenById(recDepartemen, list->at(i)->getDepartemenId())->getName());
        tuples.push_back(row);
    }
    return tuples;
}

vector<string> Matkul::tuplesHeader(){ return {"Kode", "Mata Kuliah", "SKS", "Departemen"}; }
// ==================================================================