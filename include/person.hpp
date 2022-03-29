#ifndef __PERSON_HPP__
#define __PERSON_HPP__

#include <iostream>

class Person {
private:
	char id[20];
	char name[100];
	int dd, mm, yy;

public:
	Person(char *id, char *name, int dd, int mm, int yy);

	char *getId();
	char *getName();
	int getTglLahir();
	int getBulanLahir();
	int getTahunLahir();

	void setId(char *id);
	void setName(char *name);

	void setTglLahir(int dd, int mm, int yy);
};

#endif