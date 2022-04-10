#ifndef __MAHASISWA_HPP__
#define __MAHASISWA_HPP__

#include <iostream>
#include <vector>
#include <tuple>

#include "include/person.hpp"

class User;

class Mahasiswa : public Person {
private:
	std::string nrp;
	std::string departemenId;
	std::string doswalId;
	std::string frsId;
	int tahunMasuk;
	int semester;
	int sksLulus;
	float ipk;
	std::vector<float> ips;

public:
	Mahasiswa(std::string id, std::string nama, int dd, int mm, int yy, std::string nrp, std::string departemenId, std::string doswalId, std::string frsId, int tahunMasuk);

	std::string getNRP();
	std::string getDepartemenId();
	std::string getDoswalId();
	std::string getFRSId();
	int getTahunMasuk();
	int getSemester();
	int getSKSLulus();
	float getIPK();
	float getIPS(int semester);
	std::vector<float> *getAllIPS();
	User *getUser(std::vector<User> *list);

	void setSemester(int semester);
	void setSKSLulus(int sksLulus);
	void setIPS(int semester, float ips);
	void setDoswalId(std::string id);

	std::vector<std::tuple<int, float>> makeTuplesIPS();

	static int getPositionById(std::vector<Mahasiswa> *list, std::string id);
	static Mahasiswa *getMahasiswaById(std::vector<Mahasiswa> *list, std::string id);
	static std::vector<Mahasiswa*> getMahasiswasByDeptId(std::vector<Mahasiswa> *list, std::string id);
	static std::vector<Mahasiswa*> getMahasiswasById(std::vector<Mahasiswa> *list, std::vector<std::string> *ids);
	static std::vector<Mahasiswa*> makeVectorPointer(std::vector<Mahasiswa> *list);

	static std::vector<std::tuple<std::string, std::string>> makeTuples(std::vector<Mahasiswa*> *list);
	static std::vector<std::string> tuplesHeader();
	static std::vector<std::string> tuplesIPSHeader();
};

#endif
