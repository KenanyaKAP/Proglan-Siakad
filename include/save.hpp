#ifndef __SAVE_HPP__
#define __SAVE_HPP__

#include <iostream>
#include <vector>

class Save
{
private:
    Save(){}
    
public:
    template <class T>
    static void saveData(std::vector<T> data);
};

#include "tpp/save.tpp"

#endif