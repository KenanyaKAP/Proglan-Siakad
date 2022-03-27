#include <iostream>

#include "include/person.hpp"

Person::Person(std::string id, std::string name, int dd, int mm, int yy)
	:id(id), name(name), dd(dd), mm(mm), yy(yy)
{

}

void Person::setId(std::string id){ this->id = id; }
std::string Person::getId(){ return this->id; }
void Person::setName(std::string name){ this->name = name; }
std::string Person::getName(){ return this->name; }
void Person::setTglLahir(int dd, int mm, int yy){ this->dd = dd; this->mm = mm; this->yy = yy; }
int Person::getTglLahir(){ return this->dd; }
int Person::getBulanLahir(){ return this->mm; }
int Person::getTahunLahir(){ return this->yy; }