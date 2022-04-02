#include <iostream>

#include "include/dosen.hpp"

using namespace std;

// ========================== Constructor ===========================
Dosen::Dosen(string id, string nama, int dd, int mm, int yy, string npp, string departemenId, int pendidikan)
:Person(id, nama, dd, mm, yy), npp(npp), departemenId(departemenId), pendidikan(pendidikan){}
// ==================================================================



// ======================== Private Function ========================
// ==================================================================



// ======================== Public Function =========================
string Dosen::getNPP(){ return this->npp; }

string Dosen::getDepartemenId(){ return this->departemenId; }

int Dosen::getPendidikan(){ return this->pendidikan; }

vector<string> Dosen::getAllKelasAjarId(){ return this->kelasAjarIds; }

void Dosen::setPendidikan(int pendidikan){ this->pendidikan = pendidikan; }
// ==================================================================



// ===================== Public Static Function =====================
// ==================================================================