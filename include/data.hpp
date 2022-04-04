#ifndef __DATA_HPP__
#define __DATA_HPP__

#include <iostream>

struct Data {
private:
    std::string lastPersonId;
    std::string lastDepartemenId;
    std::string lastMatkulId;

public:
    Data();

    std::string getLastPersonId();
    std::string getLastDepartemenId();
    std::string getLastMatkulId();
    
    void setLastPersonId(std::string last);
    void setLastDepartemenId(std::string last);
    void setLastMatkulId(std::string last);

    std::string lastPersonIdAddOne();
    std::string lastDepartemenIdAddOne();
    std::string lastMatkulIdAddOne();
};

#endif