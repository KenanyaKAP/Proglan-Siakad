#include <iostream>
#include <vector>

#include "include/tendik.hpp"
#include "include/user.hpp"

using namespace std;

// ========================== Constructor ===========================
Tendik::Tendik(std::string id, std::string name, int dd, int mm, int yy, std::string npp, int tahunMasuk, std::string unit)
:Person(id, name, dd, mm, yy), npp(npp), tahunMasuk(tahunMasuk), unit(unit){}
// ==================================================================



// ======================== Private Function ========================
// ==================================================================



// ======================== Public Function =========================
std::string Tendik::getNPP(){ return this->npp; }

int Tendik::getTahunMasuk(){ return this->tahunMasuk; }

std::string Tendik::getUnit(){ return this->unit; }

void Tendik::setNPP(std::string npp){ this->npp = npp; }

void Tendik::setTahunMasuk(int tahunMasuk){ this->tahunMasuk = tahunMasuk; }

void Tendik::setUnit(std::string unit){ this->unit = unit; }

User *Tendik::getUser(vector<User> *list)
{
    for (User &user : *list)
        if(user.getPersonId() == this->getId())
            return &user;
    return nullptr;
}
// ==================================================================



// ===================== Public Static Function =====================
int Tendik::getPositionById(vector<Tendik> *list, string id)
{
    for (unsigned int i = 0; i < list->size(); i++)
        if (list->at(i).getId() == id)
            return i;
    cout << "Cannot find position of: " << id << endl;
    exit(0);
}

Tendik *Tendik::getTendikById(vector<Tendik> *list, string id)
{
    for (unsigned int i = 0; i < list->size(); i++)
        if (list->at(i).getId() == id)
            return &list->at(i);
    cout << "Cannot find Tendik with id: " << id << endl;
    exit(0);
}
// ==================================================================