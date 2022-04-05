#include <iostream>
#include <vector>
#include <tuple>

#include "include/data.hpp"
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

void Dosen::setNPP(std::string npp){ this->npp = npp; }

void Dosen::setTahunMasuk(int tahunMasuk){ this->tahunMasuk = tahunMasuk; }

void Dosen::setDepartemenId(std::string departemenId){ this->departemenId = departemenId; }

void Dosen::setPendidikan(int pendidikan){ this->pendidikan = pendidikan; }

void Dosen::addKelasAjarId(std::string kelasId){ this->kelasAjarIds.push_back(kelasId); }
// ==================================================================



// ===================== Public Static Function =====================

// ==================================================================