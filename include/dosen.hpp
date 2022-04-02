#ifndef __DOSEN_HPP__
#define __DOSEN_HPP__

#include <iostream>
#include <vector>

#include "include/person.hpp"

class Dosen : public Person {
private:
	std::string npp;
	std::string departemenId;
	int pendidikan;
	std::vector<std::string> kelasAjarIds;

public:
	Dosen(std::string id, std::string name, int dd, int mm, int yy, std::string npp, std::string departemenId, int pendidikan);

	std::string getNPP();
	std::string getDepartemenId();
	int getPendidikan();
	std::vector<std::string> getAllKelasAjarId();

	void setPendidikan(int pendidikan);
};

#endif 
