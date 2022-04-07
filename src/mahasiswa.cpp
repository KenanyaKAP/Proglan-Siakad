#include <iostream>
#include <vector>

#include "include/mahasiswa.hpp"
#include "include/user.hpp"

using namespace std;

// ========================== Constructor ===========================
Mahasiswa::Mahasiswa(string id, string nama, int dd, int mm, int yy, string nrp, string departemenId, string doswalId, int tahunMasuk)
:Person(id, nama, dd, mm, yy), nrp(nrp), departemenId(departemenId), doswalId(doswalId), tahunMasuk(tahunMasuk)
{
	this->ipk = 0.0;
	this->semester = 1;
	this->sksLulus = 0;
	this->ips = vector<float>(14, 0);
}
// ==================================================================



// ======================== Private Function ========================
// ==================================================================



// ======================== Public Function =========================
std::string Mahasiswa::getNRP(){ return this->nrp; }

std::string Mahasiswa::getDepartemenId(){ return this->departemenId; }

std::string Mahasiswa::getDoswalId(){ return this->doswalId; }

int Mahasiswa::getTahunMasuk(){ return this->tahunMasuk; }

int Mahasiswa::getSemester(){ return this->semester; }

int Mahasiswa::getSKSLulus(){ return this->sksLulus; }

float Mahasiswa::getIPK(){ return this->ipk; }

float Mahasiswa::getIPS(int semester){ return this->ips.at(semester); }

std::vector<float> *Mahasiswa::getAllIPS(){ return &this->ips; }

User *Mahasiswa::getUser(vector<User> *list)
{
    for (User &user : *list)
        if(user.getPersonId() == this->getId())
            return &user;
    return nullptr;
}

void Mahasiswa::setSemester(int semester){ this->semester = semester; }

void Mahasiswa::setSKSLulus(int sksLulus){ this->sksLulus = sksLulus; }

void Mahasiswa::setIPS(int semester, float ips)
{ 
	this->ips[semester - 1] = ips;

	float temp = 0;
	for (float i : this->ips)
		temp += i;
	this->ipk = temp / this->ips.size();
}
// ==================================================================



// ===================== Public Static Function =====================
int Mahasiswa::getPosition(vector<Mahasiswa> *list, Mahasiswa *target)
{
    for (unsigned int i = 0; i < list->size(); i++)
        if (list->at(i).getId() == target->getId())
            return i;
    cout << "Cannot find position of " << target->getName() << endl;
    exit(0);
}

Mahasiswa *Mahasiswa::getMahasiswaById(vector<Mahasiswa> *list, string personId)
{
    for (unsigned int i = 0; i < list->size(); i++)
        if (list->at(i).getId() == personId)
            return &list->at(i);
    cout << "NULLLLLLLARRRRRRRR";
    return nullptr;
}

vector<Mahasiswa> Mahasiswa::getAllMahasiswaByDepartemenId(vector<Mahasiswa> *list, string id)
{
    vector<Mahasiswa> output;
    for (Mahasiswa &mahasiswa : *list)
        if (mahasiswa.getDepartemenId() == id)
            output.push_back(mahasiswa);
    return output;
}
// ==================================================================