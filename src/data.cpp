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
    semester = 1;
    this->lastAdminId = "a_-1";
    this->lastPersonId = "p_-1";
    this->lastDepartemenId = "d_-1";
    this->lastMatkulId = "m_-1";
}
// ==================================================================



// ======================== Private Function ========================
// ==================================================================



// ======================== Public Function =========================
int Data::getSemester(){ return this->semester; }

string Data::getLastAdminId(){ return this->lastAdminId; }

string Data::getLastPersonId(){ return this->lastPersonId; }

string Data::getLastDepartemenId(){ return this->lastDepartemenId; }

string Data::getLastMatkulId(){ return this->lastMatkulId; }

vector<tuple<string, int>> *Data::getDosenId(){ return &this->dosenId; }

vector<tuple<string, int>> *Data::getMahasiswaId(){ return &this->mahasiswaId; }

void Data::setSemester(int semester){ this->semester = semester; }

void Data::setLastAdminId(string last){ this->lastAdminId = last; }

void Data::setLastPersonId(string last){ this->lastPersonId = last; }

void Data::setLastDepartemenId(string last){ this->lastDepartemenId = last; }

void Data::setLastMatkulId(string last){ this->lastMatkulId = last; }

void Data::setDosenId(vector<tuple<string, int>> *data){ this->dosenId = *data; }

void Data::setMahasiswaId(vector<tuple<string, int>> *data){ this->mahasiswaId = *data; }

string Data::lastAdminIdAddOne()
{
    this->lastAdminId = Person::personIdAddOne(this->lastAdminId, "a_");
    return this->lastAdminId;
}

string Data::lastPersonIdAddOne()
{
    this->lastPersonId = Person::personIdAddOne(this->lastPersonId, "p_");
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

int Data::dosenIdCount(string tahun)
{
    for (tuple<string, int> &tahunMasuk : dosenId)
    {
        if (get<0>(tahunMasuk) == tahun)
        {
            get<1>(tahunMasuk) += 1;
            return get<1>(tahunMasuk);
        }
    }
    tuple<string, int> temp = make_tuple(tahun, 1);
    dosenId.push_back(temp);
    return 1;
}

int Data::mahasiswaIdCount(string departemenId)
{
    for (tuple<string, int> &deptId : mahasiswaId)
    {
        if (get<0>(deptId) == departemenId)
        {
            get<1>(deptId) += 1;
            return get<1>(deptId);
        }
    }
    tuple<string, int> temp = make_tuple(departemenId, 1);
    mahasiswaId.push_back(temp);
    return 1;
}
// ==================================================================



// ===================== Public Static Function =====================
// ==================================================================