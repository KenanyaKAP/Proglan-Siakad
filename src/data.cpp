#include <iostream>

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

void Data::setLastPersonId(string last){ this->lastPersonId = last; }

void Data::setLastDepartemenId(string last){ this->lastDepartemenId = last; }

void Data::setLastMatkulId(string last){ this->lastMatkulId = last; }

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
// ==================================================================



// ===================== Public Static Function =====================
// ==================================================================