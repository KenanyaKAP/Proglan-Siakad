#ifndef __DOSEN_HPP__
#define __DOSEN_HPP__

#include <iostream>
#include <vector>
#include <tuple>

#include "include/person.hpp"

class User;

class Dosen : public Person {
private:
	std::string npp;
	int tahunMasuk;
	std::string departemenId;
	int pendidikan;
	std::vector<std::string> kelasAjarIds;

public:
	Dosen(std::string id, std::string name, int dd, int mm, int yy, std::string npp, int tahunMasuk, std::string departemenId, int pendidikan);

	std::string getNPP();
	int getTahunMasuk();
	std::string getDepartemenId();
	int getPendidikan();
	std::vector<std::string> *getAllKelasAjarId();
	User *getUser(std::vector<User> *list);

	void setNPP(std::string npp);
	void setTahunMasuk(int tahunMasuk);
	void setDepartemenId(std::string departemenId);
	void setPendidikan(int pendidikan);
	void addKelasAjarId(std::string kelasId);

	static int getPosition(std::vector<Dosen> *list, Dosen *target);
	static Dosen *getDosenById(std::vector<Dosen> *list, std::string personId);
	static std::vector<std::tuple<std::string, std::string>> makeTuples(std::vector<Dosen> *dosens);
    static std::vector<std::string> tuplesHeader();
	static std::vector<Dosen> getAllDosenByDepartemenId(std::vector<Dosen> *list, std::string id);
};

#endif 
