#ifndef __MAHASISWA_HPP__
#define __MAHASISWA_HPP__

#include <iostream>

#include "include/person.hpp"

class Mahasiswa : public Person {
private:
	std::string nrp;
	std::string departemenId;
	int tahunMasuk;
	int semester;
	int sksLulus;
	float ipk;
	std::vector<float> ips;

public:
	Mahasiswa(std::string id, std::string nama, int dd, int mm, int yy, std::string nrp, std::string departemenId, int tahunMasuk);

	std::string getNRP();
	std::string getDepartemenId();
	int getTahunMasuk();
	int getSemester();
	int getSKSLulus();
	float getIPK();
	float getIPS(int semester);
	std::vector<float> *getAllIPS();

	void setSemester(int semester);
	void setSKSLulus(int sksLulus);
	void setIPS(int semester, float ips);
};

#endif
