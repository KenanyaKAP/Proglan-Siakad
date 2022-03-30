#include <iostream>
#include <cstring>

#include "include/departemen.hpp"

using namespace std;

// ========================== Constructor ===========================
Departemen::Departemen(){}

Departemen::Departemen(string id, string name)
    :id(id), name(name){}
// ==================================================================



// ======================== Private Function ========================
// ==================================================================



// ======================== Public Function =========================
string Departemen::getId(){ return this->id; }

string Departemen::getName(){ return this->name; }

void Departemen::addDosen(string id)
{
    dosenIds.push_back(id);
}
// ==================================================================



// ====================== Class for Save User =======================
// ==================================================================

