#include <iostream>
#include <vector>
#include <tuple>

#include "include/data.hpp"
#include "include/person.hpp"
#include "include/departemen.hpp"
#include "include/matkul.hpp"

using namespace std;


// ========================== Constructor ===========================
Data::Data()
{
    this->lastPersonId = "p_-1";
    this->lastDepartemenId = "d_-1";
    this->lastMatkulId = "m_-1";
}
// ==================================================================



// ======================== Private Function ========================
// ==================================================================



// ======================== Public Function =========================
string Data::getLastPersonId(){ return this->lastPersonId; }

string Data::getLastDepartemenId(){ return this->lastDepartemenId; }

string Data::getLastMatkulId(){ return this->lastMatkulId; }

vector<tuple<string, int>> *Data::getTahunMasuk(){ return &this->dosenTahunMasuk; }

void Data::setLastPersonId(string last){ this->lastPersonId = last; }

void Data::setLastDepartemenId(string last){ this->lastDepartemenId = last; }

void Data::setLastMatkulId(string last){ this->lastMatkulId = last; }

void Data::setTahunMasuk(vector<tuple<string, int>> *data){ this->dosenTahunMasuk = *data; }

string Data::lastPersonIdAddOne()
{
    this->lastPersonId = Person::personIdAddOne(this->lastPersonId);
    return this->lastPersonId;
}

string Data::lastDepartemenIdAddOne()
{
    this->lastDepartemenId = Departemen::departemenIdAddOne(this->lastDepartemenId);
    return this->lastDepartemenId;
}

string Data::lastMatkulIdAddOne()
{
    this->lastMatkulId = Matkul::matkulIdAddOne(this->lastMatkulId);
    return this->lastMatkulId;
}

int Data::tahunCount(string tahun)
{
    for (tuple<string, int> &tahunMasuk : dosenTahunMasuk)
    {
        // cout << get<0>(tahunMasuk) << "|";
        if (get<0>(tahunMasuk) == tahun)
        {
            get<1>(tahunMasuk) += 1;
            return get<1>(tahunMasuk);
        }
        // cout << endl;
    }
    tuple<string, int> temp = make_tuple(tahun, 1);
    dosenTahunMasuk.push_back(temp);
    return 1;
}
// ==================================================================



// ===================== Public Static Function =====================
// ==================================================================