#ifndef __TENDIK_HPP__
#define __TENDIK_HPP__

#include <iostream>

#include "include/person.hpp"

class User;

class Tendik : public Person {
private:
	std::string npp;
	int tahunMasuk;
	std::string unit;

public:
	Tendik(std::string id, std::string name, int dd, int mm, int yy, std::string npp, int tahunMasuk, std::string unit);

	std::string getNPP();
	int getTahunMasuk();
	std::string getUnit();
	User *getUser(std::vector<User> *list);

	void setNPP(std::string npp);
	void setTahunMasuk(int tahunMasuk);
	void setUnit(std::string unit);

	static int getPositionById(std::vector<Tendik> *list, std::string id);
	static Tendik *getTendikById(std::vector<Tendik> *list, std::string id);
};

#endif