#ifndef __DEPARTEMEN_HPP__
#define __DEPARTEMEN_HPP__

#include <iostream>
#include <vector>

class Departemen {
private:
    std::string id;
    std::string name;

    std::vector<std::string> dosenIds;

public:
    Departemen();
    Departemen(std::string id, std::string name);

    std::string getId();
    std::string getName();
    void addDosen(std::string id);
};

#endif