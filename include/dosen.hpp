#ifndef __DOSEN_HPP__
#define __DOSEN_HPP__

#include <iostream>
#include <vector>
#include <tuple>

#include "include/person.hpp"

class Departemen;

class Dosen : public Person {
private:
	std::string npp;
	std::string departemenId;
	int pendidikan;
	std::vector<std::string> kelasAjarIds;

public:
	Dosen(std::string id, std::string name, int dd, int mm, int yy, std::string departemenId, int pendidikan);

	std::string getNPP();
	std::string getDepartemenId();
	int getPendidikan();
	std::vector<std::string> getAllKelasAjarId();

	void setPendidikan(int pendidikan);

	static std::vector<std::tuple<std::string, std::string, std::string>> makeTuples(std::vector<Dosen> *dosens, std::vector<Departemen> *departemens);
    static std::vector<std::string> tuplesHeader();
};

#endif 
