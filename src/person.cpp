#include <iostream>
#include <cstring>

#include "include/person.hpp"

using namespace std;

Person::Person(char *id, char *name, int dd, int mm, int yy)
{
	strcpy(this->id, id);
	this->id[sizeof(this->id) - 1] = '\0';
	strcpy(this->name, name);
	this->name[sizeof(this->name) - 1] = '\0';
	this->dd = dd;
	this->mm = mm;
	this->yy = yy;
}

char *Person::getId(){ return this->id; }

char *Person::getName(){ return this->name; }

int Person::getTglLahir(){ return this->dd; }

int Person::getBulanLahir(){ return this->mm; }

int Person::getTahunLahir(){ return this->yy; }

void Person::setId(char *id)
{ 
	id[sizeof(this->id) - 1] = '\0';
	strcpy(this->id, id);
}

void Person::setName(char *name)
{ 
	name[sizeof(this->name) - 1] = '\0';
	strcpy(this->name, name);
}

void Person::setTglLahir(int dd, int mm, int yy)
{ 
	this->dd = dd;
	this->mm = mm;
	this->yy = yy;
}