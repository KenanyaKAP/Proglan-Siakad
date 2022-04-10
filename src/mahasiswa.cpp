#include <iostream>
#include <vector>
#include <tuple>
#include <math.h>

#include "include/mahasiswa.hpp"
#include "include/user.hpp"

using namespace std;

// ========================== Constructor ===========================
Mahasiswa::Mahasiswa(string id, string nama, int dd, int mm, int yy, string nrp, string departemenId, string doswalId, string frsId, int tahunMasuk)
:Person(id, nama, dd, mm, yy), nrp(nrp), departemenId(departemenId), doswalId(doswalId), frsId(frsId), tahunMasuk(tahunMasuk)
{
	this->ipk = 0.0;
	this->semester = 1;
	this->sksLulus = 0;
    for (int i = 0; i < 14; i++)
	    this->ips.push_back(0.0f);
}
// ==================================================================



// ======================== Private Function ========================
// ==================================================================



// ======================== Public Function =========================
string Mahasiswa::getNRP(){ return this->nrp; }

string Mahasiswa::getDepartemenId(){ return this->departemenId; }

string Mahasiswa::getDoswalId(){ return this->doswalId; }

string Mahasiswa::getFRSId(){ return this->frsId; }

int Mahasiswa::getTahunMasuk(){ return this->tahunMasuk; }

int Mahasiswa::getSemester(){ return this->semester; }

int Mahasiswa::getSKSLulus(){ return this->sksLulus; }

float Mahasiswa::getIPK(){ return this->ipk; }

float Mahasiswa::getIPS(int semester){ return fmax(0.0f, this->ips.at(semester)); }

vector<float> *Mahasiswa::getAllIPS(){ return &this->ips; }

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

	this->ipk = 0;
	for (int i = 0; i < this->semester; i++)
        this->ipk += this->ips[i];
    this->ipk /= max(1, (this->semester - 1));
}

void Mahasiswa::setDoswalId(string id)
{
    this->doswalId = id;
}

vector<tuple<int, float>> Mahasiswa::makeTuplesIPS()
{
    vector<tuple<int, float>> tuples;
    for (int i = 0; i < 14; i++)
    {
        tuple<int, float> row;
        row = make_tuple(i + 1, this->ips.at(i));
        tuples.push_back(row);
    }
    return tuples;
}
// ==================================================================



// ===================== Public Static Function =====================
int Mahasiswa::getPositionById(vector<Mahasiswa> *list, string id)
{
    for (unsigned int i = 0; i < list->size(); i++)
        if (list->at(i).getId() == id)
            return i;
    cout << "Cannot find position of: " << id << endl;
    exit(0);
}

Mahasiswa *Mahasiswa::getMahasiswaById(vector<Mahasiswa> *list, string id)
{
    for (unsigned int i = 0; i < list->size(); i++)
        if (list->at(i).getId() == id)
            return &list->at(i);
    cout << "Cannot find Mahasiswa with id: " << id << endl;
    exit(0);
}

vector<Mahasiswa*> Mahasiswa::getMahasiswasByDeptId(vector<Mahasiswa> *list, string id)
{
    vector<Mahasiswa*> output;
    for (Mahasiswa &mahasiswa : *list)
        if (mahasiswa.getDepartemenId() == id)
            output.push_back(&mahasiswa);
    return output;
}

vector<Mahasiswa*> Mahasiswa::getMahasiswasById(vector<Mahasiswa> *list, vector<string> *ids)
{
    vector<Mahasiswa*> output;
    for (string &id : *ids)
    {
        for (Mahasiswa &mhs : *list)
        {
            if (mhs.getId() == id)
            {
                output.push_back(&mhs);
                break;
            }
        }
    }
    return output;
}

vector<Mahasiswa*> Mahasiswa::makeVectorPointer(vector<Mahasiswa> *list)
{
    vector<Mahasiswa*> output;
    for (Mahasiswa &mhs : *list)
        output.push_back(&mhs);
    return output;
}

vector<tuple<string, string>> Mahasiswa::makeTuples(vector<Mahasiswa*> *list)
{
    vector<tuple<string, string>> tuples;
    for (unsigned int i = 0; i < list->size(); i++)
    {
        tuple<string, string> row;
        row = make_tuple(list->at(i)->getName(), list->at(i)->getNRP());
        tuples.push_back(row);
    }
    return tuples;
}

vector<string> Mahasiswa::tuplesHeader(){ return {"Nama", "NRP"}; }

vector<string> Mahasiswa::tuplesIPSHeader(){ return {"Semester", "   IPS   "}; }
// ==================================================================