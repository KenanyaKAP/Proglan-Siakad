#include <iostream>
#include <vector>
#include <tuple>

#include "include/data.hpp"
#include "include/user.hpp"
#include "include/dosen.hpp"
#include "include/departemen.hpp"

using namespace std;

// ========================== Constructor ===========================
Dosen::Dosen(string id, string nama, int dd, int mm, int yy, string npp, int tahunMasuk, string departemenId, int pendidikan)
:Person(id, nama, dd, mm, yy), npp(npp), tahunMasuk(tahunMasuk), departemenId(departemenId), pendidikan(pendidikan){}
// ==================================================================



// ======================== Private Function ========================
// ==================================================================



// ======================== Public Function =========================
string Dosen::getNPP(){ return this->npp; }

int Dosen::getTahunMasuk(){ return this->tahunMasuk; }

string Dosen::getDepartemenId(){ return this->departemenId; }

int Dosen::getPendidikan(){ return this->pendidikan; }

vector<string> *Dosen::getAllKelasAjarId(){ return &this->kelasAjarIds; }

User *Dosen::getUser(vector<User> *list)
{
    for (User &user : *list)
        if(user.getPersonId() == this->getId())
            return &user;
    return nullptr;
}

void Dosen::setNPP(string npp){ this->npp = npp; }

void Dosen::setTahunMasuk(int tahunMasuk){ this->tahunMasuk = tahunMasuk; }

void Dosen::setDepartemenId(string departemenId){ this->departemenId = departemenId; }

void Dosen::setPendidikan(int pendidikan){ this->pendidikan = pendidikan; }

void Dosen::addKelasAjarId(string kelasId){ this->kelasAjarIds.push_back(kelasId); }
// ==================================================================



// ===================== Public Static Function =====================
int Dosen::getPosition(vector<Dosen> *list, Dosen *target)
{
    for (unsigned int i = 0; i < list->size(); i++)
        if (&list->at(i) == target)
            return i;
    cout << "Cannot find position of " << target->getName() << endl;
    exit(0);
}

Dosen *Dosen::getDosenById(vector<Dosen> *list, string personId)
{
    for (unsigned int i = 0; i < list->size(); i++)
        if (list->at(i).getId() == personId)
            return &list->at(i);
    cout << "NULLLLLLL";
    return nullptr;
}

vector<tuple<string, string>> Dosen::makeTuples(vector<Dosen> *dosens)
{
    vector<tuple<string, string>> tuples;
    for (unsigned int i = 0; i < dosens->size(); i++)
    {
        tuple<string, string> user;
        user = make_tuple(dosens->at(i).getName(), dosens->at(i).getNPP());
        tuples.push_back(user);
    }
    return tuples;
}

vector<string> Dosen::tuplesHeader(){ return {"Nama", "NPP"}; }

vector<Dosen> Dosen::getAllDosenByDepartemenId(vector<Dosen> *list, string id)
{
    vector<Dosen> output;
    for (Dosen &dosen : *list)
        if (dosen.getDepartemenId() == id)
            output.push_back(dosen);
    return output;
}
// ==================================================================