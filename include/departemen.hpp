#ifndef __DEPARTEMEN_HPP__
#define __DEPARTEMEN_HPP__

#include <iostream>
#include <vector>

class Departemen {
private:
    char id[20];
    char name[100];

    std::vector<char[20]> dosenIds;

public:
    Departemen(char *id, char *name);

    char *getId();
    char *getName();

    void addDosen(char *id);
};

#endif