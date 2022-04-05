#ifndef __DATA_HPP__
#define __DATA_HPP__

#include <iostream>
#include <vector>
#include <tuple>

struct Data {
private:
    std::string lastPersonId;
    std::string lastDepartemenId;
    std::string lastMatkulId;
    std::vector<std::tuple<std::string, int>> dosenTahunMasuk;

public:
    Data();

    std::string getLastPersonId();
    std::string getLastDepartemenId();
    std::string getLastMatkulId();
    std::vector<std::tuple<std::string, int>> *getTahunMasuk();
    
    void setLastPersonId(std::string last);
    void setLastDepartemenId(std::string last);
    void setLastMatkulId(std::string last);
    void setTahunMasuk(std::vector<std::tuple<std::string, int>> *data);

    std::string lastPersonIdAddOne();
    std::string lastDepartemenIdAddOne();
    std::string lastMatkulIdAddOne();

    int tahunCount(std::string tahun);
};

#endif