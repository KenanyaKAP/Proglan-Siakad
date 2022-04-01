#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include <iostream>
#include <cstdlib>
#include <vector>
#include <tuple>

#include "include/VariadicTable.hpp"

namespace Utils {
    void clearScreen();
    std::string encrypt(std::string input);
    std::string decrypt(std::string input);
    template <class... T>
    void printTable(std::vector<std::tuple<T...>> data, std::vector<std::string> header, unsigned int page);
}

template <class... T>
void Utils::printTable(std::vector<std::tuple<T...>> data, std::vector<std::string> header, unsigned int page)
{
    header.insert(header.begin(), "No");
    VariadicTable<int, T...> vt(header);
    for (unsigned int i = 10*(page-1); i < 10*page; i++)
    {
        if (i < data.size())
        {
            vt.addRow(std::tuple_cat(std::make_tuple(i+1), data[i]));
        }
    }
    
    vt.print(std::cout);
}

#endif