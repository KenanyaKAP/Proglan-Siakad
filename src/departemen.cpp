#include <iostream>

#include "include/departemen.hpp"

using namespace std;

// ========================== Constructor ===========================
Departemen::Departemen(string name, string kode)
:name(name), kode(kode){}
// ==================================================================



// ======================== Private Function ========================
// ==================================================================



// ======================== Public Function =========================
string Departemen::getName(){ return this->name; }

string Departemen::getKode(){ return this->kode; }

void Departemen::addMatkul(std::string id){ this->matkulIds.push_back(id); }

void Departemen::addMahasiswa(std::string id){ this->mahasiswaIds.push_back(id); }
// ==================================================================