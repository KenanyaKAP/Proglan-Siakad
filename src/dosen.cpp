#include <iostream>
#include <sstream>
#include <vector>
#include <tuple>

#include "include/dosen.hpp"
#include "include/departemen.hpp"

using namespace std;

// ========================== Constructor ===========================
Dosen::Dosen(string id, string nama, int dd, int mm, int yy, string departemenId, int pendidikan)
:Person(id, nama, dd, mm, yy), departemenId(departemenId), pendidikan(pendidikan)
{
    // stringstream ss;
    // ss << yy << mm << dd << 
}
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