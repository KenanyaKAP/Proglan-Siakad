#include <iostream>
#include <cstring>

#include "include/departemen.hpp"

using namespace std;

Departemen::Departemen(char *id, char *name)
{
    strcpy(this->id, id);
	this->id[sizeof(this->id) - 1] = '\0';
    strcpy(this->name, name);
	this->name[sizeof(this->name) - 1] = '\0';
}

char *Departemen::getId(){ return this->id; }

char *Departemen::getName(){ return this->name; }

void Departemen::addDosen(char *id)
{
    dosenIds.push_back(id);
}