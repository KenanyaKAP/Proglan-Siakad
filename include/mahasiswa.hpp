#ifndef __MAHASISWA_HPP__
#define __MAHASISWA_HPP__

#include <iostream>

#include "include/person.hpp"

class User;

class Mahasiswa : public Person {
private:
	std::string nrp;
	std::string departemenId;
	std::string doswalId;
	int tahunMasuk;
	int semester;
	int sksLulus;
	float ipk;
	std::vector<float> ips;

public:
	Mahasiswa(std::string id, std::string nama, int dd, int mm, int yy, std::string nrp, std::string departemenId, std::string doswalId, int tahunMasuk);

	std::string getNRP();
	std::string getDepartemenId();
	std::string getDoswalId();
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

	static int getPositionById(std::vector<Mahasiswa> *list, std::string id);
	static Mahasiswa *getMahasiswaById(std::vector<Mahasiswa> *list, std::string id);
	static std::vector<Mahasiswa*> getMahasiswasByDeptId(std::vector<Mahasiswa> *list, std::string id);
};

#endif
