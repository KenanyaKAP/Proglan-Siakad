#include <iostream>
#include <string>
#include <sstream>

#include "include/person.hpp"

using namespace std;

// ========================== Constructor ===========================
Person::Person(string id, string name, int dd, int mm, int yy)
	:id(id), name(name), dd(dd), mm(mm), yy(yy){}
// ==================================================================



// ======================== Private Function ========================
// ==================================================================



// ======================== Public Function =========================
string Person::getId(){ return this->id; }

string Person::getName(){ return this->name; }

int Person::getTglLahir(){ return this->dd; }

int Person::getBulanLahir(){ return this->mm; }

int Person::getTahunLahir(){ return this->yy; }

void Person::setName(string name){ this->name = name; }

void Person::setTglLahir(int dd, int mm, int yy)
{ 
	this->dd = dd;
	this->mm = mm;
	this->yy = yy;
}
// ==================================================================



// ===================== Public Static Function =====================
string Person::personIdAddOne(string personId, const char *prefix)
{
	personId.erase(personId.begin(), personId.begin() + 2);
	stringstream ss;
	ss << prefix << stoi(personId) + 1;
	return ss.str();
}
// ==================================================================