#ifndef __PERSON_HPP__
#define __PERSON_HPP__

#include <iostream>

class Person {
private:
	std::string id;
	std::string name;
	int dd, mm, yy;

public:
	Person(std::string id, std::string name, int dd, int mm, int yy);

	std::string getId();
	std::string getName();
	int getTglLahir();
	int getBulanLahir();
	int getTahunLahir();

	void setName(std::string name);
	void setTglLahir(int dd, int mm, int yy);

	static std::string personIdAddOne(std::string personId, const char *prefix);
};

#endif